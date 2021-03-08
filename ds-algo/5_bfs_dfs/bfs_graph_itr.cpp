#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
    int src, dest;
};

class Graph
{
    public:
        vector< vector< int > > adjList;

        Graph(vector<Edge> const &edges, int N)
        {
            adjList.resize(N);

            for (auto &edge: edges)
            {
                adjList[edge.src].push_back(edge.dest);
                adjList[edge.dest].push_back(edge.src);
            }
        }
};

void BFS(Graph const &graph, int v, vector<bool> &discovered)
{
    // create a queue for doing BFS
    queue<int> q;

    // mark the source vertex as discovered
    discovered[v] = true;
    // enqueue the source vertex
    q.push(v);

    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node and print it
        v = q.front();
        q.pop();
        cout << v << " ";

        for (int u: graph.adjList[v])
        {
            if (!discovered[u])
            {
                discovered[u] = true;
                q.push(u);
            }
        }
    }
}

int main()
{
    vector< Edge > edges = {
        {1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
        {5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
    };

    int N = 15;

    Graph graph(edges, N);

    vector<bool> discovered(N, false);

    for (int i = 0; i < N; i++)
    {
        if (discovered[i] == false)
        {
            BFS(graph, i, discovered);
        }
    }
    
    return 0;
}

