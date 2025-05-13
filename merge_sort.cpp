#include <iostream>
using namespace std;


void merge(int* a, int l, int r){
    
    int temp[r-l+1];
    for (int i = l; i < r; i++)
    {
        temp[i] = a[i];
    }

    int m = (l+r)/2;
    
    int i1=l;
    int i2=m+1;   
    
    for (int curr = l; curr < r; curr++)
    {
        // ended some block
        if (i1==m+1)
        {
            a[curr] = temp[i2++];
        }
        else if (i2>r)
        {
            a[curr] = temp[i1++];
        }
        // both blocks not ended
        else
        {
            if (temp[i1]<temp[i2])
            {
                a[curr] = temp[i1++];
            }
            else
            {
                a[curr] = temp[i2++];
            }
           
        }
    }
    
    
}

void mergesort(int* a, int l, int r){
    int m = (l+r)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    merge(a,l,r);
}





int main(){

    int arr[] = {1, 9, 2, 8, 3, 7, 4, 6, 5, 0};

    mergesort(arr, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}