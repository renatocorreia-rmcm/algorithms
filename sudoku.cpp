#include <iostream>
#include <vector>

using namespace std;


int grid[9][9];

vector<int>* get_possibilities(int r, int c){
    bool* possibilities = new bool[10];
    
    for (int i = 0; i < 9; i++) possibilities[i] = 1;
    
    /* remove from possibilities values already in grid subset */
    for (int i = 0; i < 9; i++)
    {
        possibilities[grid[r][i]-1] = 0;      
        possibilities[grid[i][c]-1] = 0;        
    }
    /* check square values */
    int row_margin = (r/3)*3;
    int col_margin = (c/3)*3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            possibilities[grid[i+row_margin][j+col_margin]-1] = 0;
        }
        
    }

    vector<int>* result = new vector<int>();
    for (int i = 1; i <= 9; i++){
        if (possibilities[i])
        {
            result->push_back(i);
        }
        
    }
    return result;

}

bool sudoku(){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j]==0)
            {
                vector<int>* possibilities = get_possibilities(i,j);
                
                if (possibilities->empty()) return false;
                
                for (int n: *possibilities)
                {
                    grid[i][j] = n;
                    if (sudoku()) return true;
                    grid[i][j] = 0;                                 
                }
                delete possibilities;                
                return false;
            }
            
        }      
    }
    return true;
    
}

void print(){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    
}


int main(){




    int t; cin >> t;


    while (t--)
    {
        
        /* INPUT */
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> grid[i][j];
            }
        }
        cout << '\n';

        
        /* SOLVE AND PRINT */
        if (sudoku()) print();

        else cout << "No solution" << '\n';
        
        

    }
    






    return 0;
}