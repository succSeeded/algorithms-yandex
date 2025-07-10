#include <iostream>

int factorial(const int n) {
    int out (1);

    for (int i = 0; i < n; i++)
    {
        out *= i + 1;
    }

    return out;
}

int main() {

    int k, n;

    std::cin >> n >> k;
    std::cout << factorial(n)/factorial(k)/factorial(n-k);

    return 0;
}