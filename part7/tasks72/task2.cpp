#include <cstdint>
#include <cstddef>
#include <iostream>
#include <map>
#include <vector>

template<typename T> bool dominant_element(const std::vector<T>& array)
{
    if (array.size() < 3)
    {
        return false;
    }

    std::map<T, size_t> element_counts;
    for (auto element : array)
    {
        if (element_counts.contains(element))
        {
            element_counts[element]++;
        }
        else
        {
            element_counts[element] = 1;
        }
    }

    size_t dominants(0);
    for (auto count : element_counts)
    {
        if (array.size() / 4 < count.second)
        {
            dominants++;
        }
    }
    return (dominants >= 3) ? true : false;
}

int main()
{
    size_t n;
    uint32_t input;
    std::vector<uint32_t> array;

    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> input;
        array.push_back(input);
    }

    std::cout << dominant_element(array) << std::endl;
}
