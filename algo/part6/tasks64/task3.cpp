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

template<typename T> unsigned long min_covering_len(const std::vector<T>& points, const T& n_intervals)
{
    if (n_intervals <= 0)
    {
        return 0;
    }
    if (points.size() < n_intervals)
    {
        return 0;
    }

    size_t n(points.size());
    T min_len(points.back() - points.front());
    for (size_t i = 0; i < (n - 1); i++)
    {
        if ((points[i+1] - points[i] < min_len) && (points[i] != points[i+1]))
        {
            min_len = (points[i+1] - points[i];
        }
    }
    if ()
    {

    }
    else
    {
        return 0;
    }
}

int main()
{
    long long n, m;
    std::vector<long long> points;

    std::cin >> n >> m;
    write_vector(points, n);
    std::sort(points.begin(), points.end());

    std::cout << covering_intervals(points, m) << std::endl;

    return 0;
}
