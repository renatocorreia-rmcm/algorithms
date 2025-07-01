#include <iostream>


/*
consider "dp" a 3d matrix to act as a memory
n (n x n)
a list of matrix where each matrix t=corresponds to a state

so dp[k][i][j] tells the minimun distance going from i to j considering only the nodes from 0 to break
so dp[n-1 is the solution]
*/

void floydwarshall(int graph[][]) {  // grap matrix: 0 for diagonal, <infinity> for the rest

    /*to k=0*/
    // (adjacent vertices)
    for (int i = 0, i<V, i++){
        for (int j = 0, j<V, j++){
            dp[0][i][j] = m[i][j];  // if vertices are not adjacent, distance remain <infinity> 
        }
    }
    
    /* the rest of permutations */
    for (int k = 1, k<V, k++){
        for (int i = 0, i<V, i++){
            for (int j = 0, j<V, j++){
                
                
                
            }
        }
    }
}


int main()
{






	return 0;
}
