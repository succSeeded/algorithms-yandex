#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

template<class Iter> void print_vector(Iter first, Iter last)
{
    for (auto i = first; i != last-1; i++)
    {
        std::cout << *i;
    }
    std::cout << *(last-1) << std::endl;
}

template<typename T> T magnitude(T integer)
{
    T ans(1);
    while (integer >= 1)
    {
        integer = integer / 10;
        ans *= 10;
    }
    return ans;
} 

int main() 
{
    size_t n_papers;
    uint32_t input;
    std::vector<uint32_t> numbers;
    
    std::cin >> n_papers;
    for (size_t i = 0; i < n_papers; i++)
    {
        std::cin >> input;
        numbers.push_back(input);
    }

    std::sort(numbers.begin(), numbers.end(), [](const uint32_t& lhs, const uint32_t& rhs)
    {
        return (magnitude(rhs) * lhs + rhs) > (magnitude(lhs) * rhs + lhs);
    });

    print_vector(numbers.begin(), numbers.end());

    return 0;
}
