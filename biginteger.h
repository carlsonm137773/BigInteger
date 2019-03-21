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

	void change_sign();
	

	BigInteger addition(BigInteger num);
	BigInteger subtraction(BigInteger num);
   
	BigInteger sub(BigInteger num);
   BigInteger add(BigInteger num);
	BigInteger multi(BigInteger num);
   
   std::string to_string() const;
	int get_digit(int i) const;
	int get_size() const;
	bool get_sign() const;

	void print();
private:
   std::vector<int> m_number;
	bool is_pos;
};



#endif

