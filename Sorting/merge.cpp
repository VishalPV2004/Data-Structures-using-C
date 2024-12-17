#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    vector<int> temp; 
    
    int left = start;
    int right = mid + 1;
    
    while(left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    
    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    
    while(right <= end)
    {
        temp.push_back(arr[right]);
        right++;
    }
    
    for(int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end) 
        return;
    
    int mid = (start + end) / 2;
    
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    mergeSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
