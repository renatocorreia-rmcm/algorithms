#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int v, const vector<vector<int>>& adjacency_list, vector<bool>& visited, stack<int>& order) {  // v: index of current vertex
    visited[v] = true;
    for (int u : adjacency_list[v]) { // traverse all adjacent vertices
        if (!visited[u]) {
            dfs(u, adjacency_list, visited, order);
        }
    }
    order.push(v);
}


vector<int> toposort(int n_vertices, const vector<vector<int>>& adjacency_list) {
    vector<bool> visited(n_vertices, false);
    stack<int> order;
    for (int i = 0; i < n_vertices; ++i) { // visit all vertices
        if (!visited[i]) {
            dfs(i, adjacency_list, visited, order);
        }
    }
    vector<int> result;
    while (!order.empty()) { // pop vertices from stack to get the order
        result.push_back(order.top());
        order.pop();
    }
    return result;
}

int main() {
    int n_vertices; cin>>n_vertices;
    int n_edges; cin>>n_edges;

    vector<vector<int>> adjacency_list(n_vertices);

    for (int i = 0; i < n_edges; ++i) {
        int u; cin>>u;  // source vertex
        int v; cin>> v;  // destination vertex
        adjacency_list[u].push_back(v);
    }

    vector<int> order = toposort(n_vertices, adjacency_list);
    
    for (int v : order) {
        cout << v << " ";
    }

    return 0;
}