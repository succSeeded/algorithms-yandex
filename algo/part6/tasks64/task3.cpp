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

template<typename T, typename Y> unsigned long covering_intervals_len(const std::vector<T>& points, const Y& n)
{
    if (points.size() < n)
    {
        return 0;
    }

    Y n_points(points.size());
    unsigned long total_length(points.back() - points.front());
    std::vector<unsigned long> intervals;

    for (size_t i = 0; i < (n_points-1); i++)
    {
        intervals.push_back(points[i+1] - points[i]);
    }
    std::sort(intervals.begin(), intervals.end());

    for (size_t i = 1; i < n; i++)
    {
        total_length -= intervals[n_points-1-i];
    }
    return total_length;
}

int main()
{
    size_t n, m;
    std::vector<long long> points;

    std::cin >> n >> m;
    write_vector(points, n);
    std::sort(points.begin(), points.end());

    std::cout << covering_intervals_len(points, m) << std::endl;

    return 0;
}
