#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T> class Operation {
private:
  std::function<T(T, T)> action;

public:
  Operation(const std::string &operator_sign) {
    if (operator_sign == "+") {
      action = [](const T &a, const T &b) { return a + b; };
    } else if (operator_sign == "-") {
      action = [](const T &a, const T &b) { return a - b; };
    } else if (operator_sign == "*") {
      action = [](const T &a, const T &b) { return a * b; };
    } else {
      throw std::invalid_argument("Invalid operator symbol");
    }
  }

  T apply(const T &a, const T &b) { return action(a, b); }
};

template <typename T> class Equation {
private:
  std::vector<T> nums;
  std::vector<Operation<T>> ops;

public:
  Equation(const std::string &eqn, const size_t &n) {
    nums = std::vector<T>(n + 1, 0);
    std::string curr_symbol;
    for (std::string::size_type i = 0; i < eqn.size(); ++i) {
      curr_symbol = eqn.substr(i, 1);
      if ((i % 2) == 0) {
        nums[(int)i / 2] = std::stoi(curr_symbol);
      } else {
        ops.push_back(Operation<T>(curr_symbol));
      }
    }
  }

  T evaluate() {
    T ans{nums[0]};

    for (size_t i = 0; i < ops.size(); i++) {
      ans = ops[i].apply(ans, nums[i + 1]);
    }

    return ans;
  }
};

int main() {
  size_t n;
  std::string input;

  std::cin >> n;
  std::cin >> input;

  Equation<int> eq(input, n);

  std::cout << eq.evaluate() << std::endl;
  return 0;
}
