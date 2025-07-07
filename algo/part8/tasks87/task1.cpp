#include <cstddef>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <vector>

template <typename T> void write_vector(std::vector<T> &vtr, const size_t &n) {
  T input;
  for (size_t i = 0; i < n; i++) {
    std::cin >> input;
    vtr.push_back(input);
  }
}

template <typename T> class Matrix {
private:
  std::vector<T> data;
  std::vector<size_t> shape;

  size_t index(const std::vector<size_t> &coords) {
    size_t ans = 0, n = coords.size();
    for (size_t i = 0; i < n - 1; i++) {
      ans += coords[i] * shape[i + 1];
    }
    ans += coords[n - 1];
    return ans;
  }

public:
  Matrix(const std::vector<T> &other)
      : data(other), shape({other.size(), 1}) {};
  Matrix(const std::vector<T> &other, const std::vector<size_t> &other_shape)
      : data(other), shape(other_shape) {};

  T get(const std::vector<size_t> &coords) { return data[index(coords)]; }

  void set(const std::vector<size_t> &coords, const T &other_val) {
    data[index(coords)] = other_val;
  }

  void reshape(const std::vector<size_t> &other_shape) {
    size_t acc_size{1};
    for (auto dim : other_shape) {
      acc_size *= dim;
    }

    if (acc_size == data.size()) {
      shape = other_shape;
    } else {
      throw std::invalid_argument("Invalid new shape");
    }
  }
};

template <typename T>
int solve(const std::vector<T> &booty_values, const T &N) {
  unsigned int total_booty =
      std::accumulate(booty_values.begin(), booty_values.end(), 0);
  size_t share = total_booty / 3;

  if (total_booty % 3) {
    return false;
  }

  Matrix<bool> partitions(
      std::vector<bool>((N + 1) * (share + 1) * (share + 1), false));
  partitions.reshape({N + 1, share + 1, share + 1});
  partitions.set({0, 0, 0}, true);

  for (unsigned int i = 1; i < (N + 1); i++) {
    for (unsigned int s1 = 0; s1 < (share + 1); s1++) {
      for (unsigned int s2 = 0; s2 < (share + 1); s2++) {
        partitions.set({i, s1, s2}, partitions.get({i - 1, s1, s2}));
        if (booty_values[i] <= s1) {
          partitions.set({i, s1, s2},
                         partitions.get({i, s1, s2}) ||
                             partitions.get({i - 1, s1 - booty_values[i], s2}));
        }
        if (booty_values[i] <= s2) {
          partitions.set({i, s1, s2},
                         partitions.get({i, s1, s2}) ||
                             partitions.get({i - 1, s1, s2 - booty_values[i]}));
        }
      }
    }
  }
  return partitions.get({N, share, share});
}

int main() {

  size_t n;
  std::vector<size_t> booty_values(1, 0);

  std::cin >> n;
  write_vector(booty_values, n);

  std::cout << solve(booty_values, n) << "\n";

  return 0;
}
