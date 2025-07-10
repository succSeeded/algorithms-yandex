#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

template<typename T> T max_souvenirs(std::vector<T> prices, T budget)
{
    if ((budget <= 0) || prices.empty())
    {
        return 0;
    }

    T min_price(0);
    size_t min_price_id(0), souvenir_num(0);
    while(true)
    {
        if ((budget <= 0) || prices.empty())
        {
            break;
        }
        for (size_t i = 0; i < prices.size(); i++)
        {
            if (prices[i] < prices[min_price_id])
            {
                min_price_id = i;
            }
        }
        if (prices[min_price_id] <= budget)
        {
            souvenir_num++;
            budget -= prices[min_price_id];
        }
        prices.erase(prices.begin() + min_price_id);
    }
    return souvenir_num;
}

int main()
{
    uint32_t n, budget, price;
    std::vector<uint32_t> prices;
    std::cin >> n >> budget;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> price;
        prices.push_back(price);
    }
    std::cout << max_souvenirs(prices, budget) << std::endl;
    return 0;
}
