#include <cstddef>
#include <iostream>
#include <vector>

template<typename T> long find_first(const std::vector<T>& array, const T& query)
{
    size_t begin(0), end(array.size()), piv;
    while (end - begin > 1)
    {
        piv = (begin + end) / 2 + (begin + end) % 2;
        if (array[piv] < query)
        {
            begin = piv + 1;
        }
        else if ((array[piv] == query) && (array[piv-1] != query))
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

template<typename T> unsigned long count (const std::vector<T>& array, const T& query)
{
    size_t ans(0);
    int j(find_first(array, query));
    if (j != -1)
    {
        while (array[j + ans] == query)
        {
            ans++;
        }
    }
    return ans;
}

template<typename T> void count (const std::vector<T>& array, const std::vector<T>& query)
{
    for (auto i = query.begin(); i != query.end(); i++)
    {
        std::cout << count(array, (*i)) << " ";
    }
    std::cout << std::endl;
}

int main()
{
    size_t n;
    unsigned long input;
    std::vector<unsigned long> K, Q;

    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> input;
        K.push_back(input);
    }
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> input;
        Q.push_back(input);
    }

    count(K, Q);
}
