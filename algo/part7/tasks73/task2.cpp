#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

template<class Iter> void print_vector(Iter first, Iter last)
{
    for (auto i = first; i != last-1; i++)
    {
        std::cout << *i << " ";
    }
    std::cout << *(last-1) << std::endl;
}

template<class Iter> void shuffle(Iter first, Iter last)
{
    if ((last - first) == 2)
    {
        std::iter_swap(first, last);
    }
    else if ((last - first) > 2)
    {
        Iter piv(first + (last-first)/2);
        shuffle(first, piv);
        shuffle(piv+1, last);
    }
}

int main()
{
    size_t n;
    std::cin >> n;
    std::vector<unsigned long> vtr;

    for (size_t i = 0; i < n; i++)
    {
        vtr.push_back(i+1);
    }

    shuffle(vtr.begin(), vtr.end());
    print_vector(vtr.begin(), vtr.end());

    return 0;
}
