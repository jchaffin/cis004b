/********************************************//**
 *  node.hpp  -   as03 sequence_template
 ***********************************************/
#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <cassert>

template <class T>
class node {
 public:
  node(const T& init_data = T(), node* init_link = nullptr);

  T& data();

  node<T>* link();

  void set_data(const T& new_data);

  void set_link(node* new_link);

  const T& data() const {
    return data_field;
  };

  const node* link() const {
    return link_field;
  }

 private:
  T data_field;
  node<T> * link_field;
};


template <class T>
node<T>::node(const T& init_data, node* init_link) {
  data_field = init_data;
  link_field = init_link;
}

template <class T>
T& node<T>::data()  {
  return data_field;
}

template <class T>
node<T>* node<T>::link() {
  return link_field;
}

template <class T>
void node<T>::set_data(const T& new_data) {
  data_field = new_data;
}

template <class T>
void node<T>::set_link(node<T>* new_link) {
  link_field = new_link;
}

#include "node_template.hpp"
#include "node_iterator.hpp"
#endif // NODE_HPP
