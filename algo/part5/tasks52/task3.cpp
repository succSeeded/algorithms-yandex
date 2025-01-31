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

template<typename T> T gcdMaxDepth(const T& n)
{
    
}

int main()
{
    uint32_t a, b;
    std::cin >> a >> b;
    std::cout << GCD(a, b) << std::endl;
    return 0;
}
