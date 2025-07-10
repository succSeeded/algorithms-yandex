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

template<class Iter> Iter lomuto_partition(Iter first, Iter last)
{
    if (last - first == 1)
    {
        return first;
    }

    size_t c_small_size = 0;
    for (size_t i = 1; i < (last - first); i++)
    {
        if (*(first+i) < *first)
        {
            std::iter_swap(first + c_small_size + 1, first + i);
            c_small_size++;
        }
    }
    if (c_small_size > 0)
    {
        std::iter_swap(first, first + c_small_size);
    }

    return first + c_small_size;
}

template<class Iter> void quicksort(Iter first, Iter last)
{
    if (last - first > 1)
    {
        std::iter_swap(first, first + (last - first) / 2 - 1);

        Iter piv1 = lomuto_partition(first, last);
        std::cout << "pivot: " << *piv1 << std::endl;
        print_vector(first, last);
        quicksort(first, piv1);
        quicksort(piv1+1, last);
    }
}

int main()
{
    size_t n;
    std::cin >> n;
    std::vector<unsigned long> vtr(n);

    for (size_t i = 0; i < n; i++)
    {
        vtr[(n - i) / 2 + (i % 2) * (i + 1) - 1] = n-i;
    }

    print_vector(vtr.begin(), vtr.end());
    quicksort(vtr.begin(), vtr.end());

    return 0;
}
