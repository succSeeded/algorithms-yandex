#include <algorithm>
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

template<typename T> T FibSumLast(const T& n)
{
    if (n < 1)
    {
        return 0;
    }

    std::vector<T> period(PisanoPeriod(static_cast<T>(10)));
    T ans(0), periodLen(period.size());

    if (periodLen < n)
    {
        for (size_t i = 0; i < periodLen; i++)
        {
            ans += period[i];
        }
        ans = (ans * (n / periodLen)) % 10;
        for (size_t i = (n / periodLen) * periodLen; i < (n+1); i++)
        {
            ans += period[i % periodLen];
        }
    }
    else
    {
        for (size_t i = 0; i < (n+1); i++)
        {
            ans += period[i];
        }
    }
    return ans % 10;
}

int main()
{
    uint64_t n;
    std::cin >> n;
    std::cout << FibSumLast(n) << std::endl;
    return 0;
}
