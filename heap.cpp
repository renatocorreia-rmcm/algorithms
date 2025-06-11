#include <iostream>
using namespace std;

/*
left    2*i
right   2*i+1
parent  i//2
*/

class heap
{
public:
    int* arr;
    int n;

    void print(){
        for (int i = 1; i <= n; i++)
        {
            cout << arr[i] << ' ';
        }
    }


    void heap_bottom_up(){
        int i_lastparent = n/2;  // tree last parent (rightmost node not leaf)
        for (int i = i_lastparent; i >= 1; i--)  // iterate from last parent to root
        {
            int k = i;
            int v = arr[k];

            bool heap = false;

            int i_leftchild = 2*k;
            int i_rightchild = 2*k+1;

            
            while (!heap && i_leftchild <=n)
            {
                
                /*   SET BIGGER CHILD   */
                int i_biggerchild = i_leftchild;  // default bigger since right child may not exist
                if (i_biggerchild < n)  // range checking to see if right child exists
                {
                    if (arr[i_rightchild] > arr[i_leftchild])
                    {
                        i_biggerchild = i_rightchild;
                    }
                }
                /*  COMPARE TO PARENT   */
                if (v>=arr[i_biggerchild])
                {
                    heap = true;
                }
                else
                {
                    arr[k] = arr[i_biggerchild];
                    k = i_biggerchild;
                    i_leftchild  = 2*k;
                    i_rightchild = 2*k+1;
                }
            }
            arr[k] = v;
            i_leftchild  = 2*k;
            i_rightchild = 2*k+1;
            


        }
    }

    heap(int* a, int n){

        this->arr = a;
        this->n=n;
        heap_bottom_up();

    }
};



int main(){

    int* arr = new int[8]{0, 2, 9, 7, 6, 5, 8, 10};

    heap h = heap(arr, 7);

    h.print();




    return 0;
}