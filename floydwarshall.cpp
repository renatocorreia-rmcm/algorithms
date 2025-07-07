#include <iostream>
#include <climits>
using namespace std;


#define INFINITY INT_MAX / 2
const int V = 4;


void floydwarshall(int graph[V][V]) {
    int dp[V + 1][V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dp[0][i][j] = graph[i][j];

    for (int k = 1; k <= V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++) {

                if (
                    dp[k-1][i][k-1] < INFINITY 
                    && dp[k-1][k-1][j] < INFINITY
                    )
                {
                    dp[k][i][j] = min(dp[k-1][i][j], dp[k-1][i][k-1] + dp[k-1][k-1][j]);
                }

                else
                {
                    dp[k][i][j] = dp[k-1][i][j];
                }
            }

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = dp[V][i][j];
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
