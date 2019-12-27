// Implementation by using Priority Queue

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

#define PII pair<int,int>
#define MAXN 1000009

bool visited[MAXN];
vector<PII> graph[MAXN];

int prim(int src){
	int minCost=0;
	memset(visited,false,sizeof(visited));
	priority_queue<PII,vector<PII>,greater<PII>> pq;
	pq.push({src,0});
	while(!pq.empty()){
		PII p = pq.top();
		pq.pop();
		int u = p.first;
		if(visited[u]){
			continue;
		}
		minCost+=p.second;
		visited[u]=true;
		for(auto v : graph[u]){
			if(!visited[v.first]){
				pq.push(v);
			}
		}
	}
	return minCost;
}

int main(){
	int vertex,edge;
	cin>>vertex>>edge;
	int u,v,wt;
	for(int i=0;i<edge;i++){
		cin>>u>>v>>wt;
		graph[u].push_back({v,wt});
		graph[v].push_back({u,wt});
	}
	
	cout<<prim(1)<<endl;
	return 0;
}	
