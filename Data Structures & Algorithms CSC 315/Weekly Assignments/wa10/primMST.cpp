#include"primMST.h"

/*
* Base code was obtained from Dr. Hinkers classroom slides
*/


PrimMST::PrimMST(WeightedGraph *g, int s)
{
    visit(g,s);
    while (!minHeap.empty())
    {
        Edge e = minHeap.top();
        minHeap.pop();
       
        int v = e.either(), w=e.other(v);
       
        if (marked[v]&&marked[w])
            continue;
        
        mst.push_back(e);

        if (!marked[v]) visit(g,v);
        if (!marked[w]) visit(g,w);
    }
}

void PrimMST::visit (WeightedGraph *g, int v)
{
    marked[v]= true;
    
    for(Edge e : g->adj(v))
        if (!marked[e.other(v)])
            minHeap.push(e);
}

std::vector<Edge> PrimMST :: Edges() 
{
    return mst;
}

double PrimMST :: Weight() const
{
    return weight;
}