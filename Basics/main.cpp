#include<bits/stdc++.h>
using namespace std;

void datatypes()
{
    int a;
    long b;
    long long c;

    cin >> a >> b >> c;

    float x = 4.3;
    float y = 4;
    double z = 3.3;

    cout << z << endl;

    string s1, s2;
    cin >> s1 >> s2;
    cout << "Strings are: " << s1 << " " << s2 << endl;

    cin.ignore();
    string str;
    getline(cin, str);
    cout << "Entire line including spaces: " << str << endl;

    char cc;
    cin >> cc;
    cout << "Character given is: " << cc << endl;
}

void ifelse()
{
    int age = 19;

    if (age < 18)
    {
        cout << "Not eligible to vote" << endl;
    }
    else
    {
        cout << "Eligible to vote" << endl;
    }
}

void switchcase()
{
    int age = 18;

    switch(age >= 18)
    {
    case 1 :
        cout << "Eligible to vote" << endl;
        break;
    case 0 :
        cout << "Not eligible to vote" << endl;
        break;
    default :
        cout << "Invalid input!" << endl;
        break;
    }
}

void ArrayIntro()
{
    int len = 10;
    int arr[len];

    for(int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }

    string k = "striver";
    k[0] = 'p';
    int slen = k.size();
    cout << k << endl;
}

void loops()
{
    for(int i = 0; i < 10; i++)
    {
        cout << "hello" << endl;
    }
    int a = 1;
    while(a <= 10)
    {
        cout << "Hello world from while loop" << endl;
        a++;
    }
}

void PassByValues(int a, int b)
{
   int temp = a;
   a = b;
   b = temp;
}

void PassByReference(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void PassByReferenceSwapString(char **str1, char **str2)
{
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void functions()
{
    cout << "Void function" << endl;
}

void inputoutput()
{
    int a;
    cin >> a;
    cout << "The given number is: " << a << endl;
}

int main()
{
    int a = 1;
    int b = 2;
    PassByReference(&a, &b);
    cout << a << " " << b << endl;

    char str1[] = "Hello";
    char str2[] = "World";
    char *string1 = str1;
    char *string2 = str2;
    PassByReferenceSwapString(&string1, &string2);
    cout << string1 << " " << string2 << endl;

    return 0;
}
