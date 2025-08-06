#include <iostream>
#include <climits>
using namespace std;


#define INFINITY INT_MAX / 2
const int V = 4;


void floydwarshall(int graph[V][V]) {
    int memo[V + 1][V][V];  // array of matrices to keep shortest pairs between vertices j and k walking at most i+1 edges


    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            memo[0][i][j] = graph[i][j];  // shortest distance walking at most 1 edge is the edge itself (if it exists, else: INFINITY)

    for (int i = 1; i <= V; i++)
        for (int j = 0; j < V; j++)
            for (int k = 0; k < V; k++) {

                if (
                    memo[i-1][j][k] < INFINITY 
                    && memo[i-1][][k] < INFINITY
                    )
                {
                    memo[i][j][k] = min(
                        memo[i-1][j][k],  // reuse best distance calculated so far
                        memo[i-1][j][i] + memo[i][i-1][k]  // new distance, from j->k = j->(i-1)->k
                        );
                }

                else
                {
                    memo[i][j][k] = memo[i-1][j][k];
                }
            }

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = memo[V][i][j];
}

int main() {
    int graph[V][V] = {
        {0,         INFINITY,   3,          INFINITY},
        {2,         0,          INFINITY,   INFINITY},
        {INFINITY,  7,          0,          1},
        {6,         INFINITY,   INFINITY,   0}
    };

    floydwarshall(graph);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INFINITY)
                cout << "INF ";
            else
                cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
