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

template <typename T>
size_t subseq_len(const std::vector<T> &upper_seq,
                  const std::vector<T> &lower_seq) {
  size_t n(upper_seq.size()), m(lower_seq.size()), eq_currs;
  std::vector<size_t> table(2 * (m + 1), 0);

  for (size_t i = 1; i < (n + 1); i++) {
    table[(i % 2) * (m + 1)] = 0;
    for (size_t j = 1; j < (m + 1); j++) {
      table[(i % 2) * (m + 1) + j] = std::max(
          table[(i % 2) * (m + 1) + j - 1], table[((i + 1) % 2) * (m + 1) + j]);
      eq_currs = table[((i + 1) % 2) * (m + 1) + j - 1] + 1;
      if (upper_seq[i - 1] == lower_seq[j - 1]) {
        table[(i % 2) * (m + 1) + j] =
            std::max(table[(i % 2) * (m + 1) + j], eq_currs);
      }
    }
  }

  return table[(n % 2) * (m + 1) + m];
}

int main() {
  size_t n, m;
  std::vector<int64_t> upper_seq, lower_seq;

  std::cin >> n;
  write_vector(upper_seq, n);
  std::cin >> m;
  write_vector(lower_seq, m);

  // Ensure that the lower sequence is the smallest.
  // This allows us to use only O(min(n,m)) memory.
  if (n < m) {
    std::swap(upper_seq, lower_seq);
  }

  std::cout << subseq_len(upper_seq, lower_seq) << std::endl;

  return 0;
}
