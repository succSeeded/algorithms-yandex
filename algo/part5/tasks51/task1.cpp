#include <cstdint>
#include <iostream>

int64_t Fib(size_t n)
{
    int64_t prevprev(0), prev(1), curr(1);
    if (n <= 0)
    {
        return 0;
    }
    {
        for (size_t i = 0; i < n-1; i++)
        {
            curr = prevprev + prev;
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
    std::cout << Fib(n) << std::endl;
}
