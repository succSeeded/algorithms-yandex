#include <iostream>
#include <cmath>

template<typename T> void prizes(const T& n_candies)
{
    unsigned long k = std::floor(-0.5+std::sqrt(1.0+8.0*n_candies)*0.5);
    std::cout << k;
}

int main()
{
    unsigned long n_candies;
    std::cin >> n_candies;

    prizes(n_candies);
}
