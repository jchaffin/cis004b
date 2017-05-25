/********************************************//**
 *  node_template.hpp - as03 sequence_template
 ***********************************************/

// FILE: node2.template
// IMPLEMENTS: The functions of the node template class and the
// linked list toolkit (see node2.h for documentation).
//
// NOTE:
//   Since node is a template class, this file is included in node2.h.
//   Therefore, we should not put any using directives in this file.
//
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.
#include <stdio.h>
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides nullptr and size_t

template <class T>
void list_clear(node<T>*& head_ptr) {
  while (head_ptr != nullptr) {
    list_head_remove(head_ptr);
  }
}

template <class T>
void list_copy(
  const node<T>* source_ptr,
  node<T>*& head_ptr,
  node<T>*& tail_ptr
) {
  head_ptr = nullptr;
  tail_ptr = nullptr;

  // Handle the case of the empty list
  if (source_ptr == nullptr) {
    return;
  }

  // Make the head node for the newly created list, and put data in it
  list_head_insert(head_ptr, source_ptr->data( ));//insert
  tail_ptr = head_ptr;

  // Copy rest of the nodes one at a time, adding at the tail of new list
  source_ptr = source_ptr->link( );
  while (source_ptr != nullptr) {
    list_insert(tail_ptr, source_ptr->data( ));
    tail_ptr = tail_ptr->link( );
    source_ptr = source_ptr->link( );
  }
}

//insert from the beginning
template <class T>
void list_head_insert(node<T>*& head_ptr, const T& entry) {
  head_ptr = new node<T>(entry, head_ptr);
}
//remove the sequence from the head
template <class T>
void list_head_remove(node<T>*& head_ptr) {
  node<T> *remove_ptr;

  remove_ptr = head_ptr;
  head_ptr = head_ptr->link( );
  delete remove_ptr;
}

template <class T>
void list_insert(node<T>* previous_ptr, const T& entry) {
  node<T> *insert_ptr;

  insert_ptr = new node<T>(entry, previous_ptr->link( ));
  previous_ptr->set_link(insert_ptr);
}

template <class T>
std::size_t list_length(const node<T>* head_ptr)
// Library facilities used: cstdlib
{
  const node<T> *cursor;
  std::size_t answer;

  answer = 0;
  for (cursor = head_ptr; cursor != nullptr; cursor = cursor->link( ))
    ++answer;

  return answer;
}

template <class N, class SizeType>
N list_locate(N head_ptr, SizeType position)
// Library facilities used: cassert, cstdlib
{
  N cursor;
  SizeType i;

  assert(0 < position);
  cursor = head_ptr;
  for (i = 1; (i < position) && (cursor != nullptr); ++i)
    cursor = cursor->link( );
  return cursor;
}

template <class T>
void list_remove(node<T>* previous_ptr) {
  node<T> *remove_ptr;

  remove_ptr = previous_ptr->link( );
  previous_ptr->set_link(remove_ptr->link( ));
  delete remove_ptr;
}

template <class N, class T>
N list_search(N head_ptr, const T& target)
// Library facilities used: cstdlib
{
  N cursor;

  for (cursor = head_ptr; cursor != nullptr; cursor = cursor->link( ))
    if (target == cursor->data( ))
      return cursor;
  return nullptr;
}