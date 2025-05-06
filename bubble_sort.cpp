#include <iostream>

using namespace std;


void bubble_sort(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]=temp;
            }
            
        }
        
    }
    
}


int main(){

    int arr[] = {1, 9, 2, 8, 3, 7, 4, 6, 5, 0};

    bubble_sort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    


    return 0;
}