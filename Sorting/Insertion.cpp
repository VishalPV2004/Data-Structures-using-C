#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int j = i;
        while(j > 0 && arr[j] < arr[j-1])
        {
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Before sorting : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    SelectionSort(arr,n);
    cout<<endl;
    cout<<"After sorting : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" "; 
    }
    
}