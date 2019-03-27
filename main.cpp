/*
* Project: BigInteger 
* File: main.cpp
* Description:
* Developer: Matthew Carlson
* Email: carlsonm137773@student.vvc
* Date created: 03/12/2019
*/

#include"biginteger.h"
#include<iostream>

int main()
{
	BigInteger a = BigInteger("99283");
	BigInteger b = BigInteger("2348");
	BigInteger c = a + b;
	std::cout << "a = " << a << std::endl
				 << "b = " << b << std::endl
				 << a << " + " << b << " = " << a + b << std::endl
				 << a << " - " << b << " = " << a - b << std::endl
				 << a << " * " << b << " = " << a * b << std::endl;

  	return 0;   
}

