#include<iostream>
using namespace std;

class Graph {
	int v;
	int e;
	int** adj;

public:
	Graph(int v, int e);
	void adjMatrix();
	void display();

};

Graph::Graph(int v, int e) {
	this->v = v;
	this->e = e;
	adj = new int* [v];
	for (int i = 0; i < v; i++) {
		adj[i] = new int[v];
		for (int j = 0; j < v; j++) {
			adj[i][j] = 0;
		}
	}
};

void Graph::adjMatrix() {
	int a, b;
	for (int i = 0; i < this->e; i++) {
		cout << "Enter the starting and ending vertices of edge " <<i+1<<" : ";
		cin >> a >> b;
		this->adj[a][b] = this->adj[b][a] = 1;
	}
};

void Graph::display() {
	cout << "Your Adjacency Matrix is \n";
	for (int i = 0; i < this->v; i++) {
		for (int j = 0; j < this->v; j++) {
			cout << adj[i][j] << "\t";
		}
		cout << endl;
	}
};

int main() {
	Graph g(5,7);
	g.adjMatrix();
	g.display();

	return 0;
}