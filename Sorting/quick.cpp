#include<bits/stdc++.h>
using namespace std;


int f(int arr[], int low, int high)
{
    int pivot = arr[low];  // Set the pivot to the first element
    int i = low + 1;  // Start i from the next element
    int j = high;
    
    while(i <= j)
    {
        while(i <= high && arr[i] <= pivot)
        {
            i++;
        }
        
        while(arr[j] > pivot && j >= low)
        {
            j--;
        }
        
        if (i < j)
        {
            swap(arr[i], arr[j]);  
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int part = f(arr,low, high);
        quickSort(arr,low,part-1);
        quickSort(arr,part+1,high);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array : "<<endl;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    quickSort(arr,0,n-1);
    
    for(int i=0;i<n;i++)
    cout<<arr[i];
}