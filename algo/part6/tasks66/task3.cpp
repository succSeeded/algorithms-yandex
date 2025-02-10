#include <cstdint>
#include <cstdlib>
#include <iostream>

int main()
{
    uint32_t n_rows, n_cols, filled_rows, semifilled_rows, ans;
    std::cin >> n_rows >> n_cols;

    semifilled_rows = n_rows / 3 + (n_rows % 3 > 0);
    filled_rows = n_rows - semifilled_rows;
    ans = semifilled_rows * (n_cols - n_cols / 3 - (n_cols % 3 > 0)) + filled_rows * n_cols;

    std::cout << ans << std::endl;
    return 0;
}
