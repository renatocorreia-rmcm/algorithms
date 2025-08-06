#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int v, const vector<vector<int>>& g, vector<bool>& visited, stack<int>& order) {
    visited[v] = true;
    
    // traverse all adjacent vertices
    for (int u : g[v]) { 
        if (!visited[u]) {
            dfs(u, g, visited, order);
        }
    }
    // exit recursion - add to order
    order.push(v);
}


vector<int> toposort(int n_vertices, const vector<vector<int>>& adjacency_list) {

    //int n_vertices = adjacency_list.size();

    // initialize all visiteds as unvisited
    vector<bool> visited(n_vertices, false);

    stack<int> order;
    // visit all vertices storing order
    for (int i = 0; i < n_vertices; ++i) {
        if (!visited[i]) {
            dfs(i, adjacency_list, visited, order);
        }
    }
    vector<int> result;
    // pop vertices from stack to get the order
    while (!order.empty()) {
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