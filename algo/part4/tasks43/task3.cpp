#include <iostream>
#include <cstdlib>
#include <ctime>
#include <format>
#include <vector>
#include <string>

template<typename T> void vector_print(const std::vector<T>& v) {
    std::cout << "{";
    for (auto i = v.begin(); i != v.end()-1; i++)
    {
        std::cout << *i << ", ";
    }
    std::cout << v.back() << "}" << std::endl;
}

template<typename T> size_t lomuto_partition(std::vector<T>& v, const size_t& first, const size_t& last)
{
    if (first == last)
    {
        return first;
    }

    int c_small_size = 0, m = v[first];
    for (size_t i = 1; i < (last - first + 1); i++)
    {
        if (v[first+i] < m)
        {
            std::iter_swap(v.begin() + first + c_small_size + 1, v.begin() + first + i);
            c_small_size++;
        }
    }
    if (c_small_size > 0)
    {
        std::iter_swap(v.begin() + first, v.begin() + first + c_small_size);
    }

    return first + c_small_size;
}

template<typename T> void quicksort_inplace(std::vector<T>& v, const size_t& first, const size_t& last)
{
    if (first < last)
    {
        std::srand(std::time(nullptr));
        size_t m = std::rand() % (last - first + 1);
        std::iter_swap(v.begin() + first, v.begin() + first + m);

        size_t piv = lomuto_partition(v, first, last);
        if (piv > 0)
        {
        quicksort_inplace(v, first, piv-1);
        }
        if (piv < last)
        {
        quicksort_inplace(v, piv+1, last);
        }
    }
}

template<typename T> void quicksort_inplace(std::vector<T>& v)
{
    quicksort_inplace(v, 0, v.size()-1);
}

template<typename T> T max_product(std::vector<T> arr, const size_t& count)
{
    if (arr.size() < 3)
    {
        throw std::invalid_argument(std::format("Invalid vector size. Expecting >{}, got {} instead.", count, arr.size()));
    }

    T low_prod(1), high_prod(1);
    size_t max, n(arr.size());

    for (size_t i = 0; i < count; i++)
    {
        max = 0;
        for (size_t j = 0; j < (n - i); j++)
        {
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }
        std::iter_swap(arr.begin() + max, arr.begin() + n - 1 - i);
    }

    for (size_t i = 0; i < count; i++)
    {
        high_prod *= *(arr.end()-1-i);
    }
    for (size_t i = 0; i < count; i++)
    {
        low_prod *= *(arr.begin()+i);
    }
    return std::max(low_prod, high_prod);
}

template<typename T> T max_product_sorted(std::vector<T> arr, const size_t& count)
{
    if (arr.size() < 3)
    {
        throw std::invalid_argument(std::format("Invalid vector size. Expecting >{}, got {} instead.", count, arr.size()));
    }

    T low_prod(1), high_prod(1);
    quicksort_inplace(arr);
    for (size_t i = 0; i < count; i++)
    {
        high_prod *= *(arr.end()-1-i);
    }
    for (size_t i = 0; i < count; i++)
    {
        low_prod *= *(arr.begin()+i);
    }
    return std::max(low_prod, high_prod);
}

void stress_test()
{
    std::srand(std::time(nullptr));

    size_t n(0), m(0);
    int64_t lhs, rhs;
    std::vector<int64_t> arr;

    std::cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        arr.clear();
        m = std::rand() & (200000 - 3) + 3;
        for (size_t j = 0; j < n; j++)
        {
            arr.push_back((std::rand() % 400000) - 200000);
        }
        lhs = max_product(arr, 3);
        rhs = max_product_sorted(arr, 3);
        std::cout << lhs << " " << rhs << std::endl;
        if (lhs != rhs)
        {
            vector_print(arr);
            throw std::invalid_argument("Invalid output values.");
        }
    }
}

int main()
{
    // int64_t n(0), input;
    // std::vector<int64_t> arr;
    // std::cin >> n;
    // for (size_t i = 0; i < n; i++)
    // {
    //     std::cin >> input;
    //     arr.push_back(input);
    // }
    stress_test();
    return 0;
}
