{
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int diameter(struct Node * tree);

int main()
{
  int t;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << diameter(root) << endl;
  }
  return 0;
}

}

int height(Node* node){
    if(node==NULL) {
        return 0;
    }
    int l=height(node->left);
    int r=height(node->right);
    if(l>r){
        return (l+1);
    }
    else {
        return (r+1);
    }
}
int diameter(Node* node)
{
   if(node==NULL){
       return 0;
   }
   int ld=diameter(node->left);
   int rd=diameter(node->right);
   int lh=height(node->left);
   int rh=height(node->right);
   
   return max(lh+rh+1,max(ld,rd));
}

