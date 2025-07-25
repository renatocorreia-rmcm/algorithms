#include <iostream>

#include <vector>

#include <cstdlib>  // for rand and srand
#include <ctime>    // for time

using namespace std;

typedef vector<vector<int>*> matrix;
#define n 5


matrix gen_matrix(){
    
    matrix* m = new matrix(n);
    
    std::srand(std::time(nullptr)); // seed the RNG
    for (int i = 0; i < n; i++)
    {
        m->push_back( new vector<int>(n) );
        for (int j = 0; j < n; j++)
        {
            (*m)[i][j] = std::rand()%10;
        }
        
    }
    
    return m;
}

int max_path(int** m, int r, int c){

    if (r==n-1 && c==n-1) return m[n-1][n-1];

    return m[r][c] + max(
        ((r+1<n) ? max_path(m, r+1, c):0),
        ((c+1<n) ? max_path(m, r, c+1):0)
    );    
    
}

int max_path(int** m){
    return max_path(m,0,0);
}

void print(int** m){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << m[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(){


    int** m = gen_matrix();

    print(m);

    cout << max_path(m);

    
    return 0;
}