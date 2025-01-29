#include <cstdint>
#include <iostream>

uint16_t fibLastNum(size_t n)
{
    uint16_t prevprev(0), prev(1), curr(1);
    if (n <= 0)
    {
        return 0;
    }
    {
        for (size_t i = 0; i < n-1; i++)
        {
            curr = (prevprev + prev) % 10;
            prevprev = prev;
            prev = curr;
        }
        return curr;
    }
}

int main()
{
    size_t n(0);
    std::cin >> n;
    std::cout << fibLastNum(n) << std::endl;
}
