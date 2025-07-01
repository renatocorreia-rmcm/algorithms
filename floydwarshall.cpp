#include <iostream>


inline int min(int a, int b) {return b<a?b:a;}


/*
consider "dp" a 3d matrix to act as a memory
n (n x n)
a list of matrix where each matrix t=corresponds to a state

so dp[k][i][j] tells the minimun distance going from i to j considering only the nodes from 0 to break
so dp[n-1 is the solution]
*/


void floydwarshall(int* graph[], int V) {  // graph matrix: weights between node i to j without considering transitivity - considering only adjancencys

    int* dp[V][V];

    /*to k=0 (adjacent vertices)*/
    for (int i = 0; i<V; i++){
        for (int j = 0; j<V; j++){
            dp[0][i][j] = graph[i][j];  // if vertices are not adjacent, distance remain <infinity> 
        }
    }
    
    /* the rest of permutations */
    for (int k = 1; k<V; k++){
        for (int i = 0; i<V; i++){
            for (int j = 0; j<V; j++){
                // dp[k] is computed above dp[k-1]
                // at every dp[k] layer we test adding an adjancy to the path dp[k][i][j], but as we dont know exactly adjacencys (fringes) of dp[k-1][i] node, we test all dp[k-1][i][k]
                // consider fringe the adjancencys of a non ramified path
                dp[k][i][j] = min(  
                    dp[k-1][i][j],
                    dp[k-1][i][k] + dp[k-1][k][j]
                );
                
                
            }
        }
    }
}


int main()
{






	return 0;
}
