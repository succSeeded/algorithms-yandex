#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

template<typename T> void print_vector(const std::vector<T>& v)
{
    for (auto i = v.begin(); i != v.end()-1; i++)
    {
        std::cout << *i << " ";
    }
    std::cout << v.back() << std::endl;
}

template<typename T> void least_signs(const std::vector< std::vector<T> >& home_times)
{
    size_t n(home_times.size());
    std::vector<T> rightest, signing_times;
    for (size_t i = 0; i < n; i++)
    {
        rightest = home_times[i];
        if ((signing_times.empty()) || (signing_times.back() < rightest[1]))
        {
            signing_times.push_back(rightest[0]);
        }
    }
    std::cout << signing_times.size() << std::endl;
    print_vector(signing_times);
}

int main()
{
    unsigned long n, l, r;
    std::vector< std::vector<unsigned long> > home_times;
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> l >> r;
        home_times.push_back({r, l});
    }
    std::sort(home_times.begin(), home_times.end());
    least_signs(home_times);
    return 0;
}
