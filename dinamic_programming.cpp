/*
This code creates a grid of arbitrary size
with a randon value [0, 9] in each cell.
Then it finds the biggest cost path 
from (0,0) to (c-1, r-1), i.e., from top-left to bottom-right cell
moving only right or down each step.
Note that all possible paths are a `Permutation of (r+c) with repetitions of r and c`,
i.e., all paths will be composed of `c` moves to right and `r` moves to down,
permutated in a unique way.

it uses DP for optimize path finding,
and its usage can be simply deactivated in the headers,
so one can compare the performance
*/

#define USE_DINAMIC_PROGRAMMING true  // turn false to compare performance


#include <iostream>
#include <vector>  // for grid
#include <cstdlib>  // for random generation
#include <ctime>    // for seed

using namespace std;

typedef vector<vector<int>> matrix;

#define EMPTY -1  // for memo matrix



int max_path(matrix* map, matrix* memo, int r, int c){  // main algorithm descripted at start. how short and cute is it
    
    int ROWS = (*map).size();
    int COLS = (*map)[0].size();
    
    if (r==ROWS-1 && c==COLS-1) return (*map)[ROWS-1][COLS-1];  // reached end (bottom-right)
    
    if (((*memo)[r][c] == EMPTY) || !USE_DINAMIC_PROGRAMMING){  // if has no memo to this cell or just dont want to use dinamic programming optimization
        
        (*memo)[r][c] = (*map)[r][c] + max(  // memory for this cell is it value + bigger path from it to end
                                             // bigger path from it to end is the bigger between (path from right to end) or (path from down to end) and etc
            // range checking
            ((r+1<ROWS) ? max_path(map, memo, r+1, c) : 0),
            ((c+1<COLS) ? max_path(map, memo, r, c+1) : 0)
        );
    }
    
    return (*memo)[r][c];
}


matrix* gen_matrix(int rows, int cols, bool noise){  // used in map and memo generation
    matrix* m = new matrix();

    if(noise) std::srand(std::time(nullptr));

    for (int r = 0; r < rows; r++)
    {
        m->push_back(vector<int>());
        for (int c = 0; c < cols; c++)
        {
            (*m)[r].push_back( noise ? (std::rand()%10) : EMPTY);
        }
        
    }

    return m;
}

int max_path(matrix* m){  // simpler interface for actual algorithm
    
    matrix* memo = gen_matrix((*m).size(), (*m)[0].size(), false);    

    return max_path(m, memo, 0, 0);
}


void print(matrix* m){
    for (int r = 0; r < (*m).size(); r++)
    {
        for (int i = 0; i < (*m)[0].size(); i++)
        {
            cout << (*m)[r][i] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}


int main(){

    int ROWS = 50;
    int COLS = 50;
    matrix* m = gen_matrix(ROWS, COLS, true);
    
    cout << ROWS << " x " << COLS << " grid.\n";
    cout << "Amount of possible paths = Permutation of " << ROWS + COLS << " with repetition of " << ROWS << " and " << COLS << '\n';
    cout << " = " << ROWS+COLS << "! / (" << ROWS << "!*" << COLS << "!) \n";
    
    cout << '\n';
    print(m);
    cout << '\n';

    cout << max_path(m);

    
    return 0;
}