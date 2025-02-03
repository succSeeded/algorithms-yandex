#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

template<typename T> T sum(const std::vector<T>& vtr)
{
    if (vtr.empty())
    {
        return 0;
    }
    T ans(vtr[0]);
    for (auto v = vtr.begin()+1; v != vtr.end(); v++)
    {
        ans = ans + (*v);
    }
    return ans;
}

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

template <typename T> void change(T n)
{
    std::string ans="";
    std::vector<T> values{50, 20, 10, 5, 1}, counts;

    for (size_t i = 0; i < values.size(); i++)
    {
        if (n / values[i] > 0)
        {
            counts.push_back(n / values[i]);
            n = n - (*(counts.end()-1)) * values[i];
            ans = ans + repeat(std::to_string(values[i]) + " ", *(counts.end()-1));
        }
    }
    ans.pop_back();
    std::cout << sum(counts) << std::endl;
    std::cout << ans << std::endl;
}

int main()
{
    uint32_t money;
    std::cin >> money;
    change(money); 
    return 0;
}
