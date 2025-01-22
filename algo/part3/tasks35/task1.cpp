#include <iostream>
#include <vector>

int main() {
    int n, input, min;
    std::vector<int> a;
    
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> input;
        a.push_back(input);
    }

    for (size_t i = 0; i < n; i++)
    {
        min = i;
        for (size_t j = i; j < n; j++)
        {
            if (a[j] < a[min]) {
                min = j;
            }       
        }
        iter_swap(a.begin()+i, a.begin()+min);
    }
    
    for (auto i = a.begin(); i != a.end()-1; i++) {
        std::cout << *i << " ";
    }
    std::cout << a.back() << std::endl;
}