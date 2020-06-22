
#include <bits/stdc++.h> 
using namespace std; 


struct node 
{ 
	struct node *left; 
	int data; 
	struct node *right; 
}; 


void levelOrder(node *root) 
{ 
	if (root == NULL) return; 

	
	queue<node *> q; 
	
	
	node *curr; 

	q.push(root); 
	q.push(NULL); 

	while (q.size() > 1) 
	{ 
		curr = q.front(); 
		q.pop(); 
	
		if (curr == NULL) 
		{ 
		q.push(NULL); 
		cout << "\n"; 
		} 
		
		else { 
			
		
			if(curr->left) 
			q.push(curr->left); 
			
			
			if(curr->right) 
			q.push(curr->right); 
			
			cout << curr->data << " "; 
		} 
	} 
} 


node* newNode(int data) 
{ 
	node *temp = new node; 
	temp->data = data; 
	temp->left = NULL; 
	temp->right = NULL; 
	return temp; 
} 


int main() 
{ 
	

	node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->right = newNode(6); 

	levelOrder(root); 
	return 0; 
} 


