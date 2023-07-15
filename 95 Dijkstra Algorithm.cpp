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
    // You can also do this using min heap

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

// Dijkstra Algorithm using Min _heapadd
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    unordered_map<int,vector<pair<int,int>>> adj;
    vector<int> distance(vertices, INT_MAX);
    for(auto i:vec){
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> st; //->distance and node
    st.push({source, 0});
    distance[source] = 0;

    while(!st.empty()){

        auto top = st.top();
        st.pop();
        int dis = top.first;
        int node = top.second;

        for(auto child:adj[node]){
            if(distance[child.first] > child.second + dis){  // child.second + dis means dis->node tk aane ka expense + node se child tk ka aane ka expense
                distance[child.first] = child.second + dis;
                st.push({distance[child.first], child.first});
            }
        }
    }

    return distance;

}
