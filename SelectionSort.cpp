#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int size)
{
    for(int i = 0; i < size - 2; i++)
    {
        int min = i;
        for(int j = i+1 ; j < size-1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]); 
    }
    
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++)
       cin >> arr[i];
    
    selectionSort(arr, size);
}
