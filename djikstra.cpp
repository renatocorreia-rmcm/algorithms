#include <iostream>
#include <vector>
#include <queue>

#define inf 100000

using namespace std;


typedef pair<int, int> pii; // (distance, node)


vector<int> dijkstra(int n, const vector<vector<pii>>& adj, int source) {
    // Initialize distances to all nodes as infinity
    vector<int> dist(n, inf);
    // Min-heap priority queue to select the node with the smallest distance
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source] = 0;
    pq.push({0, source});

    //process nodes in order of increasing distance
    while (!pq.empty()) {
        int d = pq.top().first;   // Current distance
        int u = pq.top().second;  // Current node
        pq.pop();

        // Skip if we have already found a better path
        if (d > dist[u]) continue;

        // Explore all neighbors of the current node
        for (const auto& edge : adj[u]) {
            int v = edge.first;   // Neighbor node
            int w = edge.second;  // Edge weight
            // If a shorter path to v is found
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// Example usage
int main() {
    int n = 5;
    vector<vector<pii>> adj(n);
    // adj[u].push_back({v, weight});
    adj[0].push_back({1, 10});
    adj[0].push_back({2, 3});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 2});
    adj[2].push_back({1, 4});
    adj[2].push_back({3, 8});
    adj[2].push_back({4, 2});
    adj[3].push_back({4, 7});
    adj[4].push_back({3, 9});

    
    vector<int> dist = dijkstra(n, adj, 0);


    for (int i = 0; i < n; ++i) {
        cout << "Distance from 0 to " << i << ": " << dist[i] << endl;
    }
    return 0;
}