#include <iostream>
#include <math.h>

int hanoi3(const int& h) {
    if (h > 1) {
        return 2*hanoi3(h - 1) + 1;
    }
    else {
        return 1;
    }
}

int hanoi4(const int& h) {
    if (h == 1) {
        return 1;
    }
    else {
        int k = int(floor(0.5*(sqrt(8.0*h + 1.0) - 1.0)));

        return 2*hanoi4(h - k) + hanoi3(k);
    }
}

int main() {
    int height, n(0);
    std::cin >> height;
    std::cout << hanoi4(height) << std::endl;
    return 0;
}