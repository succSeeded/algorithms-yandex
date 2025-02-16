#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <iostream>
#include <vector>

template<typename T> double dist(const std::vector<T>& vtr1, const std::vector<T>& vtr2)
{
    T dist(0);
    size_t n(vtr1.size());
    for (size_t i = 0; i < n; i++)
    {
        dist += (vtr1[i] - vtr2[i]) * (vtr1[i] - vtr2[i]);
    }
    return std::sqrt(static_cast<double>(dist));
}

template<class Iter> double min_dist(const Iter& begin, const Iter& end)
{
    if (end - begin <= 1)
    {
        return 0.0;
    }
    else if (end - begin == 2)
    {
        return dist(*begin, *(begin+1));
    }

    size_t n_higher, n(end - begin);
    double d(std::min(min_dist(begin, begin + n/2 + n%2), min_dist(begin + n/2, end)));
    Iter stripe_begin, stripe_end, stripe_sorted_begin, stripe_sorted_end;

    auto center = (*(begin + n/2))[0];

    auto left_criterion = [&center, &d] (auto point) 
                            {
                                return static_cast<double>(center - point[0]) < d;
                            };
    stripe_begin = std::find_if(begin, end, left_criterion);
    
    auto right_criterion = [&center, &d] (auto point) 
                            {
                                return static_cast<double>(point[0] - center) > d;
                            };
    stripe_end = std::find_if(begin, end, right_criterion);

    std::vector<typename std::iterator_traits<Iter>::value_type> stripe(stripe_begin, stripe_end);

    std::sort(stripe.begin(), stripe.end());

    for (size_t i = 0; i < stripe.size(); i++)
    {
        n_higher = std::min(stripe.size(), i + 8);
        for (size_t j = i + 1; j < n_higher; j++)
        {
            if (dist(stripe[i], stripe[j]) > d)
            {
                break;
            }
            d = std::min(dist(stripe[i], stripe[j]), d);
        }
    }

    return d;
}

int main()
{
    size_t n;
    int32_t input_x, input_y;
    std::vector< std::vector<int32_t> > points;

    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> input_x >> input_y;
        points.push_back({input_x, input_y});
    }

    std::sort(points.begin(), points.end(), [](const std::vector<int32_t>& lhs, const std::vector<int32_t>& rhs) {return lhs[0] < rhs[0];});

    std::cout << std::fixed << std::setprecision(6) << min_dist(points.begin(), points.end()) << std::endl;

    return 0;
}
