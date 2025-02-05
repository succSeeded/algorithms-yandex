#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

template<typename T> T max_profit(const std::vector< std::vector<T> >& offers, const size_t& n_billboards, const size_t& n_weeks)
{
    if (offers.empty() || n_weeks == 0)
    {
        return 0;
    }

    T total_profit(0);
    size_t n_offers(offers.size()), free_space(n_weeks * n_billboards), uptime(0);
    for (size_t i = 0; i < n_offers; i++)
    {
        uptime = std::min(free_space, offers[n_offers - i - 1][1]);
        free_space -= uptime;
        total_profit += offers[n_offers - i - 1][0] * uptime;

        if (free_space <= 0)
        {
            break;
        }

    }
    return total_profit;
}

int main()
{
    unsigned long n, k, w, price, period;
    std::vector< std::vector<unsigned long> > offers;
    std::cin >> n >> k >> w;
    for (size_t i = 0; i < k; i++)
    {
        std::cin >> price >> period;
        offers.push_back({price, period});
    }
    std::sort(offers.begin(), offers.end()x);
    std::cout << max_profit(offers, n, w) << std::endl;
    return 0;
}
