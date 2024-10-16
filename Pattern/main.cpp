#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void printPattern1(int a) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void printPattern2(int a)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}

void printPattern3(int a)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}

void printPattern4(int a)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a-i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

void printPattern5(int a)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a-i;j++)
        {
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}

void printPattern6(int a)
{
     for(int i=0;i<a;i++)
     {
         for(int j=0;j<a-1-i;j++)
         {
             cout<<" ";
         }


         for(int j=0;j<(2*i)+1;j++)
         {
             cout<<"*";
         }


         for(int j=0;j<a-1-i;j++)
         {
             cout<<" ";
         }
         cout<<endl;
     }
}

void printPattern7(int a)
{
     for(int i=a-1;i>=0;i--)
     {
         for(int j=0;j<a-1-i;j++)
         {
             cout<<" ";
         }


         for(int j=0;j<(2*i)+1;j++)
         {
             cout<<"*";
         }


         for(int j=0;j<a-1-i;j++)
         {
             cout<<" ";
         }
         cout<<endl;
     }
}
void printPattern8(int a)
{
         for(int i=0;i<a-1;i++)
     {
         for(int j=0;j<a-1-i;j++)
         {
             cout<<" ";
         }


         for(int j=0;j<(2*i)+1;j++)
         {
             cout<<"*";
         }


         for(int j=0;j<a-1-i;j++)
         {
             cout<<" ";
         }
         cout<<endl;
     }
     for(int i=a-1;i>=0;i--)
     {
         for(int j=0;j<a-1-i;j++)
         {
             cout<<" ";
         }


         for(int j=0;j<(2*i)+1;j++)
         {
             cout<<"*";
         }


         for(int j=0;j<a-1-i;j++)
         {
             cout<<" ";
         }
         cout<<endl;
     }

}

void printPattern9(int a)
{
    for(int i=1;i<=2*a-1;i++)
    {
        int stars = i;
        if (i > a) stars = 2*a-i;

        for(int j=1;j<=stars;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void printPattern10(int a)
{
    int start = 1;
    for(int i=0;i<a;i++)
    {
        if (i % 2 == 0) start = 1;
        else start = 0;
        for(int j=0;j<=i;j++)
        {
            cout<<start;
            start = 1 - start;
        }
        cout<<endl;
    }
}

void printPattern11(int a)
{
    int space = 2*(a-1);
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j;
        }

        for(int j=1;j<=space;j++)
        {
            cout<<" ";
        }

        for(int j=i;j>=1;j--)
        {
            cout<<j;
        }

        cout<<endl;
        space -= 2;
    }
}

void printPattern12(int a)
{
    for(int i=1;i<=a;i++)
    {
        for(int j=i;j>=1;j--)
        {

            cout<<j;
        }
        cout<<endl;
    }
}

void printPattern13(int a)
{
    int ct = 1;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<ct<<" ";
            ct++;
        }
        cout<<endl;
    }
}

void printPattern14(int a)
{
    for(int i=1;i<=a;i++)
    {
        for(char ch = 'A'; ch<'A'+i;ch++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void printPattern15(int a)
{
    for(int i=0;i<a;i++)
    {
        for (char ch = 'A';ch <= 'A'+(a-i-1);ch++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void printPattern16(int a)
{
    char ch = 'A';
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<ch<<" ";
        }
        ch++;
        cout<<endl;
    }
}

void printPattern17(int a)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a-i-1;j++)
        {
            cout<<" ";
        }

        char ch = 'A';
        for(int j=0;j<2*i+1;j++)
        {
            cout<<ch;
            if (j < i)
            {
              ch++;
            }
            else
            {
                ch--;
            }
        }

        for(int j=0;j<a-1-i;j++)
        {
            cout<<" ";
        }

        cout<<endl;
    }
}

void printPattern18(int a)
{
    for(int i=0;i<a;i++)
    {
        for(char ch = 'E'-i;ch <= 'E';ch++)
        {
            cout<<ch;
        }
        cout<<endl;
    }

}

void printPattern19(int a)
{
    for (int i=0;i<a;i++)
    {
        for(int j=0;j<a-i;j++)
        {
            cout<<"*";
        }

        for(int j=0;j<2*i;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<a-i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

  for (int i=a-1;i>=0;i--)
    {
        for(int j=0;j<a-i;j++)
        {
            cout<<"*";
        }

        for(int j=0;j<2*i;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<a-i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}



void printPattern20(int a)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        for(int j=2;j<2*(a-i);j++)
        {
            cout<<" ";
        }
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

        for(int i=a-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        for(int j=2;j<2*(a-i);j++)
        {
            cout<<" ";
        }
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void printPattern21(int a)
{
    for(int i=0;i<a;i++)
    {

        for(int j=0;j<a;j++)
        {
            if (i == 0 || i == a-1 || j == 0 || j == a-1)
                cout<<"*";
            else
                cout<<" ";
        }
     cout<<endl;
    }

}

void printPattern22(int a)
{
    for(int i=1;i<=(2*a)-1;i++)
    {
        for(int j=1;j<=(2*a)-1;j++)
        {
            int top = i;
            int bottom = j;
            int ltop = 2*a-i;
            int lbot = 2*a-j;

            int sum = min(min(top,bottom),min(ltop,lbot));
            cout<<a-sum+1;
        }
        cout<<endl;
    }
}



int main() {
    cout << "Pattern 1: " << endl;
    printPattern1(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 2: " << endl;
    printPattern2(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 3: " << endl;
    printPattern3(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 4: " << endl;
    printPattern4(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 5: " << endl;
    printPattern5(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 6: " << endl;
    printPattern6(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 7: " << endl;
    printPattern7(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 8: " << endl;
    printPattern8(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 9: " << endl;
    printPattern9(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 10: " << endl;
    printPattern10(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 11: " << endl;
    printPattern11(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 12: " << endl;
    printPattern12(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 13: " << endl;
    printPattern13(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 14: " << endl;
    printPattern14(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 15: " << endl;
    printPattern15(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 16: " << endl;
    printPattern16(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 17: " << endl;
    printPattern17(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 18: " << endl;
    printPattern18(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 19: " << endl;
    printPattern19(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 20: " << endl;
    printPattern20(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 21: " << endl;
    printPattern21(5);
    cout << "---------------------------" << endl;

    cout << "Pattern 22: " << endl;
    printPattern22(5);
    cout << "---------------------------" << endl;
}

