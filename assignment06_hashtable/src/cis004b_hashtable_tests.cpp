/********************************************//**
 * cis004b_hashtable_test.cpp - HashTable
 ***********************************************/
#include <iostream>
#include <string>
#include "../include/cis004b_hashtable.hpp"


struct data_record{
    int key ;
    std::string name ;
};

void say_found(bool &found) {
  found = true;
}
void found_test() {
  bool found;
  say_found(found);
  if (found) {
    std::cout <<  "Found is true" << std::endl;
  } else {
    std::cout <<  "Found is false" << std::endl;
  }
}

typedef struct data_record Data ;
int main(int argc, const char *argv[]) {
  // Data d ;
  // d.key= 1;
  // d.name = "Jeevan" ;
  // Data d2 = {2, "Jacob"};
  // Data d3 = {3, "George"} ;
  // Data d4 = {4, "Alex"} ;
  // Data d5 = {5, "Shiva"} ;
  found_test();
  // table<data_record> my_table ;
  // my_table.insert(d) ;
  // my_table.insert(d3) ;
  // my_table.insert(d4) ;
  // my_table.insert(d2) ;
  // my_table.insert(d5) ;

  // Data d_out ;
  // bool found ;
  
  // my_table.find(1, found, d_out); 
  // std::cout << d_out.name  << std::endl ;
  // my_table.find(3,found, d_out) ;
  // std::cout << d_out.name  << std::endl ;
 
}