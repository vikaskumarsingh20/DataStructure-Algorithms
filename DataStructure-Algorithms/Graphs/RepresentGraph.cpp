#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class graph
{

public:
    unordered_map<int, list<int>> adj;
    void addEdges(int u, int v, bool direction)
    {
        // direction 0 undirected
        // direction 1 directed

        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{

    graph g;
    cout << "Enter no. of Nodes" << endl;                       
    int n;
    cin >> n;

    cout << "Enter the no. Edges" << endl;
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g.addEdges(u, v, 0);
    }

    g.printAdjList();
    return 0;
}

/*  OUTPUT FOR THE ABOVE CODE undorected gragh

Enter no. of Nodes
5
Enter the no. Edges
6
0 1
1 2
2 3
3 1
3 4
4 0
4->3 0
3->2 1 4
2->1 3
1->0 2 3
0->1 4
*/