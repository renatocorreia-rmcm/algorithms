#include <iostream>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int* a, int l, int r){
    int p = a[l];
    int i = l;
    int j = r+1;
    do
    {
        do
        {
            i++;
        } while (!((a[i] >= p) || (i >= r)));

        do
        {
            j--;
        } while (!(a[j]<=p));

        swap(a[i], a[j]);
        
    } while (!(i>=j));
    
    swap (a[i], a[j]);
    swap (a[l], a[j]);

    return j;
}

void quicksort(int* a, int l, int r){
    if (l<r){
        int s = partition(a, l, r);  // split position

        quicksort(a, l, s-1);
        quicksort(a, s+1, r);
    }

}




int main(){


    int a[] = {5, 2, 1, 7, 0};

    quicksort(a, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    



    return 0;
}