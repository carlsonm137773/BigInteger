/*
* Project: Biginteger 
* File: biginteger.cpp
* Description:
* Developer: Matthew Carlson
* Email: carlsonm137773@student.vvc
* Date created: 03/12/2019
*/

#include"biginteger.h"

BigInteger::BigInteger()
{}

BigInteger::BigInteger(std::string _number)
{
   for(int i = 0; i < _number.size(); i++ )
      m_number.push_back(_number[i] - '0');
}

BigInteger::BigInteger(std::vector<int> _number)
{
   m_number = _number;   
}
void BigInteger::print()
{
   for(int i = 0; i < m_number.size(); i++)
      std::cout << m_number[i];

   std::cout << std::endl;
}

BigInteger BigInteger::add(BigInteger num)
{

   return BigInteger("0");
}

