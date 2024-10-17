#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
      return n;
    
    int first = fibonacci(n-1);
    int second = fibonacci(n - 2);
    
    return first+second;
}

/*
   Working :
   
   input : 4
   
   n = 4
     Base case gets ignored
     fibonacci(3) is called and followed by fibonacci(2), first fibonacci(3) will be executed
     
     fibonacci(3): inturn calls two functions
       i) calls fibonacci(2)
       ii) calls fibonacci(1)
       
       fibonacci(2) will call fibonacci(1) & fibonacci(0), which will return 1 and 0 respectively.
       now fibonacci(2) is finished, now control proceeds to fibonacci(1), which just returns 1.
       
       hence fibonacci(3) returns the value 1 + 1 + 0
     
     fibonacci(2) : inturn calls two functions
       i) calls fibonacci(1)
       ii) calls fibonacci(0)
       
       fibonacci(1) will just return 1
       fibonacci(0) will return 0
       
       this will be added and value 1 will be return as the result of function call of fibonacci(2)
    
     now both cases for 2 as well for 3 is found, they will be added and value will be returned.
     
     :)
*/


int main()
{
    cout<<fibonacci(4);
}
