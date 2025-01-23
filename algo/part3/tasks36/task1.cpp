#include <iostream>
#include <vector>

std::vector<int> lomuto_partition(std::vector<int> v)
{
    if (v.size() == 1)
    {
        return v;
    }

    int c_small_size = 0, m = v[0];
    for (size_t i = 1; i < v.size(); i++)
    {
        if (v[i] < m)
        {
            std::iter_swap(v.begin() + c_small_size + 1, v.begin() + i);
            c_small_size++;
        }
    }
    if (c_small_size > 0)
    {
        std::iter_swap(v.begin(), v.begin() + c_small_size);
    }

    return v;
}

int main() 
{
    int n, input;
    std::vector<int> sorted, input_v;

    std::cin >> n;

    for (size_t j = 0; j < n; j++) 
    {
        std::cin >> input;
        input_v.push_back(input);
    }

    sorted = lomuto_partition(input_v);

    for (auto i = sorted.begin(); i != sorted.end()-1; i++) 
    {
        std::cout << *i << " ";
    }
    std::cout << sorted.back() << std::endl;
}