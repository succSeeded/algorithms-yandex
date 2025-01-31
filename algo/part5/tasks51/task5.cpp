#include <cstdint>
#include <iostream>
#include <vector>

template<typename T> std::vector<T> PisanoPeriod(const T& m)
{
    T curr(0), next(1);
    std::vector<T> ans{0, 1};
    while (true)
    {
        std::swap(curr, next);
        next = (curr + next) % m;
        ans.push_back(next);
        if ((curr == 0) && (next == 1))
        {
            break;
        }
    }
    ans.pop_back();
    ans.pop_back();
    return ans;
}

template<typename T> T FibDiv(const T& n, const T& m)
{
    if (n <= 1)
    {
        return n;
    }

    std::vector<T> period(PisanoPeriod(m));
    return period[n % period.size()];
}

template<typename T> T FibPartialSumLast(const T& m, const T& n)
{
    T Sm(FibDiv(m+1, static_cast<T>(10))), Sn(FibDiv(n+2, static_cast<T>(10)));
    if (Sn < Sm)
    {
        return 10 - (Sm - Sn);
    }
    else
    {
        return Sn - Sm;
    }
}

int main()
{
    uint64_t n, m;
    std::cin >> m >> n;
    std::cout << FibPartialSumLast(m, n) << std::endl;
    return 0;
}
