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
   BigInteger a = BigInteger("123456789");
   BigInteger b = BigInteger("987654321");

   a.print();
   b.print();

   BigInteger c = a.add(b);
   
   c.print();

   return 0;   
}

