//  Implemenation using disjoint set (union by rank and path compression)

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
	int data;
	int rank;
	Node *parent;
};

map<int,Node*> mp;

void make_set(int data){
	Node *node = new Node;
	node->data = data;
	node->rank = 0;
	node->parent = node;
	mp[data] = node;
}

Node* find_set_util(Node *node){
	Node *parent = node->parent;
	if(parent==node){
		return parent;
	}
	node->parent = find_set_util(node->parent);
	return node->parent;	
}

void union_set(int data1, int data2){
	Node *node1 = mp[data1];
	Node *node2 = mp[data2];
	
	Node *parent1 = find_set_util(node1);
	Node *parent2 = find_set_util(node2);
	
	if(parent1->rank < parent2->rank){
		parent1->parent = parent2;
	}
	else if(parent1->rank > parent2->rank){
		parent2->parent = parent1;
	}
	else{
		parent2->parent = parent1;
		parent1->rank++;
	}
}

int find_set(int data){
	return find_set_util(mp[data])->data;
}
struct Edge{
	int u;
	int v;
	int weight;
	bool operator<(Edge const &other){
		return weight < other.weight; 
	}
};

vector<Edge> graph;
vector<Edge> resultPath;
int minCost=0;
int vert,ed;

void make_edge(int u, int v, int wt){
	Edge e;
	e.u = u;
	e.v = v;
	e.weight = wt;
	graph.push_back(e);
}

void krushkal(){
	for(int i=0;i<vert;i++){
		make_set(i);
	}
	
	sort(graph.begin(),graph.end());
	
	for(Edge e : graph){
		if(find_set(e.u)!=find_set(e.v)){
			minCost+=e.weight;
			resultPath.push_back(e);
			union_set(e.u,e.v);
		}
	}
}

int main(){
	cin>>vert>>ed;
	int u,v,wt;
	for(int i=0;i<ed;i++){
		cin>>u>>v>>wt;
		make_edge(u,v,wt);
	}
	
	krushkal();
	
	cout<<minCost<<endl;
	return 0; 
}
