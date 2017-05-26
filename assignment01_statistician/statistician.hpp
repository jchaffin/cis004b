//
// Created by Jacob Chaffin on 3/13/17.
//

#ifndef ASSIGNMENT01_STATISTICIAN_HPP
#define ASSIGNMENT01_STATISTICIAN_HPP
class statistician {
public:
  /**
   * Constructor for statistician class.
   */
  statistician( );
  
  /**
   * @param r   The number to add to the statistician sequence.
   */
  void next_number(double r);
  
  /**
   * Resets the statistician's private data member values.
   */
  void reset( );
  
  /**
   * @return   The number of values that have been added to this statistician
   *           without or since a method call to reset.
   */
  int length() const;
  
  /**
   * @return  The maximum numerical value in the sequence of values managed by
   *          the statistician.
   */
  double maximum( ) const;
  
  /**
   * @return  The minimum numerical value in the sequence.
   */
  double minimum( ) const;
  
  /**
   * @return  The arithmetic mean of numbers, equivalent to the sum of numbers
   *           managed by the statistician divided by the lenght of the sequence.
   */
  double mean( ) const;
  
  
  /**
   * @return  The most recent number added to the sequence.
   */
  double recent( ) const;
  
  void squawk();
  
  /**
   * @return the sum of all the values in the sequence.
   */
  double sum( ) const;
  
  /**
   * Overloads + operator, creating a new statistician
   * that behaves as if all numbers of s1 and s2 had been
   * added to the statistician.
   * @param s1 the first statistician to add to the new statistician.
   * @param s2 the second statistician to add to the new statistician.
   */
  friend statistician operator +
  (const statistician& s1, const statistician& s2);
  
private:
  int m_len;       // How many numbers in the sequence.
  double m_max;    // The largest number in the sequence.
  double m_min;    // The smallest number in the sequence.
  double m_rec;    // The most recent number given to the sequence.
  double m_sum;    // The sum of all the numbers in the sequence.
};
#endif //ASSIGNMENT01_STATISTICIAN_HPP
