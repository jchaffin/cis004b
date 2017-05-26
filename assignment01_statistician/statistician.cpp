//
//  statistician.cpp
//  statistician
//
//  Created by Jacob Chaffin on 3/12/17.
//  Copyright © 2017 Jacob Chaffin. All rights reserved.
//

#include "statistician.hpp"
#include <iostream>
statistician::statistician() {
	m_len = 0;
	m_sum = 0;
	m_max = 0;
	m_min = 0;
}
void statistician::next_number(double r) {
	m_len += 1;
	m_sum += r;
	m_rec = r;
	if (m_len == 1) {
		m_max = r;
		m_min = r;
	}
  else if (r > m_max)
		m_max = r;
	else if (r < m_min)
		m_min = r;
}

void statistician::squawk() {
  std::cout <<  "Largest is: " << m_max << std::endl;
  std::cout <<  "Smallest is: " << m_min << std::endl;
  std::cout <<  "Length is: " << m_len << std::endl;
}

double statistician::minimum() const {
	return m_min;
}

double statistician::maximum() const {
	return m_max;
}

double statistician::sum() const {
	return m_sum;
}

int statistician::length() const {
	return m_len;
}

double statistician::recent() const {
	return m_rec;
}

double statistician::mean() const {
	return (m_sum / m_len);
}

statistician operator +(const statistician& s1, const statistician& s2) {
  statistician s;
  s.m_max = (s1.m_max > s2.m_max) ? s1.m_max : s2.m_max;
  s.m_sum = s1.m_sum + s2.m_sum;
  s.m_min = (s1.m_min < s2.m_min) ? s1.m_min : s2.m_min;
  return s;
}
void statistician::reset() {
	m_len = 0;
	m_max = 0;
	m_min = 0;
  m_rec = 0;
	m_sum = 0;
}

