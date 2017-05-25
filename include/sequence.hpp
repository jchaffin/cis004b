/********************************************//**
 *  sequence.hpp  -   as03 sequence_template
 ***********************************************/
#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include "node.hpp"
#include <iostream>
#include <string>

using size_type = std::size_t;

template <class T>
class sequence;

template <class T>
sequence<T> operator +(const sequence<T>& s1, const sequence<T>& s2);

template <class T>
class sequence {
 public:

  sequence();   // default constructor

  sequence(const sequence& source);   // copy constructor

  ~sequence();  // destructor

  void start();

  void advance();

  bool is_item() const;

  T current() const;

  void remove_current();

  void attach(const T& entry);

  void insert(const T& entry);

  friend sequence<T> operator + <> (const sequence<T>& s1, const sequence<T>& s2);

  void operator += (const sequence<T>& addend);

  void operator =(const sequence<T>& source);

  void print();

  size_type size() const;

  void squawk();

 private:
  node<T> *head_ptr, *tail_ptr, *cursor, *precursor;
  size_type num_entries;
};

template <class T>
sequence<T>::sequence() {
  head_ptr = tail_ptr = cursor = precursor = nullptr;
  num_entries = 0;
}

template <class T>
sequence<T>::sequence(const sequence& source) {
  list_copy(source.head_ptr, head_ptr, tail_ptr);
  num_entries = source.num_entries;
}

template <class T>
sequence<T>::~sequence() {
  list_clear(head_ptr);
}

template <class T>
void sequence<T>::start() {
  if (head_ptr != nullptr) {
    cursor = head_ptr;
  }
  precursor = nullptr;
}


template <class T>
void sequence<T>::advance() {
  if (cursor != nullptr && cursor->link() != nullptr ) {
    precursor = cursor;
    cursor = cursor->link();
  } else {
    cursor = precursor = nullptr;
  }
}

template <class T>
bool sequence<T>::is_item() const {
  return (cursor != nullptr);
}

template <class T>
T sequence<T>::current() const {
  return cursor->data();
}

template <class T>
void sequence<T>::remove_current() {
  assert(is_item());
  node<T>* tmp_ptr = new node<T>(T(), nullptr);
  if (cursor->link() == nullptr) {
    if (precursor == nullptr) {
      tmp_ptr = cursor;
      start();
    } else {
      node<T>* iter_cursor = nullptr;
      for (iter_cursor = head_ptr; iter_cursor->link() != precursor; iter_cursor->link()) {
        iter_cursor = iter_cursor->link();
      }
      tmp_ptr = cursor;
      cursor = precursor;
      cursor->set_link(nullptr);
      precursor = iter_cursor;
      precursor->set_link(cursor);
      tail_ptr = cursor;
    }
  } else if (cursor == head_ptr) {
    tmp_ptr = cursor;
    cursor = cursor->link();
    precursor = nullptr;
    head_ptr = cursor;
  } else {
    tmp_ptr = cursor;

    node<T>* iter_cursor = nullptr;
    for (iter_cursor = head_ptr; iter_cursor->link() != precursor; iter_cursor->link()) {
      iter_cursor = iter_cursor->link();
    }
    cursor = precursor;
    precursor = iter_cursor;
    cursor->set_link(tmp_ptr->link());
  }
  delete tmp_ptr;
  --num_entries;
}

template <class T>
void sequence<T>::attach(const T& entry) {
  if (head_ptr == nullptr) {
    head_ptr = new node<T>(entry, head_ptr);
    tail_ptr = head_ptr;
    cursor = head_ptr;
    precursor = nullptr;
  } else if (is_item() && cursor != tail_ptr) {
    cursor->set_link(new node<T>(entry, cursor->link()));
    precursor = cursor;
    cursor = cursor->link();
  } else {
    tail_ptr->set_link(new node<T>(entry, nullptr));
    precursor = tail_ptr;
    tail_ptr = tail_ptr->link();
    cursor = tail_ptr;
  }
  ++num_entries;
}

template<class T>
void sequence<T>::insert(const T& entry) {
  if (head_ptr == nullptr) {
    head_ptr = new node<T>(entry, head_ptr);
    tail_ptr = head_ptr;
    cursor = head_ptr;
    precursor = nullptr;
  } else if (is_item() && cursor != head_ptr) {
    cursor = new node<T>(entry, cursor);
    precursor->set_link(cursor);
  } else {
    head_ptr = new node<T>(entry, head_ptr);
    cursor = head_ptr;
    precursor = nullptr;
  }
  num_entries++;
}

template <class T>
sequence<T> operator+(const sequence<T>& s1, const sequence<T>& s2) {
  sequence<T> answer;
  answer += s1;
  answer += s2;
  return answer;
}

template <class T>
void sequence<T>::operator +=(const sequence<T>& addend) {
  node<T> *copy_head_ptr;
  node<T> *copy_tail_ptr;

  if (addend.num_entries > 0) {
    list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
    copy_tail_ptr->set_link(head_ptr);
    head_ptr = copy_head_ptr;
    num_entries += addend.num_entries;
  }
}

template <class T>
void sequence<T>::operator =(const sequence<T> &source) {
  if (this == &source) {
    return;
  }
  list_clear(head_ptr);
  num_entries = 0;
  list_copy(source.head_ptr, head_ptr, tail_ptr);
  num_entries = source.num_entries;
}

template <class T>
size_type sequence<T>::size() const {
  return num_entries;
}

template <class T>
void sequence<T>::print() {
  for (node<T>* iter = head_ptr; iter != nullptr; iter = iter->link()) {
    std::cout << iter->data() << std::endl;
  }
  std::cout << "\n" << std::endl;
};


template<class T>
void sequence<T>::squawk() {
  node<T>* d_mem[] = {head_ptr, tail_ptr, cursor, precursor};
  std::string s_mem[] = {"head_ptr", "tail_ptr", "cursor", "precursor"};
  std::cout << "\n" << std::endl;
  for (int i = 0; i < sizeof(d_mem) / sizeof(d_mem[0]); i++) {
    if (d_mem[i] == nullptr) {
      std::cout << s_mem[i] << " is nullptr" << std::endl;
    } else {
      std::cout << s_mem[i] << " is " << d_mem[i]->data() << std::endl;
    }
  }
  std::cout << "\n\n" << std::endl;
}

#endif /* SEQUENCE_HPP */
