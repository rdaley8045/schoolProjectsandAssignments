# include "maze.h"


Maze :: Maze (int width, int height)
{
    edges.resize(2*width*height);
    Cols = width;
    Rows = height;
    
    ds = new Disjoint (2*width*height);
}

Maze :: ~Maze ()
{
    edges.clear();
    delete ds;
}

bool Maze :: removeEdge(list<pair<int, int>> & group)
{
    int spot = rand ()% (2*Cols*Rows);
    pair <int,int> newEdge;

    newEdge = edges[spot];

    int x = newEdge.first;
    int y = newEdge.second;

    int u = ds->Find(x);
    int v = ds->Find(y);
    
    if (ds->setCount() > 1 )
    {
        ds->Union(u,v);
        edges.erase(edges.begin() + spot);
        return true;
    }

    return false;

   
}

std::vector<std::pair<int, int>> Maze :: edgeList()
{
    int position= 0;
    int index=0;
    
    for (int y = 0; y < Rows; y++)
    {
        for (int x = 0; x < Cols-1; x++)
        {
            edges[index].first =ds->Find(position);
            edges[index].second = ds->Find(position)+1;

            index++;
            position++;

        }
        position++;
        
        for (int w = 0; w < Cols && position < Rows * Cols; w++)
        {
            edges[index].first = ds->Find(position) - Cols;
            edges[index].second = ds->Find(position);
            index++;
            position++;
        }
        position -= Cols;
    }

    return edges;
}