#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dis(n+1, 1e9);
    dis[src] = 0;

    //step 1: run the loop for n-1 times to calculate the shortest distance
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dis[u] != 1e9 && (dis[u] + w < dis[v])){
                dis[v] = dis[u] + w;
            }

        }
    }

    //step 2: run loop one last time to check for negative cycle, if any value updates then it exist;
    bool cycle = false;
    for(int j=0; j<m; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(dis[u] != 1e9 && (dis[u] + w < dis[v])){
            cycle = true;
            break;
        }

    }
    
    //if cycle exist then return -1;
    if(bool) return -1; 

    return dis[dest];

}