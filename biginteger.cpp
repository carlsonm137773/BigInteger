/*
* Project: Biginteger 
* File: biginteger.cpp
* Description:
* Developer: Matthew Carlson
* Email: carlsonm137773@student.vvc
* Date created: 03/12/2019
*/

#include"biginteger.h"

BigInteger::BigInteger() {}

/*
Constructor for the BigInteger class
@peram num_string string used to create the m_number vector
*/
BigInteger::BigInteger(std::string num_string)
{
   for(int i = num_string.size() -1; i >= 1; i-- )
	{
      m_number.push_back(num_string[i] - '0');
	}
	if(num_string[0] == '-')
		is_pos = false;
	else
	{
		m_number.push_back(num_string[0] - '0');
		is_pos = true;
	}
}

/*
Changes the sign of the BigInteger
*/
void BigInteger::change_sign()
{
	if(is_pos)
		is_pos = false;
	else
		is_pos = true;
}

/*
Returns the number as a string
*/
std::string BigInteger::to_string() const
{
   std::string s;

	if(!(is_pos))
		s.push_back('-');
   
   for(int i = m_number.size() -1; i >= 0; i--)
      s = s + std::to_string(m_number[i]);

   return s;
}

/*
Outputs the number using cout
*/
void BigInteger::print()
{
	if(!(is_pos))
		std::cout << '-';
   for(int i = m_number.size() -1; i >= 0; i--)
      std::cout << m_number[i];

   std::cout << std::endl;
}

/*
return the integer stored at the givin index
@peram i the index
@return the integer stored at the givin index
*/
int BigInteger::get_digit(int i) const
{
   return m_number[i];
}

/*
returns the size of the m_number vector
*/
int BigInteger::get_size() const
{
   return m_number.size();	
}

/*
returns the is_pos bool
*/
bool BigInteger::get_sign() const
{
	return is_pos;
}

/*
Adds 2 BigIntegers together
@peram num the BigInteger to be added
@return the total
*/
BigInteger BigInteger::add(BigInteger num)
{
	if( (this->get_sign() == false || num.get_sign() == false) && !(this->get_sign() == num.get_sign()))
		return this->sub(num);

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
 
/*
subtracts 2 BigIntegers
@peram num
@return 
*/
BigInteger BigInteger::sub(BigInteger num)
{

	BigInteger* number1 = this;
	BigInteger* number2 = &num;
   std::string num_string = "";


	//if(number1->get_size() < number2->get_size())
	//	std::swap(number1, number2);

	int carry = 0;
	int size_dif = number1->get_size() - number2->get_size();

	for(int i = number2->get_size() - 1; i >= 0; i--)
	{
		int diff = (number1->get_digit(i + size_dif) - number2->get_digit(i) - carry);

		if(diff < 0)
		{
			diff = diff + 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		num_string = num_string + std::to_string(diff);
	}
	for(int i = number1->get_size() - number2->get_size() - 1; i >= 0; i--)
	{
		if(number1->get_digit(i) == 0 || carry > 0)
			num_string = num_string + "9";

		int diff = (number1->get_digit(i) - carry);

		if(i > 0 || diff > 0)
			num_string = num_string + std::to_string(diff);

		carry = 0;
	}
	reverse(num_string.begin(), num_string.end());

	BigInteger difference = BigInteger(num_string);

	if(this->get_size() < num.get_size())
		difference.change_sign();
	else if(this->get_size() == num.get_size() && this->get_digit(this->get_size() -1) < num.get_digit(num.get_size() -1))
		difference.change_sign();
		
		
	
	return difference;
}

/*
returns the product of 2 BigIntegers
@peram num the 2nd BigInteger
@return the product
*/
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
			std::cout << num_string << std::endl;
			total = total.add(BigInteger(num_string));
			count ++;
	}
	if((num1->get_sign() && num2->get_sign()) || (!(num1->get_sign()) && !(num2->get_sign())))
	{}
	else
		total.change_sign();
	return total;
}

