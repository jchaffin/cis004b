/********************************************//**
*  sequence.hpp - Assignment02 - dynamic_sequence
***********************************************/
#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP
#include <iostream>
#include <string>
#include "null_index_error.hpp"
#include <cstdlib>
/**
 * value type is the data type of the items in the sequence.
 * It may be any of the C++ built-in types, or a class with a default
 * constructor, an assignment operator, or a copy constructor.
 * We are using a char to test our methods against an array representing
 * the English alphabet in sequence_test.cpp.
 *
 */
using value_type = char;
/**
 * size_type is the data type of any variable that keeps track of how many items
 * are in a sequence.
 */
using size_type = std::size_t;


class sequence {
  /**
   * The default capacity of the sequence. The sequence object
   * is initialized to this value if an argument is not passed to the
   * explicit constructor.
   */
 public:
  static const size_type DEFAULT_CAPACITY = 30;
  /**
   * sequence constructor
   * Initializes an empty sequence.
   */
  sequence();

  sequence(size_type initial_capacity);
  /**
   * Copy constructor.
   */
  sequence(sequence& source);

  /**
   * sequence destructor.
   */
  ~sequence();

  /**
   * If the sequence is empty , there is no current item. Else the first
   * item in the sequence becomes the current item.
   */
  void start();
  
  /**
   * If is_item is true, then if current_index == used - 1, then there is no
   * longer any current item. Else, if current_index < used - 1, then
   * the current_item is now the next item in the sequence.
   */
  void advance() ;
  
  /**
   * Returns the current_index in the sequence, if there is one.
   */
  value_type current() const;
  
  /**
   * Inserts the given item before the current_index, or at index 0 if there
   * is no current item. Either way, the current_index is now at the
   * index of the given item.
   */
  void insert(const value_type& entry);
  
  /**
   * Attaches the given item after the element at current_index. If
   * there is no current_item then the entry is now at index 0. Either way,
   * the current_index is now at the position of the given entry.
   */
  void attach(const value_type& entry);

  void squawk() const;
  
  /**
   * Removes the current item in the sequence, if there is one.
   */
  void remove_current();
  
  void remove_current2();

  /**
   * Increases the capacity of the sequence by the size of new_capacity.
   * If new_capacity is less then capacity, then the size of the sequence
   * remains the same.
   */
  void reserve(size_type new_capacity);
  
  void reserve();

  friend sequence operator+(const sequence& s1,  const sequence& s2);

  void operator +=(const sequence& addend);
  
  void operator =(const sequence& source);

  size_type size() const;

  bool is_item() const;

  void print() const;

 private:
  value_type *data;
  size_type used;
  size_type capacity;
  size_type current_index;
};

#endif // SEQUENCE_HPP
