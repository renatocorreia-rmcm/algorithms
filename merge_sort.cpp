#include <iostream>
using namespace std;


void merge(int* arr, int l, int r){  // auxiliar function only
    /*
    get slice of arr with each half sorted
    merge it linearly

    l: slice start index, inclusive
    r: slice end index, inclusive
    */

    // copy the slice arr[l:r] - will be readed while merging, since array will be being modified and contain inconsistent data
    int temp[r-l+1];
    for (int i = l; i <= r; i++)
    {
        temp[i-l] = arr[i];
    }

    // separate halfs
    int m = (l+r)/2;
    int i1=l;  // start of half 1
    int i2=m+1;  // start of half 2
    
    // linearly iterate over whole slice
    for (int curr = l; curr <= r; curr++)
    {

        // ended some half - can only use the other
        if (i1==m+1) {  // half 1
            arr[curr] = temp[i2++-l];
        }
        else if (i2>r) {  // half 2
            arr[curr] = temp[i1++-l];
        }

        // none half has ended - gotta see wich has the smallest value
        else
        {
            if (temp[i1-l]<temp[i2-l]) {  // half 1 has the smallest
                arr[curr] = temp[i1-l];  // merge it
                i1++;  // advance index to smallest of half 1
            }
            else {  // half 2 has the smallest
                arr[curr] = temp[i2-l];  // merge it
                i2++;  // advance index to smallest of half 2
            }
           
        }
    }
    
    
}

void mergesort(int* arr, int l, int r){  // auxiliar function only
    /*
    l: start point, inclusive
    r: end point, inclusive  
    */

    if (l<r){  // this piece has at least 2 elements

        // divide 2 halfs
        int m = (l+r)/2;

        // sort each half
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);

        // merge the 2 halfs
        merge(arr,l,r);
    }

}


void mergesort(int* arr, int size){
    mergesort(arr, 0, size-1);
}


int main(){

    int arr[] = {5,2,1,7,0};
    int n = sizeof(arr)/sizeof(int);

    mergesort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}