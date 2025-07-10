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

template <typename T> void print_vector(const std::vector<T> &vtr) {
  std::cout << "{";
  for (auto it = vtr.begin(); it != vtr.end() - 1; it++) {
    std::cout << *it << ", ";
  }
  std::cout << *(vtr.end() - 1) << "}";
}

template <typename Iter> void print_vector(Iter begin, Iter end) {
  std::cout << "{";
  for (auto it = begin; it != end - 1; it++) {
    std::cout << *it << ", ";
  }
  std::cout << *(end - 1) << "}";
}

template <typename T> class Matrix {
private:
  std::vector<T> data;
  std::vector<size_t> shape;

  size_t get_step_size(const size_t &dim_id) {
    // Step size is the product of sizes of all following matrix dimesions
    size_t ans{1};
    if ((dim_id + 1) != shape.size()) {
      for (auto dim_size = shape.rbegin();
           dim_size != shape.rend() - dim_id - 1; ++dim_size) {
        ans *= *dim_size;
      }
    }
    return ans;
  }

  size_t index(const std::vector<size_t> &coords) {
    // Converts an n-D vector of indices to its 1-D counterpart
    size_t ans = 0, n = coords.size();
    for (size_t i = 0; i < n; i++) {
      ans += coords[i] * get_step_size(i);
    }
    return ans;
  }

  void print(const size_t &dim_id, const size_t &begin) {
    // Recursively prints out the matrix, here `dim_id` is the dimension that is
    // being printed, begin - the index of starting element. begin is calculated
    // as the sum of all steps that were already done. For example:
    //
    // [1, 2, :] in matrix of shape [2, 3, 4] has begin = 2 * 4 + 1 * (3 * 4)
    //     ^
    if ((shape.size() - dim_id - 1) == 0) {

      print_vector(data.begin() + begin, data.begin() + begin + shape.back());

    } else {

      size_t elmts_per_step{get_step_size(dim_id)};

      std::cout << "{";
      for (size_t i = 0; i < shape[dim_id] - 1; i++) {
        print(dim_id + 1, begin + i * elmts_per_step);
        std::cout << ",\n";
      }
      print(dim_id + 1, begin + (shape[dim_id] - 1) * elmts_per_step);
      std::cout << "}";
    }
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

  void print() {
    print(0, 0);
    std::cout << "\n";
  }
};

template <typename T> int solve(const std::vector<T> &booty_values) {
  unsigned int total_booty =
      std::accumulate(booty_values.begin(), booty_values.end(), 0);
  size_t share = total_booty / 3, N = booty_values.size();

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
        if (booty_values[i - 1] <= s1) {
          partitions.set(
              {i, s1, s2},
              partitions.get({i, s1, s2}) ||
                  partitions.get({i - 1, s1 - booty_values[i - 1], s2}));
        }
        if (booty_values[i - 1] <= s2) {
          partitions.set(
              {i, s1, s2},
              partitions.get({i, s1, s2}) ||
                  partitions.get({i - 1, s1, s2 - booty_values[i - 1]}));
        }
      }
    }
  }
  return partitions.get({N, share, share});
}

int main() {

  size_t n;
  std::vector<size_t> booty_values;

  std::cin >> n;
  write_vector(booty_values, n);

  std::cout << solve(booty_values) << "\n";

  // Matrix<int> mtx({1, 2, 3, 4, 5, 6, 7, 8}, {2, 2, 2});
  //
  // mtx.print();
  // std::cout << mtx.get({1, 0, 0}) << std::endl;
  //
  return 0;
}
