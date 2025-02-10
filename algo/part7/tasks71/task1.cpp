#include <cstddef>
#include <iostream>
#include <vector>

template<typename T> int find(const std::vector<T>& array, const T& query)
{
    size_t begin(0), end(array.size()), piv;
    while (end - begin > 1)
    {
        piv = (begin + end) / 2 + (begin + end) % 2;
        if (array[piv] < query)
        {
            begin = piv + 1;
        }
        else if (array[piv] == query)
        {
            return piv;
        }
        else
        {
            end = piv;
        }
    }
    if (array[begin] == query)
    {
        return begin;
    }
    else
    {
        return -1;
    }
}

int main()
{
    size_t n;
    unsigned long q, input;
    std::vector<unsigned long> K;

    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> input;
        K.push_back(input);
    }
    std::cin >> q;

    std::cout << find(K, q) << std::endl;
}
