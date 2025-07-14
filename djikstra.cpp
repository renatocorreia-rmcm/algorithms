#include <iostream>
#include <vector>
#include <queue>

#define inf 100000

using namespace std;


struct edge{
    int a;  // origin
    int b;  // destiny
    int w;  // weight

    bool operator<(const edge& e) const{
        return this->w < e.w;
    }
    bool operator>(const edge& e) const{
        return this->w > e.w;
    }

    edge(){};
    edge(int a, int b, int w): a(a), b(b), w(w){}
};


typedef vector<vector<edge>> graph;  // adjacency list



vector<int> dijkstra(graph g, int source) {

    // parameters
    
    int vertices = g.size();

    vector<bool> visited(vertices, 0);
    vector<int> parents(vertices, -1);
    vector<int> distance(vertices, inf);

    priority_queue<edge, vector<edge>, greater<edge>> h;
    

    // start at source
    distance[source] = 0;
    h.push({source, source, 0});

    // get v-nearest vertice from source
    for (int v = 0; v < vertices; v++)
    {
        // get smallest unvisited edge from heap
        edge e;
        do
        {
            if (h.empty()) return distance;
            
            e = h.top(); h.pop();
            
        } while (visited[e.b]);

        // mark it
        visited[e.b] = 1;
        parents[e.b] = e.a;

        // add its unvisited neighbors to heap
        for (edge neighbor: g[e.b])
        {
            int nb = neighbor.b;
            int nw = neighbor.w;

            if (!visited[nb] && distance[nb] > distance[e.b]+nw)
            {
                distance[nb] = distance[e.b] + nw;
                h.push({e.b, nb, distance[nb]});
            }
            
        }
        
        
    }

    return distance;
    
}



int main() {
    
    int vertices; cin >> vertices;
    int edges; cin >> edges;

    graph g(vertices);

    for (int e = 0; e < edges; e++)
    {
        int a; cin >> a;
        int b; cin >> b;
        int w; cin >> w;

        g[a].push_back({a,b,w});
    }


    int source = 0;

    vector<int> distances = dijkstra(g, source);  
    

    for (int v = 0; v < vertices; ++v) {
        cout << "Distance from " << source << " to " << v << ": " << distances[v] << '\n';
    }

    return 0;
}