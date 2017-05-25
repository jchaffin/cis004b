/********************************************//**
 *  node_iterator   -  as03 sequence_template
 ***********************************************/
#include <iostream>
#include <iterator>

template <class T>
class node_iterator : public std::iterator<std::forward_iterator_tag, T> {
 public:
  node_iterator(node<T>* initial = NULL);
  T& operator *() const;
  node_iterator<T>& operator ++();
  node<T>* operator &() const;
  node_iterator<T> operator ++(int);
  bool operator ==(const node_iterator other) const;
  bool operator != (const node_iterator other) const;
//   bool operator != (const node<T> &other) const;
  bool has_next();

 private:
  node<T>* current;
};

template<class T>
node_iterator<T>::node_iterator(node<T>* initial) {
  current = initial;
}

template<class T>
node<T>* node_iterator<T>::operator &() const {
  return current;
}


template <class T>
T& node_iterator<T>::operator *() const {
  return current->data();
}

template <class T>
node_iterator<T>& node_iterator<T>::operator ++() {
  current = current->link();
  return *this;
}

template <class T>
node_iterator<T> node_iterator<T>::operator++(int) {
  node_iterator original(current);
  current = current->link();
  return original;
}

template <class T>
bool node_iterator<T>::operator ==(const node_iterator other) const {
  return (current == other.current);
}

template <class T>
bool node_iterator<T>::operator != (const node_iterator other) const {
  return (current != other.current);
}

//template <class T>
//bool node_iterator<T>::operator !=(const node<T> &other) const {
//  return (current->data() != other->data());
//}

template <class T>
bool node_iterator<T>::has_next()  {
  return (current->link() != NULL || current->link() != nullptr);
}
