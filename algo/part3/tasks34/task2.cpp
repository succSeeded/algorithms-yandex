#include <iostream>
#include <string>

void hanoi4(const int& n, int& nActions) {
    switch(n) {
        case 1:
            nActions++;
        default:
            nActions++;
            hanoi4(n-1, nActions);
            nActions++;
    }
}

int main() {
    int height, n(0);
    std::cin >> height;
    hanoi4(height, n);
    std::cout << n << std::endl;
    return 0;
}