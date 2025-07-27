#include <iostream>

using namespace std;


/* for memory grid*/
#include <vector>
typedef  vector<vector<int>> grid;
#define EMPTY 0


int F(int i, int j, int* v, int* w, grid& m){
    

    if (i<0 || j==0) return 0;  // no items to add  ||  no more space in bag

    if (m[i][j-1] == EMPTY)
    {
        m[i][j-1] = max(
            F(i-1, j, v, w, m),  // exclude i-th item
            ( (w[i]<=j) ? (v[i]+F(i-1, j-w[i], v, w, m)) : EMPTY )  // include i-th item if it fits
        );
    }
    
    return m[i][j-1];

}

int F(int n, int j, int* v, int* w){
    grid m = grid();

    for (int r = 0; r < n; r++) m.push_back(vector<int>(j,EMPTY));
    
    
    
    
    int s = F(n-1, j, v, w, m);
    
    for (vector<int> l: m){

        for (int k: l) cout << k << ' ';

        cout << '\n';
    }

    return s;
}


int main(){

    int n = 4;
    int j = 4;

    int* v = new int[n] {12,10,20,15};
    int* w = new int[n] { 2, 1, 3, 2};


    cout << F(n, j, v, w) << '\n';




    return 0;
}