#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

template<typename T> bool is_partition(const std::vector<T>& points, const size_t& n_segments, const T& len_segments)
{
    size_t curr_segments(1);
    T left(points.front()), right(points.back()), curr_left(points.front());

    for (auto i = points.begin(); i != points.end(); i++)
    {
        if (curr_left + len_segments < (*i))
        {
            curr_segments++;
            curr_left = *i;
        }
        if (n_segments < curr_segments)
        {
            return false;
        }
    }
    return true;
}

template<typename T> unsigned long min_segmentlen(const std::vector<T>& points, const size_t& n_segments)
{
    if (points.size() <= n_segments)
    {
        return 0;
    }

    T min_len(0), max_len(points.back() - points.front()), pivot;

    while (max_len != min_len)
    {
        pivot = (min_len + max_len) / 2;
        if ((max_len == pivot) || (min_len == pivot))
        {
            return max_len;
        }
        if (is_partition(points, n_segments, pivot))
        {
            max_len = pivot;
        }
        else
        {
            min_len = pivot;
        }
    }
    return max_len;
}

int main()
{
    size_t n_points, n_segments;
    unsigned long input;
    std::vector<unsigned long> points;

    std::cin >> n_points >> n_segments;
    for (size_t i = 0; i < n_points; i++)
    {
        std::cin >> input;
        points.push_back(input);
    }

    std::sort(points.begin(), points.end());

    std::cout << min_segmentlen(points, n_segments) << std::endl;
}
