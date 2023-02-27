#include<bits/stdc++.h>
void dfs(int node, vector<bool> &visited, stack<int> &st,
unordered_map<int,vector<int>> &adj ){

	visited[node] = true;

	for(auto child: adj[node]){
		if(visited[child] == false){
			dfs(child, visited, st, adj);
		}
	}

	st.push(node);

}

void revdfs(int node, vector<bool> &visited,unordered_map<int, vector<int>> &tran){

	visited[node] = true;

	for(auto child : tran[node]){
		if(visited[child] == false){
			revdfs(child, visited, tran);
		}
	}

}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int,vector<int>> adj;
	vector<bool> visited(v+1,false);
	for(int i=0; i<edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}

	stack<int> st;
	
	//topological sort
	for(int i=0; i<v; i++){
		if(visited[i] == false){
			dfs(i, visited, st, adj);
		}
	}

	//transpose the adjacency list 
	unordered_map<int, vector<int>> tran;
	for(int i=0; i<v; i++){
		visited[i] = false;
		for(auto child: adj[i]){
			tran[child].push_back(i);
		}
	}

	int count=0;
	while(!st.empty()){
		int node = st.top();
		st.pop();
		if(visited[node] == false){
			count++;
			revdfs(node, visited, tran);
		}

	}

	return count;

}
