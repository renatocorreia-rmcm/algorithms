#include <iostream>
using namespace std;


void insertion_sort(int* arr, int n){
    int v; int j;
    for (int r = 1; r < n; r++)
    {
        v = arr[r]; j = r-1;

        while (j>=0 && arr[j]>v)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = v;
    }
    
}


int main(){

    int arr[] = {1, 9, 2, 8, 3, 7, 4, 6, 5, 0};

    insertion_sort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    


    return 0;
}