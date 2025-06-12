#include <iostream>
using namespace std;

/*
left    2*i
right   2*i+1
parent  i//2
*/

/*
size: não conta com primeiro elemento (null)
index: conta com primeiro elemento (null, 0)
*/

class heap_BottomUp
{
public:
    int* arr;
    int n;
    int max_size;

    void print(){
        for (int i = 1; i <= n; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
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

    void insert(int v){
        n++;
        arr[n] = v;  // insert new value at the end of the heap
        int k = n;  // current node index
        int i_parent = k/2;  // parent index

        while (k>1 && arr[i_parent]<arr[k])  // while not root and parent is smaller than current node
        {
            swap(arr[k], arr[i_parent]);  // swap with parent
            k = i_parent;  // move to parent
            i_parent = k/2;  // update parent index
        }

    }

    void remove_root(){
        if (n==0) return;

        arr[1] = arr[n];
        n--;
        heap_bottom_up();
    }

    heap_BottomUp(int* a, int n){

        max_size = n;
        this->max_size = max_size;
        
        this->arr = a;
        this->n=n;
        heap_bottom_up();

    }
};



int main(){

    int* arr = new int[8]{0, 2, 9, 7, 6, 5, 8, 10};

    heap_BottomUp h = heap_BottomUp(arr, 7);

    h.print();

    h.remove_root();

    h.print();

    h.remove_root();

    h.print();

    h.insert(11);
    h.print();

    h.insert(1);
    h.print();



    return 0;
}