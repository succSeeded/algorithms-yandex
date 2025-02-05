#include <algorithm>
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

int main()
{
    int n, input;
    std::vector<int> vtr;

    std::cin >> n;

    for (size_t j = 0; j < n; j++)
    {
        std::cin >> input;
        vtr.push_back(input);
    }

    lomuto_partition(vtr.begin(), vtr.end());

    print_vector(vtr);
}
