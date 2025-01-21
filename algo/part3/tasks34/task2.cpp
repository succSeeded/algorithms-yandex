#include <iostream>

void hanoi3(const int& h, int& nActions) {
    if (h > 1) {
        hanoi3(h-1, nActions);
        nActions++;
        hanoi3(h-1, nActions);
    }
    else {
        nActions++;
    }
}

void hanoi4(const int& h, int& nActions) {
    if (h == 1) {
            nActions++;
    }
    else {
        hanoi3(h-2, nActions);
        std::
        hanoi3(h, nActions);
        hanoi3(h-2,nActions);
    }
}


int main() {
    int height, n(0);
    std::cin >> height;
    hanoi4(height, n);
    std::cout << n << std::endl;
    return 0;
}
