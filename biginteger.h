/*
* Project: Biginteger 
* File: biginteger.h
* Description:
* Developer: Matthew Carlson
* Email: carlsonm137773@student.vvc.edu
* Date created: 03/12/2019
*/

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

class BigInteger
{
public:
   BigInteger();
   BigInteger(std::string num_string);
   BigInteger(std::vector<int> _number);
   
   BigInteger add(BigInteger num);
	BigInteger multi(BigInteger num);
   
   std::string to_string() const;
   std::vector<int> get_vec() const;
	int get_digit(int i) const;
	int get_size() const;
   void print();

private:
   std::vector<int> m_number;
};



#endif

