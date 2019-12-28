#include<iostream>
#define MAX 10
using namespace std;

class Graph {
	int v;
	struct node {
		int data;
		struct node* next;
	}*adj[MAX];

public:
	Graph(int);
	void adjList();
	void display();
};

Graph::Graph(int v) {
	this->v = v;
	for (int i = 0; i < v; i++) {
		this->adj[i] = NULL;
	}
};

void Graph::adjList() {
	struct node* nn, * last;
	int n,val;
	for (int i = 0; i < this->v; i++) {
		last = NULL;
		cout << "Enter the number of neighbour of vertex " << i << " : ";
		cin >> n;
		for (int j = 0; j < n; j++) {
			cout << "Enter the connected vertex : ";
			cin >> val;
			nn = new struct node();
			nn->data = val;
			nn->next = NULL;
			if (this->adj[i] == NULL) {
				this->adj[i] = nn;
				last = nn;
			}
			else {
				last->next = nn;
				last = nn;
			}
		}
	}
};

void Graph::display() {
	struct node* temp;
	for (int i = 0; i < this->v; i++) {
		cout << "Vertex " << i << " : ";
		temp = this->adj[i];
		while (temp!= NULL) {
			cout << temp->data << " --> ";
			temp = temp->next;
		}
		cout << endl;
	}
};


int main() {
	Graph g(5);
	g.adjList();
	g.display();
	return 0;
}