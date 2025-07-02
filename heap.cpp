#include <iostream>
using namespace std;

/*
left    2*i
right   2*i+1
parent  i//2
*/

/*
size: não conta com primeiro elemento (0)
index: conta com primeiro elemento (0, 0)
*/

class heap
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

    void heap_bottom_up(){  // builds heap above ready made array

        int i_lastparent = n/2;  // last parent in tree (rightmost node not leaf)
        for (int i = i_lastparent; i >= 1; i--)  // iterate from last parent to root
        {
            int k = i;  // parent index
            int v = arr[k];  // parent value

            int i_leftchild = 2*k;
            int i_rightchild = 2*k+1;

            bool heapfiyed = false;
            
            while (!heapfiyed && i_leftchild <=n)  // dive parent into biggerchild until heapfy it
            {
                
                /*   SET BIGGER CHILD   */
                int i_biggerchild = i_leftchild;  // default bigger since right child may not exist
                
                if ((i_rightchild <= n)  &&  (arr[i_leftchild] < arr[i_rightchild]))  // rightchild exists  and  is bigger than left
                {
                    i_biggerchild = i_rightchild;
                }
                
                /*  COMPARE TO PARENT   */
                if (v>=arr[i_biggerchild])
                {
                    heapfiyed = true;
                }
                else
                {  // swap parent with bigger child 
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

    void insert(int v){  // TOP-DOWN
        n++;
        arr[n] = v;  // insert new value at the end of the heap
        int k = n;  // current node index
        int i_parent = k/2;  // parent index

        // HEAPIFY
        while (k>1 && arr[i_parent]<arr[k])  // while not root and parent is smaller than current node
        {
            swap(arr[k], arr[i_parent]);
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


    /*
        CONSTRUCTORS
    */

    // BOTTOM-UP
    heap(int* a, int n, int max_size = 0){

        if (max_size==0)
        {
            max_size = n;
        }
        
        // copy array pushing 0 at 0
        this->arr = new int[n+1];
        arr[0] = 0;
        for (int i = 0; i < n; i++) arr[i+1] = a[i];
        
        this->n=n;
        this->max_size = max_size;

        heap_bottom_up();
    }
    // TOP-DOWN
    heap(int max_size = 0){
        if (max_size == 0)
        {
            max_size = 10e5;
        }

        this->arr = new int[max_size];
        arr[0] = 0;

        this->n = 0;
    }
};



int main(){

    int* arr = new int[7]{2, 9, 7, 6, 5, 8, 10};

    heap h = heap(arr, 7);

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