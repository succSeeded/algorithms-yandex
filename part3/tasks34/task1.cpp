#include <iostream>
#include <string>

void hanoi(const int& n, const int& fromPeg, const int& toPeg, std::string& output, int& nActions) {
    if (n > 1) {
        int unusedPeg = 6 - fromPeg - toPeg;
        hanoi(n-1, fromPeg, unusedPeg, output, nActions);
        nActions++;
        output.append(std::to_string(fromPeg)+std::to_string(toPeg));
        hanoi(n-1, unusedPeg, toPeg, output, nActions);
    }
    else {
        nActions++;
        output.append(std::to_string(fromPeg)+std::to_string(toPeg));
    }
}

int main() {
    int height, n(0);
    std::string ans;
    std::cin >> height;
    hanoi(height, 1, 3, ans, n);
    std::cout << n << std::endl;
    for (size_t i = 0; i < n; i++)
        std::cout << ans[i] << " " << ans[i+1] << std::endl;
    return 0;
}
