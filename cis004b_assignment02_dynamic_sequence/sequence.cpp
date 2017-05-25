//
//  sequence.cpp
//  cis004b_assignment02_dynamic_sequence
//
//  Created by Jacob Chaffin on 3/13/17.
//  Copyright © 2017 Jacob Chaffin. All rights reserved.
//

#include "sequence.hpp"
#include <assert.h>
#include <memory>
#include <algorithm>

sequence::sequence(size_type initial_capacity) : capacity(initial_capacity) {
  used = 0;
  current_index = 0;
  data = new value_type[initial_capacity];
}

sequence::sequence() : sequence(DEFAULT_CAPACITY) {};

sequence::sequence(sequence& source) {
  capacity = source.capacity;
  data = new value_type(capacity);
  used = source.used;
  for (int i = 0; i < source.used; i++) {
    data[i] = source.data[i];
  }
}

sequence::~sequence() {
  delete [] data;
}

void sequence::reserve(size_type new_capacity) {
  value_type *tmp;
  if (new_capacity <= capacity)
    new_capacity = capacity;
  tmp = new value_type[capacity];
  for (int i = 0; i < used; i++) {
    tmp[i] = data[i];
  }
  delete [] data;
  data = tmp;
  capacity = new_capacity;
}

void sequence::reserve() {
  reserve(used * 2 +  1);
}

bool sequence::is_item() const {
  return (current_index < used && used > 0);
}

void sequence::insert(const value_type& entry) {
  size_type i;
  if (size() == capacity) {
    reserve();
  }
  if (!is_item())
    start();
  for (i = used;  i > current_index; --i) {
    data[i] = data[i - 1];
  }
  data[current_index] = entry;
  ++used;
}

void sequence::advance() {
  current_index += 1;
}

void sequence::start() {
  current_index = 0;
}

size_type sequence::size() const {
  return used;
}

value_type sequence::current() const {
  if (is_item())
    return data[current_index];
  else
    throw null_index_error();
}

void sequence::attach(const value_type &entry) {
  size_type i;
  if (size() == capacity) {
      reserve();
  }
  if (current_index == 0 && used == 0) {
    current_index = -1;
  }
  for (i = used; i > current_index + 1; i--) {
    data[i] = data[i - 1];
  }
  data[current_index + 1] = entry;
  ++current_index;
  ++used;
};

void sequence::remove_current() {
  if (is_item()) {
    for (size_type i = current_index; i < used; i++) {
      data[i] = data[i + 1];
    }
    used--;
  }
}

void sequence::remove_current2() {
  size_type i;
  assert(is_item());
  for (i = current_index + 1; i < used; i ++) {
    std::cout <<  data[i - 1] << " becomes " << data[i] << std::endl;
    data[i - 1] = data[i];
  }
  used--;
}
  
void sequence::operator +=(const sequence& addend) {
  size_type i;
  if (used + addend.used >= capacity)
    reserve(used + addend.used);

  for (i = 0; i < addend.used; i++) {
    data[used] = addend.data[i];
    used++;
  }
}

void sequence::operator =(const sequence& source) {
  value_type *new_data;
  if (this == &source)
    return;
  if (capacity != source.capacity) {
    capacity = source.capacity;
    new_data = new value_type[source.capacity];
    delete [] data;
    data = new_data;
  }
  used = source.used;
  for (size_type i = 0; i < source.used; i++)
    data[i] = source.data[i];
}

sequence operator +(const sequence& s1, const sequence& s2) {
  sequence s(s1.size() + s2.size());
  s += s1;
  s += s2;
  return s;
}


void sequence::squawk() const {
  std::cout << "Current used is: " << used << std::endl;
  std::cout << "Current capacity is: " << capacity << std::endl;
  std::cout << "Current index is: " << current_index << std::endl;
  std::cout << "Current value at index is: " << data[current_index] << std::endl << '\n' << std::endl;
}

void sequence::print() const {
  size_type i;
  if (is_item()) {
    for (i = 0; i < used; i++) {
      std::cout <<  data[i] << std::endl;
    }
  }
}


