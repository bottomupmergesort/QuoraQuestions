/*
MIT License

Copyright (c) 2022 Max Goren - maxgoren@gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

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

