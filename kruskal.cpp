#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



struct edge{
    int a;
    int b;
    int w;

    bool operator< (edge const &e) const {
        return w < e.w;
    }
    bool operator> (edge const &e) const {
        return w > e.w;
    }   

    edge();
    edge(int a, int b, int w): a(a), b(b), w(w){}
};


typedef vector<vector<edge>> graph;


void kruskal(graph g){
    int vertices = g.size();
   
    graph g_(vertices);

    int edge_count = 1;
    
    vector<edge> edges;

    for (int v = 0; v < vertices; v++)
    {
        for (edge e: g[v])
        {
            int b = e.b;
            int w = e.w;

            edges.push_back({v, b, w});
        }
    }

    sort(edges.begin(), edges.end());

    vector<int> ds(vertices);

    int numMST = vertices;

    while (numMST > 1)
    {
        edge e = edges.back(); edges.pop_back();
        int a = e.a;
        int b = e.b;
        int w = e.w;

        if (ds.find(a) != ds.find(b))
        {
            union(ds, a, b);
            g_[a].push_back({a, b, w});
            numMST--;
        }
        
    }
}





int main(){











    return 0;
}