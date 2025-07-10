#include <iostream>
#include <vector>
#include <string>

int main() 
{
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> table((n+1)*(m+1), 0);

    for (size_t i = 1; i < n+1; i++)
    {
        table[(m+1)*i] = 1 - table[(m+1)*(i-1)];
    }
    
    for (size_t j = 1; j < m+1; j++)
    {
        table[j] = 1 - table[j-1];
        for (size_t i = 1; i < n+1; i++)
        {
            table[(m+1)*i+j] = 1 - table[(m+1)*i+j-1] * table[(m+1)*(i-1)+j-1] * table[(m+1)*(i-1)+j];
        }
    }
    
    std::string ans = (table[(n+1)*(m+1)-1]) ? "Win" : "Lose";

    std::cout << ans << std::endl;

    return 0;
}