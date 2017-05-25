/********************************************//**
 * deque.hpp   -  cis004b_assignment04_deque
 ***********************************************/

/**
 * Linked-list implementation of a double-ended dequeue.
 */

#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <cstdlib>
#include <cassert>
#include <iostream>
#include "double_node.hpp"

template <class T>
class deque {
 public:
  using size_type = std::size_t;
  using value_type = T;

  // Constructor
  deque();

  void add_front(T entry);

  T peek_front();
  T peek_back();

  void add_rear(T entry);

  T remove_front();

  T remove_rear();

  bool empty();

 private:
  size_type count;
  double_node<T> *front_ptr, *rear_ptr;
};


template <class T>
deque<T>::deque() {
  front_ptr = rear_ptr = nullptr;
  count = 0;
}

template<class T>
deque<T>::peek_front() {
  return front_ptr;
}

template <class T>
void deque<T>::add_front(T entry) {
  if (front_ptr == nullptr) {
    front_ptr = new double_node<T>(entry, nullptr, nullptr);
    rear_ptr = front_ptr;
  } else {
    assert(!empty());
    double_node<T>* temp_ptr = new double_node<T>(entry, nullptr, front_ptr);
    front_ptr->set_link_left(temp_ptr);
    front_ptr = temp_ptr;
  }
  ++count;
}

template <class T>
void deque<T>::add_rear(T entry) {
  if (front_ptr == nullptr) {
    front_ptr = new double_node<T>(entry, nullptr, nullptr);
    rear_ptr = front_ptr;
  } else {
    assert(!empty());
    double_node<T>* temp_ptr = new double_node<T>(entry, rear_ptr, nullptr);
    rear_ptr->set_link_right(temp_ptr);
    rear_ptr = temp_ptr;
  }
  ++count;
}

template <class T>
T deque<T>::remove_front() {
  T entry;
  assert(!empty());
  entry = front_ptr->data();
  double_node<T>* temp_ptr = front_ptr;
  front_ptr = front_ptr->get_link_right();
  delete temp_ptr;
  --count;
  if (front_ptr == nullptr) {
    rear_ptr = nullptr;
  }
  if (front_ptr != nullptr) {
    front_ptr->set_link_left(nullptr);
  }
  return entry;
}


template <class T>
T deque<T>::remove_rear() {
  T entry;
  assert(!empty());
  entry = rear_ptr->data();
  double_node<T>* temp_ptr = rear_ptr;
  rear_ptr = rear_ptr->get_link_left();
  delete temp_ptr;
  count--;
  if (rear_ptr == nullptr) {
    front_ptr = nullptr;
  } else {
    rear_ptr->set_link_right(nullptr);
  }
  return entry;
}

template <class T>
bool deque<T>::empty() {
  return (count == 0);
}

#endif /* DEQUE_HPP */