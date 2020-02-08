#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
void insert(Node *root,ll a1,ll a2,char lr){
    if(root==NULL)
        return;
    if(root->data==a1){
        switch(lr){
            case 'L':root->left=new Node(a2);
            break;
            case 'R':root->right=new Node(a2);
            break;
        }
    }
    else{
        insert(root->left,a1,a2,lr);
        insert(root->right,a1,a2,lr);
    }
}
void inorder(Node *root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool isCousins(Node *root,int a,int b);
int main() {
    
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        Node *root=NULL;
        while(n--){
            ll a1,a2;
            char lr;
            cin>>a1>>a2;
            cin>>lr;
            if(root==NULL){
                root=new Node(a1);
                switch(lr){
                    case 'L':root->left=new Node(a2);
                    break;
                    case 'R':root->right=new Node(a2);
                    break;
                }
            }
            else{
                insert(root,a1,a2,lr);
            }
        }
       
        ll a,b;
        cin>>a>>b;
        
        if(a==b){
            cout<<"0";
            continue;
        }
        isCousins(root,a,b)?cout<<"1":cout<<"0";
    }
	return 0;
}


int printans(Node* root,int t,int arr[],int *l){
    if(root==NULL){
        return 0;
    }
    if(root->data==t){
        return 1;
    }
    if(printans(root->left,t,arr,l) || printans(root->right,t,arr,l)){
        arr[(*l)]=root->data;
        (*l)=(*l)+1;
        return 1;
    }
    else{
        return 0;
    }
}
bool isCousins(Node *root, int x, int y)
{
    int arr1[1000];
    int arr2[1000];
    int s1=0,s2=0;
    printans(root,x,arr1,&s1);
    printans(root,y,arr2,&s2);
   if(s1<2 || s2<2){
       return 0;
   }
    if(s1==s2 && arr1[s1-3]!=arr2[s1-3]){
        return 1;
    }
    else {
        return 0;
    }
}
