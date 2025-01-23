#include <iostream>
#include <vector>

std::vector<std::vector<int>> sum(const std::vector<std::vector<int>>& lhs, std::vector<std::vector<int>> rhs)
{
    std::vector<int> row;
    std::vector<std::vector<int>> ans;
    for (size_t i = 0; i < lhs.size(); i++)
    {
        for (size_t j = 0; j < lhs[0].size(); j++)
        {
           row.push_back(lhs[i][j] + rhs[i][j]);
        }
        ans.push_back(row);
        row.clear();
    }
    return ans;
}

int main()
{
    int n(0), m(0), input;
    std::vector<int> input_v;
    std::vector<std::vector<int>> lhs, rhs, ans;

    std::cin >> n >> m;

    for (size_t i = 0; i < n; i++) 
    {
        for (size_t j = 0; j < m; j++) 
        {
            std::cin >> input;
            input_v.push_back(input);
        }
        lhs.push_back(input_v);
        input_v.clear();
    }

    for (size_t i = 0; i < n; i++) 
    {
        for (size_t j = 0; j < m; j++) 
        {
            std::cin >> input;
            input_v.push_back(input);
        }
        rhs.push_back(input_v);
        input_v.clear();
    }

    ans = sum(lhs, rhs);
    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        for (auto j = (*i).begin(); j != (*i).end()-1; j++) 
        {
            std::cout << *j << " ";
        }
        std::cout << (*i).back() << std::endl;
    }
    return 0;
}