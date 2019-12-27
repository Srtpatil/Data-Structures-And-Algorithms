#include<bits/stdc++.h> 
using namespace std; 

void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    //adj[v].push_back(u); 
} 
  
//recursive deapth first search
void rec_dfs(vector<int> adj[],int src,bool visited[])
{
	if(visited[src])
		return;
	
	cout<<src<<" ";
	visited[src] = true;
	
	for(auto edge : adj[src])
	{
		if(!visited[edge])
		{
			rec_dfs(adj,edge,visited);
		}
	}
}

void ite_dfs(vector<int> adj[],int src,bool visited[])
{
	stack<int> s;
	s.push(src);
	while(!s.empty())
	{
		int curr = s.top();
		s.pop();
		if(!visited[curr])
		{
			cout<<curr<<" ";
			visited[curr] = true;
			
		}
		for(auto edge : adj[curr])
		{
			if(!visited[edge])
				s.push(edge);
			
		}
	}
}
int main() 
{ 
    int V = 5; 
    vector<int> adj[V]; 
	bool visited[V];
	memset(visited,false,sizeof(visited));
    addEdge(adj,1, 0); 
    addEdge(adj,0, 2); 
    addEdge(adj,2, 1); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 4); 

    rec_dfs(adj,0,visited);
	cout<<"\n\n";
	memset(visited,false,sizeof(visited));
	ite_dfs(adj,0,visited);
    return 0; 
} 