class Solution {
public:
    int answer;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        answer = -1;

        unordered_map<pair<int,pair<int,int>>> adj;

        for(auto &i: flights){
            adj[i[0]].push_back({i[1],i[3]});
        }

        vector<int> parent(n,-1);
        vector<bool> mst(n,false);
        vector<int> key(n,INT_MAX);

        key[src] = 0;
        parent[src] = -1;

        int n = adj.size(); 

        for(int i=0; i<n; i++){
            int mini = INT_MAX;
            int u;

            for(int v=0; v<n; v++){
                if(mst[v] == false && key[v] < mini){
                    u = v;
                    mini = key[v];
                }
            }

            mst[u] = true;

            for(auto it:adj[u]){
                int v = it.first;
                int w = it.second;
                if(mst[v] == false && w < key[v]){
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }

    }
};