#include <iostream>
#include <vector>
#include <queue>

#define inf 1e5

using namespace std;



struct edge{
    int a;
    int b;
    int w;

    bool operator<(const edge& b) const{
        return this-> w < b.w;
    }
    bool operator>(const edge& b) const{
        return this-> w > b.w;
    }

    edge(){};
    edge(int a, int b, int w): a(a), b(b), w(w) {};
};

typedef vector<vector<edge>> graph;  // adjacency list



vector<int> prim(const graph& g){

    // setup parameters

    int vertices = g.size();

    vector<bool> visited(vertices, 0);
    vector<int> distances(vertices, inf);
    vector<int> parent(vertices, -1);
    priority_queue<edge, vector<edge>, greater<edge>> h;


    h.push({0,0,0}); distances[0] = 0;
    // iterate over each vertice
    for (int i = 0; i < vertices; i++)
    {

        // get smaller unvisited edge on fringe

        edge edge;
        do
        {
            if (h.empty()) return parent;  // no more unvisited edge on fringe
            
            edge = h.top(); h.pop();


        } while (visited[edge.b]);
        
        int p = edge.a;
        int v = edge.b;


        // mark it
        visited[v] = 1;
        parent[v] = p;


        // neighbors
        for (const struct edge& e : g[v])
        {
            int nb = e.b;
            if (!visited[nb] && distances[nb] > e.w)
            {
                distances[nb] = e.w;
                h.push({v, nb, distances[nb]});
            }
            
        }
        
        
    }

    return parent; 



}




int main(){


    int vertices; cin >> vertices;
    int edges; cin >> edges;

    graph g(vertices);


    for (int e = 0; e < edges; e++)
    {
        int a; cin >> a;
        int b; cin >> b;
        int w; cin >> w;

        g[a].push_back({a, b, w});
        g[b].push_back({b, a, w});
    }
    

    vector<int> parents = prim(g);


    for (int& p: parents)
    {
        cout << p << ' ';
    } cout << '\n';


    





    return 0;
}
