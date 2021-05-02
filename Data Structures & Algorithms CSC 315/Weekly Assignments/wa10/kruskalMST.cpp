#include "kruskalMST.h"

/*
* Base code was obtained from Dr. Hinkers classroom slides
*/


KruskalMST :: KruskalMST(WeightedGraph *G)
{
    priority_queue <Edge, vector <Edge>, CompareEdge> minHeap;
    for (Edge e: G->Edges())
        minHeap.push(e);

    DisjointSet ds;

    for (int i : G->Vertices())
        ds.makeSet(i);

    while(!minHeap.empty() && mst.size() != (unsigned int)G->V()-1)
    {
        Edge e = minHeap.top();
        minHeap.pop();
        int v = e.either();
        int w = e.other(v);

        if (ds.Find(v) != ds.Find(w))
        {
            ds.Union(v,w);
            mst.push_back(e);
        }
    }
}

std::vector<Edge> KruskalMST :: Edges()
{
    return mst;
}

double KruskalMST :: Weight() const
{
    return weight;
}
