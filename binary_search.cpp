#include <iostream>

using namespace std;


int bs(int* a, int l, int r, int k){
    if (r>=l)
    {
        int m = (l+r)/2;
        if (k == a[m])
        {
            return m;
        }
        if (k < a[m])
        {
            return bs(a, l, m-1, k);
        }
        else{
            return bs(a, m+1, r, k);
        }
        
        
    }
    return -1;
}



int main(){


    int a[] = {1,3,4,5,7,8,9};

    cout << bs(a, 0, 6, 4)<<" ";


    return 0;
}