#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

template<typename T> unsigned long min_segmentlen(const std::vector<T>& points, const size_t& n_segments)
{
    if (points.size() < n_segments)
    {
        return 0;
    }

    find_first(points, )
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
