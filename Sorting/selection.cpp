#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		int mini = i;
		for(int j = i ; j < n ; j++)
        {
            if (arr[j] < arr[mini])
            {

                mini = j;
            }
        }
        swap(arr[i],arr[mini]);
	}
}

int main()
{
    int n;
    cout<<"Enter the size of array : ";
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
    cout<<endl;
    SelectionSort(arr,n);

    cout<<"After sorting : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
