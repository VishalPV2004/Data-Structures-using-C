#include<bits/stdc++.h>
using namespace std;

void recur()
{
    static int cnt = 0;
    
    if (cnt == 3)
     return;
    
    cout<<cnt<<" ";
    cnt++;
    recur();
}
int main()
{
    recur();
    return 0;
}