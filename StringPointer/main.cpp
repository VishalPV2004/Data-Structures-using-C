#include <iostream>

using namespace std;

void swapString(char **str1, char **str2)
{
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int main()
{
    char s1[] = "Hello";
    char s2[] = "world";

    char *str1 = s1;
    char *str2 = s2;

    swapString(&str1,&str2);

    cout<<"After swapping : "<<endl;

    cout<<str1<<" "<<str2<<endl;
}

/* Explantion:

 s1 : "Hello" (having an address of 0x1000)
 s2 : "world" (having an address of 0x2000)

 ptr1 : points to s1, contents of ptr1 : 0x1000
 ptr2 : points to s2, contents of ptr2 : 0x2000

    _______           _______
   | 1000 |           | 2000|
   |______|           |_____|
     1500H             1600H
     ptr1               ptr2

 now this address 1500 and 1600 will be passed on to the method
 these will pointed by str1 and str2

 str1 and str2 will be having the address of those two pointers,
 they will form a double pointer.

    str1 --> ptr1 --> s1
    str2 --> ptr2 --> s2

 if str1 is derefernced once it will display the address of the
 ptr1, same for str2 as well.

 now the addresses present in ptr1 and ptr2 is changed, using a temporary pointer

    str1 --> ptr1 --> s2
    str2 --> ptr2 --> s1

 */
