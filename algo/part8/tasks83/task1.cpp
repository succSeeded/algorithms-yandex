#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

template<class Iter> void print_vector(Iter first, Iter last)
{
    for (auto i = first; i != last-1; i++)
    {
        std::cout << *i << " ";
    }
    std::cout << *(last-1) << std::endl;
}

template<typename T> void calculator(const T& money)
{
    std::vector<T> table(money);
    table[0] = 0;

    for (size_t i = 1; i < money; i++)
    {
        table[i] = 1 + table[i-1];
        if ((i + 1) % 2 == 0)
        {
            table[i] = std::min(table[i], 1 + table[(i + 1) / 2 - 1]);
        }
        if ((i + 1) % 3 == 0)
        {
            table[i] = std::min(table[i], 1 + table[(i + 1) / 3 - 1]);
        }
    }

    std::cout << table.back() << std::endl;

    std::vector<T> operations(table.back() + 1, 1);
    size_t n(operations.size());
    T curr_sum(money);
    for (size_t k = 1; k < n; k++)
    {
        operations[n - k] = curr_sum;
        if (table[curr_sum-1] == table[curr_sum-2] + 1)
        {
            curr_sum = curr_sum - 1;
        }
        else if ((curr_sum % 2 == 0) && (table[curr_sum-1] == table[curr_sum/2-1] + 1))
        {
            curr_sum = curr_sum / 2;
        }
        else if ((curr_sum % 3 == 0) && (table[curr_sum-1] == table[curr_sum/3-1] + 1))
        {
            curr_sum = curr_sum / 3;
        }
    }
    print_vector(operations.begin(), operations.end());
}

int main()
{
    uint32_t money;
    std::vector<uint32_t> nominal_vals{1, 3, 4};
    std::cin >> money;

    calculator(money);
    return 0;
}
