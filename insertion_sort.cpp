#include <iostream>

using namespace std;


void insertion_sort(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        int menor = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[menor])
            {
                menor = j;
            }
            
        }
            int temp = arr[i];
            arr[i] = arr[menor];
            arr[menor] = temp;
        
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