#include <iostream>
using namespace std;


void merge(int* a, int l, int r){
    
    int temp[r-l+1];
    for (int i = l; i <= r; i++)
    {
        temp[i-l] = a[i];
    }

    int m = (l+r)/2;
    
    int i1=l;
    int i2=m+1;   
    
    for (int curr = l; curr <= r; curr++)
    {
        // ended some block
        if (i1==m+1)
        {
            a[curr] = temp[i2++-l];
        }
        else if (i2>r)
        {
            a[curr] = temp[i1++-l];
        }
        // both blocks not ended
        else
        {
            if (temp[i1-l]<temp[i2-l])
            {
                a[curr] = temp[i1++-l];
            }
            else
            {
                a[curr] = temp[i2++-l];
            }
           
        }
    }
    
    
}

void mergesort(int* a, int l, int r){
    if (l<r)
    {
    
    int m = (l+r)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    merge(a,l,r);
    }

}





int main(){

    int arr[] = {5,2,1,7,0};

    mergesort(arr, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}