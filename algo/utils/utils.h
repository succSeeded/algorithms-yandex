#include <iostream>
#include <vector>

template<typename T> void print_vector(const std::vector<T>& v)
{
    std::cout << "{";
    for (auto i = v.begin(); i != v.end()-1; i++)
    {
        std::cout << *i << ", ";
    }
    std::cout << v.back() << "}" << std::endl;
}

template<typename T> void write_vector(std::vector<T>& vtr, const size_t& n)
{
    T input;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> input;
        vtr.push_back(input);
    }
}
