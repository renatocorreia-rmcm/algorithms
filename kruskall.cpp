#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



struct edge{
    int a;
    int b;
    int w;

    bool operator< ()

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

    sort(edges);


    

}





int main(){











    return 0;
}