#include <iostream>
#include <string>

int main() {
    int n;
    int out (1);
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        out *= i + 1;
    }
    
    std::cout << out;

    return 0;
}