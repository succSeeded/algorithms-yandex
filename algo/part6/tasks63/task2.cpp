#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

template<typename T> size_t lomuto_partition(std::vector<T>& v, const size_t& first, const size_t& last)
{
    if (first == last)
    {
        return first;
    }

    size_t c_small_size(0);
    T m(v[first]);
    for (size_t i = 1; i < (last - first + 1); i++)
    {
        if (v[first+i] < m)
        {
            std::iter_swap(v.begin() + first + c_small_size + 1, v.begin() + first + i);
            c_small_size++;
        }
    }
    if (c_small_size > 0)
    {
        std::iter_swap(v.begin() + first, v.begin() + first + c_small_size);
    }

    return first + c_small_size;
}

template<typename T> void quicksort_inplace(std::vector<T>& v, const size_t& first, const size_t& last)
{
    if (first < last)
    {
        std::srand(std::time(nullptr));
        size_t m = std::rand() % (last - first + 1);
        std::iter_swap(v.begin() + first, v.begin() + first + m);

        size_t piv = lomuto_partition(v, first, last);
        if (piv > 0)
        {
            quicksort_inplace(v, first, piv-1);
        }
        if (piv < last)
        {
            quicksort_inplace(v, piv+1, last);
        }
    }
}

template<typename T> void quicksort_inplace(std::vector<T>& v)
{
    quicksort_inplace(v, 0, v.size()-1);
}

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
    quicksort_inplace(offers);
    std::cout << max_profit(offers, n, w) << std::endl;
    return 0;
}
