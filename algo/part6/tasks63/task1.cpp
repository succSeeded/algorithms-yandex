#include <cstddef>
#include <iostream>
#include <vector>

template<typename T> void write_vector(std::vector<T>& vtr, const size_t& n)
{
    T input;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> input;
        vtr.push_back(input);
    }
}

template<typename T> T max_profit(std::vector<T> prices, std::vector<T> clicks)
{
    if (prices.empty() || clicks.empty())
    {
        return 0;
    }

    size_t n(prices.size());
    T total_profit(0), max_profit(0);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n - i; j++)
        {

        }
    }

    return profit;
}

int main()
{
    size_t n;
    unsigned long input;
    std::vector<unsigned long> prices, clicks;

    std::cin >> n;
    write_vector(prices, n);
    write_vector(clicks, n);

    std::cout << max_profit(prices, clicks) << std::endl;

    return 0;
}
