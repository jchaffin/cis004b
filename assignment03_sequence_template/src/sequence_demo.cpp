/********************************************//**
 *  sequence_demo.cpp - sequence_template
 ***********************************************/

#include <iostream>
#include "../include/sequence.hpp"

int main(int argc, const char * argv[]) {
  sequence<int> *test = new sequence<int>();
  test->insert(30);
  test->insert(10);
  test->insert(20); // 20 10 30
  test->remove_current(); // 10 30
  test->remove_current(); // 30
  test->attach(40); // 30 40
  test->attach(50); // 30 40 50
  test->advance(); // cursor falls off
  test->print();
  test->start();
  std::cout <<  "Expecting cursor to be at the head_ptr, 30" << std::endl;
  assert(test->current() == 30);
  std::cout <<  "Passed" << std::endl;
  std::cout <<  "Removing current, so sequence should now be 40 50" << std::endl;
  test->remove_current();
  assert(test->current() == 40);
  test->advance();
  assert(test->current() == 50);
  std::cout <<  "Passed" << std::endl;
  test->attach(100); // 40 50 100
  test->attach(120); // 40 50 100 120
  test->attach(140); // 40 50 100 120 140
  test->start();
  test->advance();
  test->advance();
  test->remove_current();
  std::cout <<  "Advancing cursor to 100, call it sequence[2], then removing." <<
            "So cursor should become 50, precursor should be 40," <<
            "and 100 should be removed from the sequence." << std::endl;
  assert(test->current() == 50);
  std::cout <<  "Passed" << std::endl;
  return 0;
}
