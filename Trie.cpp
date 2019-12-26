#include<iostream>
#include<string>
using namespace std;

struct TrieNode{
	struct TrieNode *children[26];
	bool isEndOfWord;
};

struct TrieNode *getNode(){
	struct TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;
	
	for(int i=0;i<26;i++){
		pNode->children[i]=NULL;
	}

	return pNode;
}


void insert(struct TrieNode *root, string key){
	struct TrieNode *temp = root;
	
	for(int i=0;i<key.length();i++){
		int index = key[i] - 'a';
		if(temp->children[index]==NULL){
			temp->children[index] = getNode();
		}
		temp = temp->children[index];
	}
	temp->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key){
	struct TrieNode *temp = root;
	for(int i=0;i<key.length();i++){
		int index = key[i]-'a';
		if(temp->children[index]==NULL){
			return false;
		}
		temp = temp->children[index];
	}
	return (temp!=NULL && temp->isEndOfWord);
}

int main(){
	/*int n;
	cout<<"Enter the number of strings : ";
	cin>>n;
	string key[n];
	struct TrieNode *root = getNode();
	for(int i=0;i<n;i++){
		cin>>key[i];
		insert(root,key[i]);
	}	
	
	string s;
	cout<<"Enter the string to be search : ";
	cin>>s;
	search(root, s)? cout << "Yes\n" : cout << "No\n"; 
    return 0;
    */
    
     string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
  
    struct TrieNode *root = getNode(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    // Search for different keys 
    search(root, "the")? cout << "Yes\n" : 
                         cout << "No\n"; 
    search(root, "these")? cout << "Yes\n" : 
                           cout << "No\n"; 
    return 0; 
}

