#include <iostream>
using namespace std;

void merge(int* arr, int l, int r) {
    int m = (l + r) / 2;
    int temp[r - l + 1];

    
    for (int i = l; i <= r; i++) {
        temp[i - l] = arr[i];
    }

    int i1 = 0;           
    int i2 = m - l + 1;   
    int curr = l;

    while (i1 <= m - l && i2 <= r - l) {
        if (temp[i1] <= temp[i2]) {
            arr[curr++] = temp[i1++];
        } else {
            arr[curr++] = temp[i2++];
        }
    }


    while (i1 <= m - l) {
        arr[curr++] = temp[i1++];
    }

    while (i2 <= r - l) {
        arr[curr++] = temp[i2++];
    }
}


void mergesort(int* arr, int l, int r){
    if (l<r)
    {
        int m = (l+r)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, r);
    }
    
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