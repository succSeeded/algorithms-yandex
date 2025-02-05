#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <vector>

template<typename T> T max_product(std::vector<T> arr)
{
    size_t n = arr.size();
    std::sort(arr.begin(), arr.end());
    return std::max(arr[0] * arr[1] * arr[n-2] * arr[n-1], std::max(arr[0] * arr[1] * arr[2] * arr[3] , arr[n-4] *arr[n-3] * arr[n-2] * arr[n-1]));
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
