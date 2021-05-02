#include "graph.h"

Graph::Graph() { }

Graph::Graph(istream &instream) : numVertices(0), numEdges(0)
{
   int v, w;
   while (!instream.eof())
   {
      instream >> v >> w;
      addEdge(v, w);
   }

   numVertices = vertices.size();
   for (int u : Vertices())
      numEdges += adj(u).size();

   numEdges /= 2;
}

Graph::Graph(const vector<vector<int>> &grid)
{
   int h = grid.size();
   int w = grid[0].size();

   for (int x = 0; x < h; x++)
   {
      for (int y = 0; y < w; y++)
      {
         int edge = x * w + y;
         if (!((x>=0 && x <h) && (y>=0 && y<w) && (grid[x][y] !=0)))
            continue;
         if ((x+1 >= 0 && x +1 < h) && (y>=0 && y < w) && (grid[x+1][y] !=0))
            addEdge(edge, edge+w);
         if ((x-1 >= 0 && x -1 < h) && (y>=0 && y < w) && (grid[x-1][y] !=0))
            addEdge(edge, edge - w);
         if ((x >= 0 && x < h) && (y+1>=0 && y+1 < w) && (grid[x][y+1] !=0))
            addEdge(edge+1, edge);
         if ((x>= 0 && x< h) && (y-1>=0 && y-1 < w) && (grid[x][y-1] !=0))
            addEdge(edge-1, edge);
      }
   }

   // You need to write the constructor that will take a 2-d grid of values
   // and change it into an adjacency list representation.
}
   
Graph::~Graph() {}

int Graph::V() const { return numVertices ; }
int Graph::E() const { return numEdges ; }

set<int> Graph::Vertices() const
{
   set<int> retVal;
   for (auto &kv : vertices)
      retVal.insert(kv.first);

   return retVal;
}

set<int> Graph::adj(int v)
{
   return vertices[v];
}

// This implementation of addEdge presumes the graph is undirected
void Graph::addEdge(int v, int w)
{
   vertices[v].insert(w);
   vertices[w].insert(v);
}
