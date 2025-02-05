#include <algorithm>
#include <iostream>
#include <vector>

void many(const int& n, const int& m, const std::vector<int>& lhs, const std::vector<int>& rhs)
{
    std::cout << std::max(n-1, m-1) << std::endl;

    int id(n-1);
    std::vector<int> a(lhs);
    for (size_t i = 0; i < m; i++)
    {
        a[id] += rhs[m - i - 1];
        id--;
    }

    for (auto i = a.begin(); i != a.end()-1; i++)
    {
        std::cout << *i << " ";
    }
    std::cout << a.back() << std::endl;
}

int main()
{
    int n(0), m(0), input;
    std::vector<int> a, b;

    std::cin >> n;
    for (size_t i = 0; i < n+1; i++)
    {
        std::cin >> input;
        a.push_back(input);
    }
    std::cin >> m;
    for (size_t i = 0; i < m+1; i++)
    {
        std::cin >> input;
        b.push_back(input);
    }

    if (n < m)
    {
        a.swap(b);
        std::swap(n, m);
    }

    many(n+1, m+1, a, b);
    return 0;
}
