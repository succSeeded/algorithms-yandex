#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <vector>

template<typename T> void vector_print(const std::vector<T>& v)
{
    std::cout << "{";
    for (auto i = v.begin(); i != v.end()-1; i++)
    {
        std::cout << *i << ", ";
    }
    std::cout << v.back() << "}" << std::endl;
}

template<typename T> T max_product(std::vector<T> arr)
{
    size_t n = arr.size();
    std::sort(arr.begin(), arr.end());
    return std::max(arr[0] * arr[1] * arr[n-1], arr[n-3] * arr[n-2] * arr[n-1]);
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
        lhs = max_product(arr);
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
