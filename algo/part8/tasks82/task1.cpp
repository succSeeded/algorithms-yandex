#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

template<typename T> T change(const T& money, const std::vector<T>& nominal_vals)
{
    if ((money == 1) || (money == 3) || (money == 4))
    {
        return 1;
    }
    
    std::vector<T> changes_list(money+1, 1000);
    changes_list[0] = 0;

    for (T curr_money = 1; curr_money < money+1; curr_money++)
    {
        for (auto coin : nominal_vals)
        {
            if (coin <= curr_money)
            {
                changes_list[curr_money] = std::min(changes_list[curr_money], changes_list[curr_money-coin] + 1);
            }
        }
    }
    return changes_list[money];
}

int main()
{
    uint32_t money;
    std::vector<uint32_t> nominal_vals{1, 3, 4};
    std::cin >> money;

    std::cout << change(money, nominal_vals) << std::endl;
    return 0;
}
