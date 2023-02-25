#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<int> &arcpoints, unordered_map<int, vector<int>> &adj)
{

    visited[node] = true;
    disc[node] = low[node] = timer++;
    int children = 0;
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;

        if (visited[child] == false)
        {
            dfs(child, node, timer, disc, low, visited, arcpoints, adj);
            low[node] = min(low[node], low[child]);

            if (low[child] >= disc[node] && parent != -1)
            {
                arcpoints[node] = 1;
            }
            children++;
        }
        else
        {
            low[node] = min(low[node], disc[child]);
        }
    }

    if (parent == -1 && children > 1)
    {
        arcpoints[node] = 1;
    }
}

vector<int> ArticulationPoints(vector<pair<int, int>> &edges, int n)
{
    unordered_map<int, vector<int>> adj;
    for (auto i : edges)
    {
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }

    int timer = 0;
    vector<int> disc(n);
    vector<int> low(n);
    vector<bool> visited(n);
    vector<int> arcpoints(n);
    for (int i = 0; i < n; i++)
    {
        disc[i] = -1;
        low[i] = -1;
        visited[i] = false;
        arcpoints[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            dfs(i, -1, timer, disc, low, visited, arcpoints, adj);
        }
    }

    return arcpoints;
}

int main()
{
    vector<pair<int, int>> edges;
    int n = 5;
    edges.push_back({0, 3});
    edges.push_back({3, 4});
    edges.push_back({0, 4});
    edges.push_back({0, 1});
    edges.push_back({1, 2});

    vector<int> arculation_points = ArticulationPoints(edges, n);
    for (int i=0; i<n; i++)
    {
        if (arculation_points[i] != 0)
            cout << i << " ";
    }

    return 0;
}