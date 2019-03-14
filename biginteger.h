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

class BigInteger
{
public:
   BigInteger();
   BigInteger(std::string _number);
   Biginteger(std::vector<int> _number);
   
   BigInteger add(BigInteger num);
   

   void print();

private:
   std::vector<int> m_number;
};



#endif

