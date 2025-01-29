#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

template<typename T> void vector_print(const std::vector<T>& v) {
    std::cout << "{";
    for (auto i = v.begin(); i != v.end()-1; i++)
    {
        std::cout << *i << ", ";
    }
    std::cout << v.back() << "}" << std::endl;
}

template<typename T> std::vector<T> maxima(std::vector<T> arr)
{
    size_t n, k(2);
    while (true)
    {
        n = arr.size();
        for (size_t i = 0; i < (n / k); i++)
        {
            if (arr[k*i] < arr[k*i + static_cast<size_t>(0.5*k)])
            {
                std::iter_swap(arr.begin()+k*i, arr.begin()+k*i+static_cast<size_t>(0.5*k));
            }
        }
        k *= 2;
    }
    return maxima(arr)
}

int main()
{
    size_t n(0);
    int64_t input;
    std::vector<int64_t> arr;
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> input;
        arr.push_back(input);
    }
    vector_print(maxima(arr));
    return 0;
}
