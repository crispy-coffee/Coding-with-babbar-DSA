#include <bits/stdc++.h>

vector<int> dis, low, vis;

void dfs(int node, int parent, int &timer, unordered_map<int, vector<int>> &ad,
         vector<vector<int>> &result)
{
    vis[node] = true;
    dis[node] = low[node] = timer++;
    for (auto child : ad[node])
    {
        if (child == parent)
            continue;

        if (vis[child] == false)
        {
            dfs(child, node, timer, ad, result);
            low[node] = min(low[node], low[child]);

            if (low[child] > dis[node])
            {
                result.push_back({node, child});
            }
        }
        else
        {
            low[node] = min(low[node], dis[child]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{

    unordered_map<int, vector<int>> ad;
    for (auto i : edges)
    {
        ad[i[0]].push_back(i[1]);
        ad[i[1]].push_back(i[0]);
    }

    vector<vector<int>> result;
    dis.resize(v), low.resize(v), vis.resize(v);
    for (int i = 0; i < v; i++)
    {
        dis[i] = -1;
        low[i] = -1;
        vis[i] = false;
    }
    int parent = -1;
    int timer = 0;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, timer, ad, result);
        }
    }

    return result;
}