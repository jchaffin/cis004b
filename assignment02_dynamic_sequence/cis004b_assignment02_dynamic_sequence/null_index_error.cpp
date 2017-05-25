//
//  null_index_error.cpp
//  cis004b_assignment02_dynamic_sequence
//
//  Created by Jacob Chaffin on 3/14/17.
//  Copyright © 2017 Jacob Chaffin. All rights reserved.
//

#include "null_index_error.hpp"
null_index_error::null_index_error(const std::string& msg)  : std::runtime_error(msg){
  m_msg = msg;
}
null_index_error::null_index_error() : null_index_error("Invalid current index operation."){};

null_index_error::~null_index_error() throw() {};

const char* null_index_error::what() const throw() {
  return std::runtime_error::what();
};
