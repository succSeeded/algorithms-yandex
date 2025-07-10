#include <iostream>
#include <string>

std::string merge(const int& len, const std::string& lhs, const std::string& rhs) {

    std::string merged;
    for (size_t i = 0; i < len; i++) 
    {
        merged.push_back(lhs[i]);
        merged.push_back(rhs[i]);
    }
    return merged;
}

int main()
{
    int n;
    std::string lhs, rhs;
    std::cin >> n;
    std::cin >> lhs;
    std::cin >> rhs;

    std::cout << merge(n, lhs, rhs) << std::endl;
}