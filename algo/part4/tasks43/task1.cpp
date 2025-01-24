#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

template<typename T> T max_product(std::vector<T>& arr)
{
    auto max(arr.begin()), max_prev(arr.begin());
    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        if ((*max) < (*i))
        {
            max = i;
        }
    }
    std::iter_swap(max, arr.end()-1);
    for (auto i = arr.begin(); i != arr.end()-1; i++) {
        if ((*max_prev) < (*i))
        {
            max_prev = i;
        }
    }
    std::iter_swap(max_prev, arr.end()-2);
    return (*(arr.end()-2)) * (*(arr.end()-1));
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
    std::cout << max_product(arr) << std::endl;
    return 0;
}
