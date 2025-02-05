#include <algorithm>
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

template<typename T> unsigned long covering_intervals(const std::vector<T>& points, const T& len)
{
    size_t n(points.size());
    unsigned long n_intervals(1);
    T r_m(points[0] + len);

    for (size_t i = 0; i < n; i++)
    {
        if (r_m < points[i])
        {
            r_m = points[i] + len;
            n_intervals++;
        }
    }

    return n_intervals;
}

int main()
{
    long long n, len;
    std::vector<long long> points;

    std::cin >> n >> len;
    write_vector(points, n);
    std::sort(points.begin(), points.end());

    std::cout << covering_intervals(points, len) << std::endl;

    return 0;
}
