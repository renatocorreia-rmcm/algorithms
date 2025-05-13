#include <iostream>

using namespace std;

int sequential_search(int* a, int k, int n){
    int i = 0;
    while (i < n && a[i] != k){
        i++;
    }
    if (i < n){
        return i;
    } 
    return -1;
}


int main(){


    int a[] = {5, 2, 1, 7, 0};

    cout << sequential_search(a, 7, 4) << " ";

    



    return 0;
}