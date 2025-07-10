#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

int main() 
{
    uint32_t input, weak(0), strong(0);
    size_t n_competitors, competitorno, n_wins(0);
    std::vector<uint32_t> skill_levels;

    std::cin >> n_competitors >> competitorno;

    for (size_t i = 0; i < n_competitors; i++)
    {
        std::cin >> input;
        skill_levels.push_back(input);
    }

    for (size_t i = 0; i < n_competitors; i++)
    {
        if (skill_levels[i] < skill_levels[competitorno-1])
        {
            weak++;
        }
        else if (skill_levels[i] > skill_levels[competitorno-1])
        {
            strong++;
        }
    }

    while (weak >= 1)
    {
        if ((strong % 2 == 1) || (weak % 2 == 1))
        {
            weak -= 1;
        }
        weak = weak / 2;
        strong = strong / 2;
        n_wins++;
    }

    std::cout << n_wins << std::endl;

    return 0;
}
