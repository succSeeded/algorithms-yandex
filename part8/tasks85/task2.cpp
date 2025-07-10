#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

template <typename T> void write_vector(std::vector<T> &vtr, const size_t &n) {
  T input;
  for (size_t i = 0; i < n; i++) {
    std::cin >> input;
    vtr.push_back(input);
  }
}

// Convert idx of a 3d matrix to that of a 1d matrix
unsigned int get_index(const unsigned int &n_rows, const unsigned int &n_cols,
                       const unsigned int &n_cols2, const unsigned int &row,
                       const unsigned int &col, const unsigned int &col2) {
  return row * n_cols + col + col2 * n_cols * n_rows;
}

template <typename T>
size_t subseq_len(const std::vector<T> &a, const std::vector<T> &b,
                  const std::vector<T> &c) {
  size_t n(a.size()), m(b.size()), k(c.size()), eq_currs;
  std::vector<size_t> table((n + 1) * (m + 1) * (k + 1), 0);

  unsigned int idx{0}, idx1{0}, idx2{0}, idx3{0}, idx4{0};

  for (size_t i = 1; i < (n + 1); i++) {
    for (size_t j = 1; j < (m + 1); j++) {
      for (size_t p = 1; p < (k + 1); p++) {
        idx = get_index(n + 1, m + 1, k + 1, i, j, p);
        idx1 = get_index(n + 1, m + 1, k + 1, i - 1, j, p);
        idx2 = get_index(n + 1, m + 1, k + 1, i, j - 1, p);
        idx3 = get_index(n + 1, m + 1, k + 1, i, j, p - 1);
        idx4 = get_index(n + 1, m + 1, k + 1, i - 1, j - 1, p - 1);

        table[idx] = std::max(std::max(table[idx1], table[idx2]), table[idx3]);

        if ((a[i - 1] == b[j - 1]) && (b[j - 1] == c[p - 1]) &&
            (a[i - 1] == c[p - 1])) {
          table[idx] = std::max(table[idx], table[idx4] + 1);
        }

        // std::cout << "At [" << i << ", " << j << ", " << k << "] table is "
        //           << table[idx] << "\n";
      }
    }
  }

  idx = get_index(n + 1, m + 1, k + 1, n, m, k);
  return table[idx];
}

int main() {
  size_t n, m, k;
  std::vector<int64_t> a, b, c;

  std::cin >> n;
  write_vector(a, n);
  std::cin >> m;
  write_vector(b, m);
  std::cin >> k;
  write_vector(c, k);

  std::cout << subseq_len(a, b, c) << std::endl;

  return 0;
}
