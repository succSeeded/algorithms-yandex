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
    size_t n = arr.size();
    for(size_t i = 0; i < (n / 2); i++)
    {
        if (arr[])
    }
}

int main()
{
    int64_t n(0), input;
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
