// Union by Rank and Path Compression

#include<iostream>
#include<map>
using namespace std;

struct Node{
	int data;
	int rank;
	Node *parent;
};

map<int,Node*> mp;

void make_set(int data){
	Node *node = new Node;
	node->data=data;
	node->rank=0;
	node->parent = node;
	mp[data]=node;
}

Node* find_set_util(Node *node){
	Node *parent = node->parent;
	if(parent == node){
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

int main(){
	make_set(1);
	make_set(2);
	make_set(3);
	make_set(4);
	make_set(5);
	make_set(6);
	make_set(7);
	
	union_set(1,2);
	union_set(2,3);
	cout<<find_set(3)<<endl;
}
