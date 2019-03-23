/*
* Project: BigInteger 
* File: main.cpp
* Description:
* Developer: Matthew Carlson
* Email: carlsonm137773@student.vvc
* Date created: 03/12/2019
*/

#include"biginteger.h"

int main()
{
   BigInteger a = BigInteger("222");
   BigInteger b = BigInteger("33");
   a.print();
   b.print();

   BigInteger c = a.sub(b);
//   c.print();
	std::cout << "multi: " << std::endl;
   c = a.multi(b);
	std::cout << "= ";
	c.print();

   return 0;   
}

