#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>

template <typename T> class List {
private:
  struct Node {
    T data;
    std::unique_ptr<Node> next;
  };

  std::unique_ptr<Node> front;
  size_t list_size{0};

public:
  void push_front(const T &data) {
    front = std::make_unique<Node>(data, std::move(front));
    list_size++;
  }

  void push_by_idx(const T &data, const size_t &idx) {
    if (idx > list_size) {
      throw std::invalid_argument("Invalid item index");
    } else if (idx == 0) {
      push_front(data);
    } else {
      Node *head = front.get();
      for (size_t i = 1; i < idx; i++) {
        head = head->next.get();
      }
      head->next = std::make_unique<Node>(data, std::move(head->next));
      list_size++;
    }
  }

  void push_back(const T &data) { push_by_idx(data, list_size); }

  T pop_front() {
    if (front == nullptr) {
      throw std::invalid_argument("Unable to pop: list is empty");
    }

    T ans = front->data;
    front = std::move(front->next);
    list_size--;
    return ans;
  }

  T pop_by_idx(const size_t &idx) {
    if (front == nullptr) {
      throw std::invalid_argument("Unable to pop: list is empty");
    }
    if (idx > list_size) {
      throw std::invalid_argument("Unable to pop: index outside list range");
    }
    if (idx == 1) {
      return pop_front();
    }

    T ans = front->data;
    Node *head = front.get();

    for (size_t i = 2; i < idx; i++) {
      head = head->next.get();
    }

    if (idx == list_size) {
      head->next.reset(nullptr);
    } else {
      head->next = std::move(head->next->next);
    }
    list_size--;
    return ans;
  }

  T operator[](const size_t &idx) {
    if (idx > list_size) {
      throw std::invalid_argument("Invalid item index");
    } else {
      Node *head = front.get();
      for (size_t i = 1; i < idx; i++) {
        head = head->next.get();
      }
      return head->data;
    }
  }

  friend std::ostream &operator<<(std::ostream &os, const List &list) {
    Node *head = list.front.get();
    while (head) {
      os << head->data << ' ';
      head = head->next.get();
    }
    return os;
  }

  size_t size() { return list_size; }

  bool is_empty() { return front == nullptr; }

  ~List() {
    while (!is_empty()) {
      pop_front();
    }
  }
};

enum class List_Operations : unsigned int { add = 1, display = 2, remove = 3 };

void process_input(const size_t &n) {
  List<int> lst, display_lst;
  size_t arg1, arg2, operation_code;
  List_Operations operation;

  for (size_t i = 0; i < n; i++) {
    std::cin >> operation_code;
    operation = static_cast<List_Operations>(operation_code);

    switch (operation) {
    case List_Operations::add:
      std::cin >> arg1 >> arg2;
      lst.push_by_idx(arg2, arg1);
      break;
    case List_Operations::display:
      std::cin >> arg1;
      display_lst.push_back(lst[arg1]);
      break;
    case List_Operations::remove:
      std::cin >> arg1;
      lst.pop_by_idx(arg1);
      break;
    default:
      throw std::invalid_argument("Invalid operation code");
    };

    // std::cout << "Current list: " << lst << "\n";
  }

  std::cout << display_lst << "\n";
}

int main() {
  size_t n;
  std::cin >> n;

  process_input(n);

  return 0;
}
