#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int data; 
	Node *left, *right; 
}; 

Node* newNode(int data) 
{ 
	Node *temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Inserting a new Node. 
Node* insert(Node*& root, int data) 
{ 
	if (!root) 
		return newNode(data); 

	// Updating size of left subtree. 
	if (data <= root->data) { 
		root->left = insert(root->left, data); 
	} 
	else
		root->right = insert(root->right, data); 

	return root; 
} 

// Function to get Rank of a Node x. 
int c=0;
int same=0;
int found=-1;
int get(Node* root,int x)
{
  
	if(root==NULL) {
      return 0;
    }
    get(root->left,x);
  if(root->data==x)
  {
    same=1;
  }
  if(root->data==x){
  	found=1;
  }
  if(root->data<=x) {
    ++c;
    //printf("%d ",c );
  }
  get(root->right,x);
  if(found==-1){
  	return -1;
  }
  return c-same;
}
int getRank(Node* root, int x) 
{ 
  c=0;
  same=0;
  found=-1;
  return get(root,x);
} 
// Driver code 
int main() 
{ 
	int arr[] = { 5,2,1,3,4,7,6,8 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int x = 5; 

	Node* root = NULL; 
	for (int i = 0; i < n; i++) 
		root = insert(root, arr[i]); 

	cout << "Rank of " << x << " in stream is: "
		<< getRank(root, x) << endl; 

	x = 1; 
	cout << "Rank of " << x << " in stream is: "
		<< getRank(root, x) << endl; 

	x = 9; 
	cout << "Rank of " << x << " in stream is: "
		<< getRank(root, x) << endl; 
	return 0; 
} 
