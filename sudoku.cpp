#include <iostream>
#include <vector>

using namespace std;


int grid[9][9];

bool* get_possibilities(int r, int c){
    bool* possibilities = new bool[9];
    for (int i = 0; i < 9; i++) possibilities[i] = 1;
    
    
    for (int i = 0; i < 9; i++)
    {
        if (grid[r][i] != 0)  // check horizontal values
        {
            possibilities[grid[r][i]-1] = 0;
        }        
        if (grid[i][c] != 0)  // check vertical values
        {
            possibilities[grid[i][c]-1] = 0;
        }        
        
    }

    /* check square values */
    int row_margin = (r/3)*3;
    int col_margin = (c/3)*3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i+row_margin][j+col_margin] != 0){

                possibilities[grid[i+row_margin][j+col_margin]-1] = 0;
                
            }
        }
        
    }

    return possibilities;

}

bool all_false(bool* possibilities){
    for (int i = 0; i < 9; i++)
    {
        if (possibilities[i])
        {
            return false;
        }
        
    }
    return true;
}

bool sudoku(){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j]==0)
            {
                bool* possibilities = get_possibilities(i,j);
                if (all_false(possibilities))
                {
                    return false;
                }
                
                for (int k = 0; k < 9; k++)
                {
                    if (possibilities[k])
                    {
                        grid[i][j] = k+1;
                        bool r = sudoku();
                        grid[i][j] = 0;
                        return r;                        
                    }
                    
                }
                
                
            }
            
        }      
    }
    return true;
    
}



int main(){




    int t; cin >> t;


    while (t--)
    {
        
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> grid[i][j];
            }
        }
        cout << '\n';

        if (sudoku)
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    cout << grid[i][j] << ' ';
                }
                cout << '\n';
            }
            cout << '\n';
            
        }
        

    }
    






    return 0;
}