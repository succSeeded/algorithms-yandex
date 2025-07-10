#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

std::string repeat(const std::string& string, const size_t& n)
{
    if (n <= 0)
    {
        return "";
    }
    std::string ans(string);
    for (size_t i = 1; i < n; i++)
    {
        ans = ans + string;
    }
    return ans;
}

template<typename T> void change(const T& n)
{
    T fives(n / 5), tens(n / 10), count = (fives % 2 == 1) ? (tens + 2) * (tens + 1) : (tens + 2) * (tens + 1) - tens - 1;
    std::cout << count << std::endl;

    std::string ans;
    for (size_t i = 0; i < fives + 1; i++)
    {
        for (size_t j = 0; j < (n - i * 5) / 10 + 1; j++)
        {
            ans = repeat("1 ", n - i * 5 - j * 10) + repeat("5 ", i) + repeat("10 ", j);
            ans.pop_back();
            std::cout << n - i * 4 - j * 9 << " " << ans << std::endl;
        }
    }
}

int main()
{
    uint32_t n;
    std::cin >> n;
    change(n);
    return 0;
}
