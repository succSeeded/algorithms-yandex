#include <algorithm>
#include <cstddef>
#include <ctime>
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

    unsigned long c_small_size = 0, m = (*first);
    for (size_t i = 1; i < (last - first); i++)
    {
        if (*(first+i) < m)
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
        std::srand(std::time(nullptr));
        size_t m = std::rand() % (last - first);
        std::iter_swap(first, first + m);

        Iter piv = lomuto_partition(first, last);
        quicksort(first, piv);
        quicksort(piv+1, last);
    }
}

template<typename T> void quicksort(std::vector<T>& vtr)
{
    quicksort(vtr.begin(), vtr.end());
}

int main()
{
    int n, input;
    std::vector<int> sorted;

    std::cin >> n;
    for (size_t j = 0; j < n; j++)
    {
        std::cin >> input;
        sorted.push_back(input);
    }

    quicksort(sorted.begin(), sorted.end());
    print_vector(sorted.begin(), sorted.end());
}
