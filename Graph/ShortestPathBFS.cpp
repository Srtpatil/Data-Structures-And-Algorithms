//This is shortest path algorithm using BFS for unweighted Graph

#include<iostream>
#include<vector>
#include<list>
#include<iterator>
using namespace std;

class Graph {
	int v;
	vector<int>* adj;

public:
	Graph(int);
	void adjList();
	void shortestPath(int);
};

Graph::Graph(int v) {
	this->v = v;
	this->adj = new vector<int>[this->v];
};

void Graph::adjList() {
	int n, val;
	for (int i = 0; i < this->v; i++) {
		cout << "Enter the number of neighbour of vertex " << i << " : ";
		cin >> n;
		for (int j = 0; j < n; j++) {
			cout << "Enter the connected vertex : ";
			cin >> val;
			this->adj[i].push_back(val);
		}
	}
};

void Graph::shortestPath(int s) {
	int* distance = new int[this->v];
	list<int> q;
	int u;
	vector<int>::iterator itr;
	for (int i = 0; i < this->v; i++) {
		distance[i] = -1;
	}
	distance[s] = 0;

	q.push_back(s);
	while (!q.empty()) {
		u = q.front();
		q.pop_front();
		for (itr = this->adj[u].begin(); itr != this->adj[u].end(); itr++) {
			if (distance[*itr] == -1) {
				distance[*itr] = distance[u] + 1;
				q.push_back(*itr);
			}
		}
	}

	for (int i = 0; i < this->v; i++) {
		cout << i << "\t" << distance[i] <<  endl;
	}
};

int main() {
	Graph g(6);
	g.adjList();
	g.shortestPath(0);
	return 0;
}