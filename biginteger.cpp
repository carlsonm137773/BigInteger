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

BigInteger::BigInteger(std::string num_string)
{
   for(int i = num_string.size() -1; i >= 0; i-- )
      m_number.push_back(num_string[i] - '0');
}

BigInteger::BigInteger(std::vector<int> _number)
{
   m_number = _number;   
}

std::string BigInteger::to_string() const
{
   std::string s;
   
   for(int i = m_number.size() -1; i >= 0; i--)
      s = s + std::to_string(m_number[i]);

   return s;
}

void BigInteger::print()
{
   for(int i = m_number.size() -1; i >= 0; i--)
      std::cout << m_number[i];

   std::cout << std::endl;
}

std::vector<int> BigInteger::get_vec() const
{
   return m_number;   
}

int BigInteger::get_digit(int i) const
{
   return m_number[i];
}

int BigInteger::get_size() const
{
   return m_number.size();	
}

BigInteger BigInteger::add(BigInteger num)
{
   std::vector<int> number = num.get_vec();

   if(m_number.size() < num.get_size())
      swap(m_number, number);

   int carry = 0;
   std::string num_string = "";

   for(int i = 0; i < number.size(); i++)
   {
      int sum = m_number[i] + number[i] + carry;
      num_string = num_string + std::to_string(sum %10);
      carry = sum/10;
   }
   
   for(int i = number.size(); i < m_number.size(); i++)
   {
      int sum = m_number[i] + carry;
      num_string = num_string + std::to_string(sum%10);
      carry = sum/10;
   }
   if(carry > 0)
      num_string = num_string + std::to_string(carry);

   reverse(num_string.begin(), num_string.end());
       
      
   return BigInteger(num_string);
}


BigInteger BigInteger::multi(BigInteger num)
{
	std::vector<int> number = num.get_vec();

	BigInteger total;

	if(m_number.size() < number.size())
		swap(m_number, number);

	int carry = 0;

	for(int i1 = 0; i1 < number.size(); i1++ )
	{
		std::string num_string = "";
		for(int i2 = 0; i2 < m_number.size(); i2++ )
		{
			int sum = m_number[i2] * number[i1] + carry;
			num_string = num_string + std::to_string(sum%10);
			carry = sum/10;
		}
		if(carry > 0)
			num_string = num_string + std::to_string(carry);
	   int carry = 0;

		reverse(num_string.begin(), num_string.end());
		total = total.add(BigInteger(num_string));
//		total = total + BigInteger(num_string);
	}
   
	return total;
}

