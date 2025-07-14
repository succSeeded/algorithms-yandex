// Отпишите пж если у вас получилось уложиться во 1 секунду с использованием
// лишь Листа
#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T> class List {
private:
  struct Node {
    T data;
    Node *next = nullptr;

    Node() : data{0}, next{nullptr} {};
    Node(const T &in_data) : data{in_data}, next{nullptr} {};
    ~Node() {};
  };

  Node *front = nullptr;
  Node *back = nullptr;
  size_t list_size{0};

public:
  List() {
    front = new Node();
    back = new Node();
    front->next = back;
    back->next = nullptr;
    list_size = 0;
  };

  struct Iterator {
  private:
    Node *ptr = nullptr;

  public:
    Iterator(Node *other_ptr) : ptr(other_ptr) {};
    Iterator(const Iterator &other) : ptr(other.ptr) {};

    T &operator*() {
      if (ptr != nullptr) {
        return ptr->data;
      } else {
        throw std::invalid_argument(
            "Attempted dereferencing of an iterator at nullptr");
      }
    }

    Iterator &operator++() {
      if (ptr != nullptr) {
        ptr = ptr->next;
        return *this;
      } else {
        throw std::invalid_argument(
            "Attempted dereferencing of an iterator at nullptr");
      }
    }

    Iterator &operator++(int) {
      if (ptr != nullptr) {
        ptr = ptr->next;
        return *this;
      } else {
        throw std::invalid_argument(
            "Attempted dereferencing of an iterator at nullptr");
      }
    }

    bool operator==(const Iterator &other) const { return ptr == other.ptr; }

    bool operator!=(const Iterator &other) const { return ptr != other.ptr; }

    Node *get() { return ptr; }
  };

  Iterator begin() { return ++Iterator(front); }
  Iterator end() { return Iterator(back); }

  void push_front(const T &in_data) {
    Node *new_item = new Node(in_data);
    new_item->next = front->next;
    front->next = new_item;
    list_size++;
  }

  void push_by_idx(const T &in_data, const size_t &idx) {
    if (idx > list_size) {
      throw std::out_of_range("Push index out of list range");
    }
    if (idx == 0) {
      push_front(in_data);
    } else {
      Node *new_item = new Node(in_data);
      Node *head{front->next};
      for (size_t i = 1; i < idx; i++) {
        head = head->next;
      }
      new_item->next = head->next;
      head->next = new_item;
      list_size++;
    }
  }

  void push_back(const T &in_data) { push_by_idx(in_data, list_size); }

  T pop_front() {
    Node *head{front};
    T ans{front->data};
    front = front->next;
    delete head;
    return ans;
  }

  T pop_by_idx(const size_t &idx) {
    if ((idx > list_size) || (idx == 0)) {
      throw std::out_of_range("Push index out of list range");
    }
    if (idx == 1) {
      return pop_front();
    }
    Node *head{front->next}, *pop_node{front->next};
    for (size_t i = 2; i < idx; i++) {
      head = head->next;
    }
    pop_node = head->next;
    head->next = pop_node->next;
    T ans{pop_node->data};
    delete pop_node;
    return ans;
  }

  T pop_back() { return pop_by_idx(list_size); }

  ~List() {
    Node *head;
    list_size = 0;

    while (front != nullptr) {
      head = front;
      front = front->next;
      delete head;
    }
  }

  size_t size() { return list_size; }

  T operator[](const size_t &idx) {
    if (idx > list_size) {
      throw std::invalid_argument("Invalid item index");
    } else {
      Node *head = front->next;
      for (size_t i = 1; i < idx; i++) {
        head = head->next;
      }
      return head->data;
    }
  }

  friend std::ostream &operator<<(std::ostream &os, const List &list) {
    Node *head = list.front->next;
    while (head->next != nullptr) {
      os << head->data << ' ';
      head = head->next;
    }
    return os;
  }

  T test() { return back->data; }
};

template <typename T> void find_min_pair(List<T> &lst) {
  size_t left_idx{1}, right_idx{2}, new_left_idx{1}, i{2};
  T left_item{lst[left_idx]}, right_item{lst[right_idx]},
      new_left_item{lst[new_left_idx]};

  for (auto iter = ++lst.begin(); iter != lst.end(); iter++) {
    if (new_left_item - *iter < left_item - right_item) {
      right_idx = i;
      right_item = *iter;
      left_idx = new_left_idx;
      left_item = new_left_item;
    }
    if ((*iter < left_item) && (*iter < new_left_item)) {
      new_left_idx = i;
      new_left_item = *iter;
    }
    i++;
  }

  std::cout << left_idx << " " << right_idx << "\n";
}

template <typename T> void find_max_pair(List<T> &lst) {
  size_t left_idx{1}, right_idx{2}, new_left_idx{1}, i{2};
  T left_item{lst[left_idx]}, right_item{lst[right_idx]},
      new_left_item{lst[new_left_idx]};

  for (auto iter = ++lst.begin(); iter != lst.end(); iter++) {
    if (new_left_item - *iter > left_item - right_item) {
      right_idx = i;
      right_item = *iter;
      left_idx = new_left_idx;
      left_item = new_left_item;
    }
    if ((*iter > left_item) && (*iter > new_left_item)) {
      new_left_idx = i;
      new_left_item = *iter;
    }
    i++;
  }

  std::cout << left_idx << " " << right_idx << "\n";
}

void solve(const size_t &n) {
  List<int> lst;
  int value_in;

  for (size_t i = 0; i < n; i++) {
    std::cin >> value_in;
    lst.push_back(value_in);
  }

  find_min_pair(lst);
  find_max_pair(lst);
}

int main() {
  size_t n;
  std::cin >> n;

  solve(n);
}
