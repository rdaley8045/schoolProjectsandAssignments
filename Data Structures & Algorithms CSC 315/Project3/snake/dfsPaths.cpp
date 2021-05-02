#include "dfsPaths.h"

DFSPaths::DFSPaths(SnakeGraph *G, int s) : s(s)
{
   dfs (G,s);
}

void DFSPaths::dfs(SnakeGraph *G, int v)
{
   marked[v] = true;

   for (int x : G->adj(v))
   {
      if (!marked[x])
      {
         dfs(G,x);
         prev[x] = v;
      }
   }
}

bool DFSPaths::hasPath(int v)
{
   return marked[v]; // this isn't right
}

std::list<int> DFSPaths::pathTo(int v)
{
   std::list<int> path;
   if (!hasPath(v)) return path;

   for (int x =v; x!=s; x = prev[x])
      path.push_front(x);
   
   path.push_front(s);
   return path;
}