#include <iostream>

int sum(const int& lhs, const int& rhs)
{
    return lhs+rhs;
}

int main()
{
    int lhs(0), rhs(0);

    std::cin >> lhs >> rhs;
    std::cout << sum(lhs, rhs);

    return 0;
}