#include "dijkstra.h"

/*
* Base code was obtained from Dr. Hinkers classroom slides
*/

Dijkstra::Dijkstra (WeightedGraph *G, int s) : start (s)
{
    for (int i : G->Vertices())
    {
        dist[i] = std::numeric_limits<double>::infinity();
    }

    known[start] = true;
    prev[start] = 0;
    dist[start] = 0.0;
    pq.push (DijNode (start, 0.0));

    while (!pq.empty())
    {
        int v = pq.top().vertex;
        pq.pop();


        for (Edge e: G->adj(v))
            relax(v,e);
    }
}

void Dijkstra::relax (int v, Edge e)
{
    int w = e.other(v);
    
    if (dist[w]> dist[v]+e.Weight())
    {
        dist[w] = dist[v] + e.Weight();
        pq.push(DijNode(w,dist[w]));
        known[w] = true;
        prev[w] = v;
    }
}

bool Dijkstra::hasPath(int v)
{
    return known[v];
}

std::list<int> Dijkstra::pathTo(int end)
{
   std::list<int> path;
   if (!hasPath(end)) return path;
   for (int x = end ; x != start ; x = prev[x])
        path.push_front(x);

   path.push_front(start);
   return path;
}

double Dijkstra::distance (int v)
{
    return dist[v];
}