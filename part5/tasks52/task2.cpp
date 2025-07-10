#include <algorithm>
#include <cstdint>
#include <iostream>

template<typename T> T GCD(const T& a, const T& b)
{
    if ((a == 0) || (b == 0))
    {
        return std::max(a, b);
    }
    return GCD(b, a % b);
}

template<typename T> T LCM(const T& a, const T& b)
{
    if ((a == 1) || (b == 1))
    {
        return std::max(a, b);
    }
    return (a * b) / GCD(a, b);
}

int main()
{
    uint64_t a, b;
    std::cin >> a >> b;
    std::cout << LCM(a, b) << std::endl;
    return 0;
}
