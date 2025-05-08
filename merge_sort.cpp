#include <iostream>
using namespace std;


void separate(int* arr, int n){
    
    int* a = new int[n/2];
    int* b = new int[(n+1)/2];
    for (int i = 0; i < n/2; i++)
    {
        a[i] = arr[i];
    }
    for (int i = 0; i < n+1/2; i++)
    {
        b[i] = arr[i+n/2];
    }


    return merge_sort(a, n/2) + merge_sort(b, (n+1)/2);
    
}
void unite(int* arr, int n){

}

int* merge_sort(int* arr, int n){

    if (n)
    {
        /* code */
    }
    

}


int main(){



    return 0;
}