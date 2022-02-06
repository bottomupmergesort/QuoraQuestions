#include <iostream>
using namespace std;

class Graph {
    private:
    int **adjMatrix;
    int _v;
    public:
    Graph(int v = 5)
    {
        _v = v;
        adjMatrix = new int*[v];
        for (int i = 0; i < v; i++)
        {
            adjMatrix[i] = new int[v];
            for (int j = 0; j < v; j++)
                adjMatrix[i][j] = 0;
        }
    }
    int V()
    {
        return _v;
    }
    void addEdge(int v, int u, int wt)
    {
        adjMatrix[v][u] = wt;
        adjMatrix[u][v] = wt;
    }
    void showGraph()
    {
        for (int i = 0; i < _v; i++) 
        {
          for (int j = 0; j < _v; j++)
          {
              cout<<adjMatrix[i][j]<<" ";
          }
          cout<<endl;
        }
    }
    int* adj(int v)
    {
        return adjMatrix[v];
    }
};

void dfs(Graph& g, int curr, bool visited[], int& cost)
{
    cout<<curr<<" ";
    visited[curr] = true;
    int* neighbors = g.adj(curr);
    for (int i = 0; i < g.V(); i++)
    {
        if (!visited[i] && neighbors[i] != 0)
        {
            cost += neighbors[i];
            dfs(g, i, visited, cost);
        }
    }
}

void connectedComponentCost(Graph& g, int W)
{
    bool *visited = new bool[g.V()];
    for (int i = 0; i < g.V(); i++)
      visited[i] = false;
    int cost = 0;
    int numcomponents = 0;
    for (int i = 0; i < g.V(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            cout<<"Vertexes in Connected Component: ";
            dfs(g, i, visited, cost);
            cout<<"\nCost of connected component"<<++numcomponents<<": "<<cost<<"\n";
            if (cost == W)
            {
                cout<<"Component "<<numcomponents<<" meets our criteria of edge weight "<<W<<"\n";
            }
            cost = 0;
        }
    }
}

int main()
{
    Graph g(9);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 3, 3);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 5);
    g.addEdge(7, 8, 5);
    g.addEdge(4, 5, 7);
    g.addEdge(4, 6, 5);
    g.addEdge(5, 6, 5);
    g.showGraph();
    connectedComponentCost(g, 12);
    return 0;
}