#include<bits/stdc++.h> 
using namespace std; 

void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 

void bfs(vector<int> adj[],int src,bool visited[])
{	
	queue<int> q;
	q.push(src);
	
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		if(!visited[curr])
		{
			cout<<curr<<" ";
			visited[curr] = true;
			
		}

		for(auto edge : adj[curr])
		{
			if(!visited[edge])
			{
				q.push(edge);
			}
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

	memset(visited,false,sizeof(visited));
	bfs(adj,0,visited);
    return 0; 
} 