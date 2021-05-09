#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <list>
#include <unordered_map>
using namespace std;

class Graph
{
    int V;
    unordered_map<int, list<pair<int, int>>> l;

public:
    Graph(int V)
    {
        this->V = V;
    }

    int returnVertex()
    {
        return V;
    }

    void addEdge(int x, int y, int w, bool bidir)
    {
        l[x].push_back(make_pair(y, w));
        if (bidir)
        {
            l[y].push_back(make_pair(x, w));
        }
    }

    list<pair<int, int>> returnAdjList(int x)
    {
        return l[x];
    }
};

vector<int> dijkstra(int initial_node, int final_node, Graph &g)
{
    int V = g.returnVertex();
    vector<int> processed(V, 0);
    vector<int> parents(V, 0);
    vector<int> path;
    parents[initial_node] = initial_node;
    vector<int> distance(V, numeric_limits<int>::max());
    distance[initial_node] = 0;
    priority_queue<pair<int, int>> q;

    q.push(make_pair(0, initial_node));
    while (!q.empty())
    {
        int current_node = q.top().second;
        /*if (current_node == final_node)
            break;*/
        q.pop();
        if (processed[current_node])
            continue;
        processed[current_node] = 1;
        for (auto nbg : g.returnAdjList(current_node))
        {
            int node = nbg.first;
            int w = nbg.second;
            if (distance[current_node] + w < distance[node])
            {
                distance[node] = distance[current_node] + w;

                parents[node] = current_node;
                //cout << node << " distance: " << -distance[node] << ',';

                q.push(make_pair(-distance[node], node));
            }
        }
    }
    while (final_node != initial_node)
    {
        path.push_back(final_node);
        final_node = parents[final_node];
    }
    path.push_back(initial_node);

    return path;
}

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 5, true);
    g.addEdge(0, 2, 6, true);
    g.addEdge(1, 2, 2, true);
    g.addEdge(2, 3, 4, true);
    g.addEdge(1, 4, 1, true);
    g.addEdge(4, 3, 1, true);
    g.addEdge(1, 5, 0, true);
    g.addEdge(5, 3, 1, true);

    vector<int> d = dijkstra(5, 0, g);
    for (auto n : d)
    {
        cout << n << ' ';
    }

    return 0;
}