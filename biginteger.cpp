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
   BigInteger* number1 = this;
   BigInteger* number2 = &num;

   if(number1->get_size() < number2->get_size())
      std::swap(number1, number2);

   int carry = 0;
   std::string num_string = "";

   for(int i = 0; i < number2->get_size(); i++)
   {
      int sum = number1->get_digit(i) + number2->get_digit(i) + carry;
      num_string = num_string + std::to_string(sum %10);
      carry = sum/10;
   }
   
   for(int i = number2->get_size(); i < number1->get_size(); i++)
   {
      int sum = number1->get_digit(i) + carry;
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
	BigInteger* num2 = &num;
	BigInteger* num1 = this;

	if(num1->get_size() < num2->get_size())
		std::swap(num1, num2);

   BigInteger total;
	int count = 0;
	for(int i1 = 0; i1 < num1->get_size(); i1++)
	{
		int carry = 0;
	   std::string num_string = "";
		if(count > 0)
		{
			for(int c = 0; c < count; c++)
				num_string = num_string + "0";
		}
	   for(int i2 = 0; i2 < num2->get_size(); i2++)
		{
			int product =  num1->get_digit(i1) * num2->get_digit(i2) + carry;
			num_string = num_string + std::to_string(product%10);
			carry = product/10;
		}
		if(carry > 0)
		   num_string = num_string + std::to_string(carry);

			reverse(num_string.begin(), num_string.end());
			total = total.add(BigInteger(num_string));
			count ++;
	}
	return total;
}

