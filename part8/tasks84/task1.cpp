#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>


size_t editorial_distance(const std::string& upper_str, const std::string& lower_str)
{
    size_t n(upper_str.size()), m(lower_str.size()), incertion_up, incertion_low, replacement;
    std::vector<size_t> table(2*(m+1), 0);

    for (size_t i = 0; i < (m+1); i++)
    {
        table[i] = i;
    }

    for (size_t i = 1; i < (n+1); i++)
    {
        table[(i % 2) * (m + 1)] = i;

        for (size_t j = 1; j < (m+1); j++)
        {
            incertion_low = table[(i % 2) * (m + 1) + j - 1] + 1;
            incertion_up = table[((i + 1) % 2) * (m + 1) + j] + 1;
            replacement = table[((i + 1) % 2) * (m + 1) + j - 1] + 1;
            
            if (upper_str[i-1] == lower_str[j-1])
            {
                table[(i % 2) * (m + 1) + j] = table[((i + 1) % 2) * (m + 1) + j - 1];
            }
            else
            {
                table[(i % 2) * (m + 1) + j] = std::min(std::min(incertion_low, incertion_up), replacement);
            }
        }
    }

    return table[(n % 2) * (m + 1) + m];
}


int main()
{
    std::string upper_str, lower_str;
    std::cin >> upper_str >> lower_str;

    // Ensure that the lower string is the smallest.
    // This allows us to use only O(min(n,m)) memory.
    if (upper_str.size() < lower_str.size())
    {
        std::swap(upper_str, lower_str);
    }

    std::cout << editorial_distance(upper_str, lower_str);

    return 0;
}
