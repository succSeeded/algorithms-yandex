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

template<class Iter> Iter last_copy(Iter first, Iter last)
{
    if (last - first == 1)
    {
        return first;
    }

    size_t n_copies(1);
    for (size_t i = 1; i < (last - first); i++)
    {
        if (*(first+i) == *first)
        {
            std::iter_swap(first + n_copies, first + i);
            n_copies++;
        }
    }

    return first + n_copies;
}

template<class Iter> void quicksort(Iter first, Iter last)
{
    if (last - first > 1)
    {
        std::srand(std::time(nullptr));
        size_t m = std::rand() % (last - first);
        std::iter_swap(first, first + m);

        Iter piv1 = lomuto_partition(first, last);
        Iter piv2 = last_copy(piv1, last);
        quicksort(first, piv1);
        quicksort(piv2, last);
    }
}

template<typename T> void quicksort(std::vector<T>& vtr)
{
    quicksort(vtr.begin(), vtr.end());
}

int main()
{
    size_t n;
    long input;
    std::vector<long> sorted;

    std::cin >> n;
    for (size_t j = 0; j < n; j++)
    {
        std::cin >> input;
        sorted.push_back(input);
    }

    quicksort(sorted.begin(), sorted.end());
    print_vector(sorted.begin(), sorted.end());
}
