/* this code created by Max Goren 1/4/2021
   and is freely available for use under the MIT License
   maxgoren@gmail.com
*/
#include <iostream>
using namespace std;

struct listnode {
    int label;
    listnode* next;
    listnode(int l, listnode* n)
    {
        label = l;
        next = n;
    }
    listnode()
    {
        label = 0;
        next = nullptr;
    }
};



class Graph {
    public:
    int N;
    listnode **adjList;
    Graph(int numV)
    {
        N = numV;
        adjList = new listnode*[N];
        for (int i = 0; i < N; i++)
           adjList[i] = nullptr;
    }
    void addEdge(int from, int to)
    {
        adjList[from] = new listnode(to, adjList[from]);
        adjList[to] = new listnode(from, adjList[to]);
    }
    void showGraph()
    {
        for (int i = 0; i < N; i++)
        {
            if (adjList[i] != nullptr)
            {
                cout<<i<<": ";
                for (listnode* itr = adjList[i]; itr != nullptr; itr = itr->next)
                {
                    cout<<itr->label<<" ";
                }
                cout<<endl;
            }
        }
    }
};

class DFSearch {
    private:
    bool *visited;
    bool found;
    public:
    DFSearch(Graph& G, int from, int to)
    {
        found = false;
        visited = new bool[G.N];
        for (int i = 0; i < G.N; i++)
          visited[i] = false;
        search(G, from, to);
        if (found)
        {
            cout<<"Search Succesful.\n";
        } else {
            cout<<"Search Failed.\n";
        }
    }
    void search(Graph& G, int from, int to)
    {
        if (found) return;
        cout<<"Visiting: "<<from<<"\n";
        if (from == to)
        {
            found = true;
            cout<<"Found "<<to<<"!\n";
            return;
        }
        visited[from] = true;
        for (listnode* adj = G.adjList[from]; adj != nullptr; adj = adj->next)
        {
            if (!visited[adj->label])
            {
                search(G, adj->label, to);
            }
        }
    }
};

int main()
{
    Graph G(5);
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 3);
    G.addEdge(2, 4);
    G.addEdge(2, 3);
    G.addEdge(3, 4);
    G.showGraph();
    DFSearch dfs(G, 0, 4);
    return 0;
}

