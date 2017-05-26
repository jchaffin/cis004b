//
//  main.cpp
//  statistician
//
//  Created by Jacob Chaffin on 3/12/17.
//  Copyright © 2017 Jacob Chaffin. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include "statistician.hpp"

int main(int argc, const char * argv[]) {
	statistician s1;
  double a = 5.4;
  double b = 2.3;
  double c = -12.3;
  double d = 1.34;
  s1.next_number(a);
  s1.squawk();
  s1.next_number(b);
  s1.squawk();
  assert(s1.sum() == a + b);
  s1.next_number(c);
  assert(s1.sum() == a + b + c);
  s1.squawk();
  assert(s1.minimum() == c);
  assert(s1.maximum() == a);
  s1.squawk();
  s1.reset();
  assert(s1.sum() == 0);
  s1.next_number(d);
  s1.squawk();
  statistician s2;
  s2.next_number(c);
  s2.next_number(a);
  statistician s3 = s1 + s2;
  assert(s3.sum() == s1.sum() + s2.sum());
  assert(s3.minimum() == (s1.minimum() < s2.minimum()) ? s1.minimum() : s2.minimum());
  assert(s3.maximum() == (s1.maximum() < s2.maximum()) ? s1.maximum() : s2.maximum());
	return 0;
}
