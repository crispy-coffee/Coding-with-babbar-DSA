#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Graph
{

public:
    unordered_map<int, vector<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back({v, weight});
    }

    void printing()
    {
        for (auto i : adj)
        {
            cout << i.first << " : ";
            for (auto j : i.second)
            {
                cout << "[ " << j.first << " " << j.second << " ] ";
            }
            cout << endl;
        }
    }

    void printtopo(stack<int> s){

        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
    }

    void dfs(int node, stack<int> &topo, vector<bool> &visited)
    {
        visited[node] = true;

        for (auto child : adj[node])
        {
            if (!visited[child.first])
                dfs(child.first, topo, visited);
        }
        topo.push(node);
    }

    void finddistance(vector<int> &distance, stack<int> topo)
    {

        while (!topo.empty())
        {
            int node = topo.top();
            topo.pop();

            if (distance[node] != INT_MAX)
            {
                for (auto child : adj[node])
                {
                    if (distance[node] + child.second < distance[child.first])
                    {
                        distance[child.first] = distance[node] + child.second;
                    }
                }
            }
        }
    }
};

int main()
{

    Graph G;
    G.addEdge(0, 1, 5);
    G.addEdge(0, 2, 3);
    G.addEdge(1, 2, 2);
    G.addEdge(1, 3, 6);
    G.addEdge(2, 3, 7);
    G.addEdge(2, 4, 4);
    G.addEdge(2, 5, 2);
    G.addEdge(3, 4, -1);
    G.addEdge(4, 5, -2);

    G.printing();
    int n = 6;
    stack<int> s;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            G.dfs(i, s, visited);
        }
    }

    G.printtopo(s);

    vector<int> distance(n, INT_MAX);

    int src = 1;
    distance[src] = 0;

    G.finddistance(distance, s);

    cout << "Answer : ";
    for (auto i : distance)
    {
        cout << i << " ";
    }

    return 0;
}