#include "sequence.hpp"

int main(int argc, const char * argv []) {
  sequence s1(10);
  s1.insert('D');
  s1.insert('C');
  s1.insert('B');
  s1.insert('A');
  s1.remove_current2();
  s1.print();
}
