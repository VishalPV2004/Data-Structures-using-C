#include<stdio.h>

int main()
{
    int arr[] = {1,2,3,1,1,1,1,4,2};
    int n = sizeof(arr)/sizeof(int);
    
    int p1 = 0, p2 = 0, p3 = 0;
    
    while(p1 < n)
    {
        p2 = p1;
        while(p2 < n)
        {
            p3 = p2;
            while(p3 < n)
            {
                printf("%d ",arr[p3]);
                p3++;
            }
            printf("\n");
            p2++;
        }
        
        p1++;
    }
}
