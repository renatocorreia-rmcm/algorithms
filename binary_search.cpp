#include <iostream>

using namespace std;


int binary_search(int* arr, int l, int r, int k){
    /*
    k: target
    l: slice start index, inclusive
    r: slice end index, inclusive
    */
    if (r>l)  // len(slice)>0  // maybe could do len(slice)>1 and always return last found index, being target or not (would be the 'to insert' position)
    {
        int m = (l+r)/2;  // slice mid index

        if (k == arr[m])  // found
        {
            return m;
        }

        if (k < arr[m])  // is at left
        {
            return binary_search(arr, l, m-1, k);
        }
        else  // is at right
        {
            return binary_search(arr, m+1, r, k);
        }       
    }
    return k>arr[r] ? r+1 : r;  // not found - no more slice to search  // return n if k is bigger than every element of array
}

int binary_search(int* arr, int n, int k){
    /*
    return: index of found element or index of where it should be inserted
    */
    return binary_search(arr, 0, n-1, k);
}



int main(){

    //         0 1 2 3 4 5  6 
    int a[] = {1,3,4,5,7,8,10};
    int n = sizeof(a)/sizeof(int);

    cout << binary_search(a, n, 3)<<'\n';
    cout << binary_search(a, n, 9)<<'\n';
    cout << binary_search(a, n, 11)<<'\n';


    return 0;
}