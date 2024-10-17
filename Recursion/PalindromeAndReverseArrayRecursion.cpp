#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
string s;

void reverseArray(int l, int r)
{
    if (l >= r)
        return;
    
    swap(arr[l], arr[r]);
    reverseArray(l+1, r-1);
}

void reverseArrayOnePointer(int i)
{
    if (i >= arr.size()/2)
        return;
    
    swap(arr[i], arr[arr.size()-1-i]);
    reverseArrayOnePointer(i+1);
}

bool checkPalindrome(int i)
{
    if (i >= s.size()/2)
      return true;
    
    if (s[i] != s[s.size()-1-i])
      return false;
    
    return checkPalindrome(i+1);
}

/* to know the status of recursion at each stage :
 bool checkPalindrome(int i)
{
    if (i >= s.size()/2) {
        cout << "1 ";  // Base case: if we reach the middle, it's a palindrome.
        return true;
    }
    
    if (s[i] != s[s.size()-1-i]) {
        cout << "0 ";  // Print 0 if characters don't match.
        return false;
    }
    
    cout << "1 ";  // Print 1 if characters match.
    return checkPalindrome(i+1);
}
*/
int main()
{
    arr = {1, 2, 3, 4, 5}; 
    s = "malayalam";
    reverseArray(0, arr.size()-1);
    for (int i : arr)
        cout << i << " ";
    cout << endl;

    reverseArrayOnePointer(0);
    for (int i : arr)
        cout << i << " ";
    cout << endl;
    cout<<checkPalindrome(0);
}
