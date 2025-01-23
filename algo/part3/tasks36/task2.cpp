#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int lomuto_partition(std::vector<int>& v, const int& first, const int& last)
{
    if (v.size() == 1)
    {
        return 0;
    }

    int c_small_size = 0, m = v[first];
    for (size_t i = 1; i < (last - first + 1); i++)
    {
        if (v[first+i] < m)
        {
            std::iter_swap(v.begin() + first + c_small_size + 1, v.begin() + first + i);
            c_small_size++;
        }
    }
    if (c_small_size > 0)
    {
        std::iter_swap(v.begin() + first, v.begin() + first + c_small_size);
    }

    return first + c_small_size;
}

void quicksort(std::vector<int>& v, const int& first, const int& last)
{
    if (first < last)
    {
        std::srand(std::time(nullptr));
        int m = std::rand() % (last - first);
        std::iter_swap(v.begin() + first, v.begin() + first + m);

        int piv = lomuto_partition(v, first, last);
        quicksort(v, first, piv-1);
        quicksort(v, piv+1, last);
    }    
}

int main() 
{
    int n, input;
    std::vector<int> sorted, input_v;

    std::cin >> n;

    for (size_t j = 0; j < n; j++) 
    {
        std::cin >> input;
        sorted.push_back(input);
    }

    quicksort(sorted, 0, n-1);

    for (auto i = sorted.begin(); i != sorted.end()-1; i++) 
    {
        std::cout << *i << " ";
    }
    std::cout << sorted.back() << std::endl;
}