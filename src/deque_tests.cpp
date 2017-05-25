/********************************************//**
 * deque_tests.cpp - cis004b_assignment04_deque
 ***********************************************/
#include "../include/deque.hpp"

int main(int argc, const char * argv[]) {
  deque<int> d;
  d.add_front(5);
  d.add_front(10);
  std::cout <<  d.remove_front() << std::endl;
  std::cout <<  d.remove_front() << std::endl;
  d.add_rear(20);
  std::cout <<  d.remove_front() << std::endl;
  return 0;
}




/* UNIT TESTS HERE */


