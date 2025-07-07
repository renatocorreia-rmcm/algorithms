#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// Edge structure: destination and weight
struct Edge {
    int to;
    int weight;
};

// Min-heap item: (distance, parent, vertex)
struct Item {
    int dist, parent, vertex;
    bool operator>(const Item& other) const {
        return dist > other.dist;
    }
};

void dijkstra(int s, const vector<vector<Edge>>& G, vector<int>& D, vector<int>& P) {
    int n = G.size();
    vector<bool> visited(n, false);
    D.assign(n, INF);
    P.assign(n, -1);

    // Min-heap: (distance, parent, vertex)
    priority_queue<Item, vector<Item>, greater<Item>> H;

    D[s] = 0;
    H.push({0, s, s});

    for (int i = 0; i < n; ++i) {
        Item item;

        // Step 6–9: Find unvisited node with smallest distance
        do {
            if (H.empty()) return;
            item = H.top(); H.pop();
        } while (visited[item.vertex]);

        int v = item.vertex;
        visited[v] = true;
        P[v] = item.parent;

        // Step 11–16: Update neighbors
        for (const Edge& e : G[v]) {
            int w = e.to;
            int weight_vw = e.weight;
            if (!visited[w] && D[w] > D[v] + weight_vw) {
                D[w] = D[v] + weight_vw;
                H.push({D[w], v, w});
            }
        }
    }
}


int main(){

    





    return 0;
}