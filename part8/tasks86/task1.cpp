#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>

template <typename T> void write_vector(std::vector<T> &vtr, const size_t &n) {
  T input;
  for (size_t i = 0; i < n; i++) {
    std::cin >> input;
    vtr.push_back(input);
  }
}

template <typename T, typename Y>
T idx2d(const T &n_rows, const T &n_cols, const Y &row, const Y &col) {
  return row * n_cols + col;
}

template <typename T> T solve(const std::vector<T> &weights, const T &W) {
  size_t n = weights.size();
  std::vector<bool> Knapsack((n + 1) * (W + 1), false);

  Knapsack[idx2d(n + 1, W + 1, 0, 0)] = true;

  for (size_t i = 1; i < n + 1; i++) {
    for (size_t j = 0; j < W + 1; j++) {
      if (j < weights[i - 1]) {
        Knapsack[idx2d(n + 1, W + 1, i, j)] =
            Knapsack[idx2d(n + 1, W + 1, i - 1, j)];
      } else {
        Knapsack[idx2d(n + 1, W + 1, i, j)] =
            Knapsack[idx2d(n + 1, W + 1, i - 1, j)] ||
            Knapsack[idx2d(n + 1, W + 1, i - 1, j - weights[i - 1])];
      }
    }
  }

  for (size_t w = W; w > 0; w--) {
    if (Knapsack[idx2d(n + 1, W + 1, n, w)]) {
      return w;
    }
  }
  return 0;
}

int main() {

  size_t W, n;
  std::vector<size_t> bar_weights;

  std::cin >> W >> n;
  write_vector(bar_weights, n);

  std::cout << solve(bar_weights, W) << std::endl;

  return 0;
}
