#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

template<typename T> double max_profit(std::vector<T> prices, std::vector<T> masses, const T& w)
{
    if ((w <= 0) || prices.empty() || masses.empty())
    {
        return 0.0;
    }

    T max_cost_mass(0);
    size_t max_cost_id(0);
    double cost(0.0), max_cost(0.0);
    for (size_t i = 0; i < prices.size(); i++)
    {
        cost = (double)prices[i] / (double)masses[i];
        if (max_cost < cost)
        {
            max_cost = cost;
            max_cost_id = i;
            max_cost_mass = masses[i];
        }
    }
    prices.erase(prices.begin() + max_cost_id);
    masses.erase(masses.begin() + max_cost_id);
    return max_cost * std::min(w, max_cost_mass) + max_profit(prices, masses, w - std::min(w, max_cost_mass));
}

int main()
{
    uint32_t n, w, price, mass;
    std::vector<uint32_t> prices, masses;
    std::cin >> n >> w;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> price >> mass;
        prices.push_back(price);
        masses.push_back(mass);
    }
    std::cout << std::fixed << std::setprecision(4) << max_profit(prices, masses, w) << std::endl;
    return 0;
}
