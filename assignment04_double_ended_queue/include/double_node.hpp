/********************************************//**
 * double_node.hpp - cis004b_assignment04_deque
 ***********************************************/
#ifndef DOUBLE_NODE_HPP
#define DOUBLE_NODE_HPP

#include <cstdlib>
#include <cassert>
#include <iostream>

template <class T>
class double_node {
 public:
  using value_type = T;

  // Constructor
  double_node(const T& init_data, double_node* init_link_left, double_node* init_link_right);

  T& data();

  double_node<T>* get_link_right();

  double_node<T>* get_link_left();

  void set_data(const T& new_data);

  void set_link_left(double_node<T>* new_link);

  void set_link_right(double_node<T>* new_link);

 private:
  T data_field;
  double_node<T> *link_left, *link_right;
};

template<class T>
double_node<T>::double_node(
  const T& init_data,
  double_node<T>* init_link_left,
  double_node<T>* init_link_right
) {
  data_field = init_data;
  link_left = init_link_left;
  link_right = init_link_right;
}

template <class T>
T& double_node<T>::data() {
  return data_field;
}

template <class T>
double_node<T>* double_node<T>::get_link_right() {
  return link_right;
}

template <class T>
double_node<T>* double_node<T>::get_link_left() {
  return link_left;
}

template <class T>
void double_node<T>::set_data(const T& new_data) {
  data_field = new_data;
}

template <class T>
void double_node<T>::set_link_left(double_node<T>* new_link) {
  link_left = new_link;
}

template <class T>
void double_node<T>::set_link_right(double_node<T>* new_link) {
  link_right = new_link;
}

#endif /* DOUBLE_NODE_HPP */