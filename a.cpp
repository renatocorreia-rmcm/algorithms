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




int bfs(graph g, int source, int target){

    int vertices = g.size();

    vector<bool> visited(vertices, 0);
    vector<int> parents(vertices, -1);

    
    visited[source] = 1;
    parents[source] = source;

    int layer = 1;

    queue<int> q;
    q.push(source);
    q.push(-1);  // end of layer

    while (q.size() > 0)
    {
        
        // get node v to analyse
        int v = q.front();
        q.pop();
        
        if(v == -1){  // end of layer
            layer++;
            // getting actual next node
            v = q.front();
            q.pop();
            q.push(-1);
        }      

        int nb;
        for (edge e: g[v])
        {
            nb = e.b;
            if (!visited[nb])
            {
                visited[nb] = 1;
                parents[nb] = e.a;  // from wich transformation it is borned
                
                q.push(nb);
                if (nb == target)
                {
                    return layer;
                }
                
            }
        }

    }

    return -1;
}



int main(){

    int test_cases; cin>>test_cases;

    for (int t = 0; t < test_cases; t++)
    {
        graph g;

        int vertices; cin>>vertices;
        int edges; cin>>edges;
        
        int s; cin>>s;
        int target; cin>>target;

        for (int e = 0; e < edges; e++)
        {
            int a; cin >> a;
            int b; cin >> b;
            int w; cin >> w;
            g[a].push_back({a,b,w});
        }
        
    }
    




    return 0;
}