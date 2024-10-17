#include<bits/stdc++.h>
using namespace std;

void printName(int i, int n)
{
    if (i > n)
    return;                            //              printName(1,3) => Vishal      ^   
                                       //                |           |               |
    i++;                               //              printName(2,3) => Vishal      | 
    cout<<"Vishal"<<endl;              //                |           |               |
    printName(i,n);                    //              printName(3,3) => Vishal      |
}                                      //                |           |               |
                                       //              printName(4,3)                |
void printNumbers(int i,int n)
{
    if (i > n)
    return; 
    
    cout<<i<<" ";
    printNumbers(++i,n);
}

void printNumbersBacktrack(int a, int b)
{
    if (a < 1)
    {
        return;
    }
    printNumbersBacktrack(a-1,b);
    cout<<a;
}

/* Explanation for Backtracking :
     
    first case => (3,3) : parent => main function
      
      a is not less that 1, hence function is called recursively until the complete execution of the
      function call, parent function call will be stored in stack memory, alnogside a will be decremented
      by 1
    
    second case => (2,3) : parent => first case
      
      a is not less that 1, hence function is called recursively again, this call will be stored in the stack
      memory as well until the third function call gets executed, a will be decremented by one.
     
    third case => (1,3) : parent => second case
      
      now also a is not less that 1, hence recrusive function call occurs again and stored in stack memory until
      the child call gets executed completely, a will be decremented to 0.
    
    fourth case => (0,3) : parent => third case
    
      now a is less 1, means this function will be ended, since this function got ended completely, now the lines
      after the function call in third case will get executed and control flow reaches the flower brackets.
      output : prints 1
      
      Now the third case is completely executed, sensing this, the lines after the function call in second case
      will be executed.
      output : prints 2
      
      Similarly after completion of corresponding child function calls, cases will be executed.
      finally
      output : prints 3
     
       final output : 1 2 3
*/

void Nto1(int a, int b)
{
    if (a > b)
     return;
    
    Nto1(a+1,b);
    cout<<a<<" ";
}

int main()
{
    printNumbers(1,3);
    cout<<endl;
    printNumbersBacktrack(3,3);
    cout<<endl;
    Nto1(1,10);
}
