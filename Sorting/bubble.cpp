#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i = n - 1; i > 0; i--) 
    {
        int swapped = 0;
        for(int j = 0; j < i; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swapped = 1;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "After sorting: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";  
    }
    cout << endl;
}
