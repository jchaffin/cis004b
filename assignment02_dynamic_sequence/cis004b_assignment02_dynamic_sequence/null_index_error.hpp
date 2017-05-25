//
//  null_index_error.hpp
//  cis004b_assignment02_dynamic_sequence
//
//  Created by Jacob Chaffin on 3/14/17.
//  Copyright © 2017 Jacob Chaffin. All rights reserved.
//

#ifndef null_index_error_hpp
#define null_index_error_hpp

#include <stdio.h>
#include <stdexcept>
#include <string>
#include <iostream>
using re = std::runtime_error;
class null_index_error : public re {
 private:
  std::string m_msg;

 public:
  explicit null_index_error(const std::string& msg);
  explicit null_index_error();
  virtual ~null_index_error() throw();
  virtual const char* what() const throw();
  
};
#endif /* null_index_error_hpp */
