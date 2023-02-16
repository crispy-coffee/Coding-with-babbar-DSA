#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    unordered_map<int,vector<pair<int,int>>> aj;

    for(auto i:vec){
        int u = i[0];
        int v = i[1];
        int w = i[2];

        aj[u].push_back({v,w});
        aj[v].push_back({u,w});
    }

    vector<int> distance(vertices,INT_MAX);

    distance[source] = 0;

    set<pair<int,int>> s;
    s.insert({distance[source],source});

    while(!s.empty()){
        auto top = *(s.begin());
        s.erase(top);

        int distancenode = top.first;
        int node = top.second;

        for(auto child : aj[node]){
            if(distancenode + child.second < distance[child.first]){

              auto record = s.find({distance[child.first], child.first});

              if (record != s.end())
                s.erase(record);

              distance[child.first] = distancenode + child.second;
              s.insert({distance[child.first],child.first});
            }
        }
    }

    return distance;

}
