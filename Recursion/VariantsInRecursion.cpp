#include<bits/stdc++.h>
using namespace std;
/*
|-----------------------------------------------------------|
|                Sum of N natural numbers                   |
|-----------------------------------------------------------| */

//Parameterised recursion
void sumOfN(int a, int b)
{
	if (a < 0)
	{
		cout<<b<<endl;
		return;
	}

	sumOfN(a-1,b+a);
}

//functional recursion
int sumOfN(int a)
{
	if (a == 0)
		return 0;

	return a + sumOfN(a-1);
}

/*
   Functional recursion

   first case : input => 3
   checks if it is zero, it is not, hence it executes return statement,
   where it will be waiting like 3 + sumOfN(2)

   second case : input => 2
   this is called recursively from the first call, it is also not equal to zero,
   it will be waiting like 2 + sumOfN(1)

   third case : input => 1
   this is called recursively from second call, it is not equal to zero,
   it will be waiting like 1 + sumOfN(0)

   fourth case : input => 0
   this is called recursively from third call, it is equal to zero,
   now it will return the value 0, the program get completely executed

   as a result :
   1 + sumOfN(0) will change to 1 + 0, hence their sum 1 is returned by third case

   2 + sumOfN(1) will chage to 2 + 1, hence their sum 3 is returned by second case

   3 + sumOfN(2) will change to 3 + 3, hence their sum 6 is returned by first case

   all cases gets exected and the value is returned.
-
|-----------------------------------------------------------|
|                  Factorial of a number                    |
|-----------------------------------------------------------| */

// Parameterised recursion
void fact(int a, int b)
{
	if (a < 1)
	{
		cout<<b<<" ";
		return;
	}

	fact(a-1,b*a);
}

// Functional recursion
int fact(int a)
{
	if (a == 0)
		return 1;

	return a * fact(a-1);
}

int main()
{
	sumOfN(3,0);
	cout<<sumOfN(3);
	cout<<endl;
	fact(5,1);
	cout<<endl;
	cout<<fact(5);
}