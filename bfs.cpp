#include <iostream>
#include <queue>

using namespace std;



char matrix[2000][2000];  // constraints
char tranformations[2000][2000];  // wich transformation was done before reaching that point
int rows, cols;


void print(char m[2000][2000]){  // to print matrix or tranformations
    cout << '\n';
    for (int r=0; r<rows; r++){
        for (int c = 0; c < cols; c++)
        {
            
            cout << (m[r][c]=='\0'?'*':m[r][c]);
        }
        cout << '\n';
    }
    cout << '\n';
}


bool is_guard(char pixel){
    return (
        pixel=='^'  ||
        pixel=='>'  ||
        pixel=='v'  ||
        pixel=='<'
    );
}

bool is_inside(pair<int, int> p){
    return (
        p.first>=0
        && p.first<=rows-1
        && p.second>=0
        && p.second<=cols-1
    );
}


//           u,  r,  d,  l
int dr[] = {-1,  0, +1,  0};
int dc[] = { 0, +1,  0, -1};


int bfs(pair<int, int> start = {0,0}){

    int layer = 1;

    matrix[start.first][start.second] = 'o';  // VISITED
    tranformations[start.first][start.second] = 'o';  // origin

    queue<pair<int, int>> q;
    q.push(start);
    q.push({-1,-1});  // end of layer

    while (q.size() > 0)
    {
        
        // get node v to analyse
        pair<int, int> v = q.front();
        q.pop();
        
        if(v.first == -1 && v.second == -1){  // end of layer
            layer++;
            // getting actual next node
            v = q.front();
            q.pop();
            q.push({-1,-1});
        }
        
        // previsit func here


        // fill dv  (v neighboors)
        pair<int, int> dv[4];
        for (int d = 0; d < 4; d++) dv[d] = {v.first+dr[d], v.second+dc[d]};
        

        // traversing its neighboors w
        pair<int, int> w;
        for (int i = 0; i < 4; i++)
        {
            w = dv[i];
            if (is_inside(w) && (matrix[w.first][w.second] == '.'))  // visitable
            {
                matrix[w.first][w.second] = 'o';
                tranformations[w.first][w.second] = i+'0';  // from wich transformation it is borned
                
                q.push(w);
                if (w.first==rows-1 && w.second==cols-1)
                {
                    return layer;
                }
                
            }
        }
        // posvisit

    }

    return -1;
}


int main(){


    /*
        INPUT
    */

    cin >> rows;
    cin >> cols;

    if ((rows == 1) && (cols == 1))
    {
        char c; cin >> c;
        cout << 'X';
        return 0;
    }
    
    

    for (int r=0; r<rows; r++){
        for (int c = 0; c < cols; c++)
        {

            cin >> matrix[r][c];

        }
    }



    /*
        BUILD VISION WALLS
    */

    for (int r=0; r<rows; r++){
        for (int c = 0; c < cols; c++)
        {
            
            // UP WALL
            if (matrix[r][c] == '^')
            {
                int r_copy = r;
                while (r_copy>0 && !is_guard(matrix[r_copy-1][c]))
                {
                    matrix[r_copy-1][c] = 'B';  // BLOCKED
                    r_copy--;
                }
            }

            // RIGHT WALL
            else if (matrix[r][c] == '>')
            {
                int c_copy = c;
                while (c_copy<cols-1 && !is_guard(matrix[r][c_copy+1]))
                {
                    matrix[r][c_copy+1] = 'B';
                    c_copy++; 
                }
            }

            // DOWN WALL
            else if (matrix[r][c] == 'v')
            {
                int r_copy = r;
                while (r_copy<rows-1 && !is_guard(matrix[r_copy+1][c]))
                {
                    matrix[r_copy+1][c] = 'B';
                    r_copy++; 
                }
            }

            // LEFT WALL
            else if (matrix[r][c] == '<')
            {
                int c_copy = c;
                while (c_copy>0 && !is_guard(matrix[r][c_copy-1]))
                {
                    matrix[r][c_copy-1] = 'B';
                    c_copy--; 
                }
            }
            
        }
    }


    if (matrix[0][0]=='B')
    {
        cout << -1;
        return 0;
    }
    

    int result = bfs();
    
    if (result == -1)
    {
        cout << -1;
    }


    else
    {
        char out[rows][cols];
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                out[r][c] = is_guard(matrix[r][c])?matrix[r][c]:'.';
            }
        }

        int r = rows-1;
        int c = cols-1;
        out[r][c] = 'X';

        while (! (r==0 && c==0))
        {
            int t = tranformations[r][c]-'0'; // fazer reversa
            t = (t+2)%4;

            r+=dr[t];
            c+=dc[t];
            out[r][c] = 'X';
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << out[i][j];
            }
            cout << '\n';
            
        }
        
        
        
    }
    
    


    return 0;
}