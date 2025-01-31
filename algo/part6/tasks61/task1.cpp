#include <cstdint>
#include <cstdlib>
#include <iostream>

template<typename T> void change(const T& n)
{
    T count = (((n / 5) % 2) == 1) ? (n / 10 + 2) * ((n / 10) + 1) : (n / 10 + 2) * ((n / 10) + 1) - n / 10 - 1;
    std::cout << count << std::endl;
}

int main()
{
    uint32_t n;
    std::cin >> n;
    change(n);
    return 0;
}