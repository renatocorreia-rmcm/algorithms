#include <iostream>

using namespace std;


void swap(int& a, int& b){  // auxiliary function
    int temp = a;
    a = b;
    b = temp;
}


int pivoting(int* arr, int l, int r){  // pivot arr[l:r]  ->  {ai<pivot} + [pivot] + {ai>pivot}  // return pivot index
    
    int pivot = arr[l];
    int i = l;
    int j = r+1;

    do  // swap all {ai>pivot in left} with {ai<pivot in right}
    {
        do // search first element not in place from left-start 
        {
            i++;
        } while ((arr[i] < pivot) && (i < r));  

        do  // search first element not in place from right-start
        {
            j--;
        } while (arr[j]>pivot); 

        // swap both elements not in place
        swap(arr[i], arr[j]);
        
    } while (!(i>=j));
    
    swap (arr[i], arr[j]);
    swap (arr[l], arr[j]);

    return j;
}


void quicksort(int* arr, int l, int r){
    
    if (l<r){
        int i_pivot = pivoting(arr, l, r);  // pivot index

        quicksort(arr, l, i_pivot-1);
        quicksort(arr, i_pivot+1, r);
    }

}

void quicksort(int* arr, int n){
    quicksort(arr, 0, n-1);
}




int main(){


    int arr[] = {5, 2, 1, 7, 0};
    int n = sizeof(arr)/sizeof(int);

    quicksort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}