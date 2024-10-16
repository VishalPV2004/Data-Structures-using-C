#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/* Note

 * For iterations based on divisions, the complexity is just log(x),
   where x is the number by which the loop is iterated */


void countLog(int a)
{
    int cnt = (int)(log10(a)+1);
    cout<<cnt;
}

int reverse(int a)
{
    int rev = 0;
    while(a > 0)
    {
        int rem = a % 10;
        rev = (rev * 10) + rem;
        a /= 10;
    }
    return rev;
}

void palindrome(int a)
{
    int k = reverse(a);
    if (a == k)
        cout<<"Yes it is a palindrom"<<endl;
    else
        cout<<"No it is not a palindrome"<<endl;
}
void armstrong(int a)
{
    int k = a;
    int sum = 0;

    while(a > 0)
    {
        int rem = a % 10;
        sum = sum + (a * a * a);
        a /= 10;
    }

    if (sum == k)
        cout<<"Yes, it is an armstrong"<<endl;
    else
        cout<<"No, it is not an armtrong number"<<endl;
}

void printAllDivisiors(int a)  //this has TC = O(n)
{
    for(int i=1;i<=a;i++)
    {
        if (a % i == 0)
            cout<<i<<" ";
    }
}

void printDivisorsOpt(int a)
{
    int k = sqrt(a);
    vector<int> v;
    for(int i=1;i<k;i++)  //O(sqrt(a)
    {
        if (a % i == 0)
        {
            v.push_back(i);

            if (a/i != i)
            {
                v.push_back(a/i);
            }
        }
    }
    sort(v.begin(),v.end()); //O(a*loga)
    for(auto it : v) cout<<it<<" ";
}

void checkPrimeBrute(int a)
{
    int cnt = 0;
    for(int i=0;i<=a;i++)
    {
        if (a % i == 0)
            cnt++;
    }
    if (cnt == 2)
        cout<<"Yes it is a prime"<<endl;
    else
        cout<<"No it is not a prime"<<endl;

}

void checkPrimeOptimal(int n) {
    if (n <= 1) {
        cout << "False" << endl;
        return;
    }
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cnt++;
            if (i != n / i)
                cnt++;
        }
    }

    if (cnt == 2)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}

void GCD(int a, int b)
{
    int least = min(a,b);

    for(int i=least;i>=1;i--)
    {
        if (a%i == 0 && b%i == 0)
        {
            cout<<i<<" ";
            break;
        }
    }
}

void GCDoptimal(int a,int b)
{
    //Euclidean algorithm

    // gcd(a,b) = gcd(a-b,b) ; provided a > b
    // ex gcd(20,15) => gcd(5,15) => gcd(5,10) => gcd(5,5) => gcd(5,0), now acutal GCD is 5.

    /*It can also be written as
     gcd(a,b) = gcd(a%b,b), at the instance when b becomes zero, that a is the gcd.
    */
    while(a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        cout<<b<<endl;
    else
        cout<<a<<endl;

}

void count(int a)
{
    int cnt = 0;

    while(a > 0)
    {
        int num = a % 10;
        cnt++;
        a /= 10;
    }
    cout<<cnt;
}

int main()
{
    GCDoptimal(13,1);
}
