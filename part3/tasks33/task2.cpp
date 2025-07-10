#include <iostream>
#include <vector>
#include <string>

int main() 
{
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> table((n+1)*(m+1), 0);

    table[1] = 1;
    table[m+1] = 1;

    for (size_t i = 2; i < n+1; i++)
    {
        table[(m+1)*i] = 1 - table[(m+1)*(i-1)] * table[(m+1)*(i-2)];
        table[(m+1)*i+1] = 1 - table[(m+1)*(i-1)+1] * table[(m+1)*(i-2)+1] * table[(m+1)*(i-2)] * table[(m+1)*i];
    }

    for (size_t j = 2; j < m+1; j++)
    {
        table[j] = 1 - table[j-1]*table[j-2];
        table[(m+1)+j] = 1 - table[(m+1)+j-1] * table[(m+1)+j-2] * table[j-2] * table[j];
        for (size_t i = 2; i < n+1; i++)
        {
            table[(m+1)*i+j] = 1 - table[(m+1)*i+j-1] * table[(m+1)*i+j-2] * table[(m+1)*(i-1)+j-2] * table[(m+1)*(i-1)+j] * table[(m+1)*(i-2)+j] * table[(m+1)*(i-2)+j-1];
        }
    }
    
    std::string ans = (table[(n+1)*(m+1)-1]) ? "Win" : "Lose";

    std::cout << ans << std::endl;

    return 0;
}