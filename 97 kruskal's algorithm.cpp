#include <algorithm>
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

void makeset(vector<int> &parent, vector<int> &rank, int n)
{

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{

    if (parent[node] == node)
    {
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}

void unionset(int u, int v, vector<int> &parent, vector<int> &rank)
{

    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{

    sort(begin(edges), end(edges), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent, rank, n);

    int maxweight = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int w = edges[i][2];

        if (u != v)
        {
            maxweight += w;
            unionset(u, v, parent, rank);
        }
    }

    return maxweight;
}
