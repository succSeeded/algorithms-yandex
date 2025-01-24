#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

template<typename T> void vector_print(const std::vector<T>& v) {
    std::cout << "{"
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
        size_t m = std::rand() % (last - first);
        std::iter_swap(v.begin() + first, v.begin() + first + m);

        size_t piv = lomuto_partition(v, first, last);
        quicksort_inplace(v, first, piv-1);
        quicksort_inplace(v, piv+1, last);
    }
}

template<typename T> void quicksort_inplace(std::vector<T>& v)
{
    quicksort_inplace(v, 0, v.size()-1);
}

int main()
{
    int n, input;
    std::vector<int> sorted, input_v;

    std::cin >> n;

    for (size_t j = 0; j < n; j++)
    {
        std::cin >> input;
        sorted.push_back(input);
    }

    quicksort_inplace(sorted);
    vector_print(sorted);
}
