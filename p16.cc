#include<iostream>
using namespace std;

struct tree
{
  int data;
  struct tree *left;
  struct tree *right;
  int deep;
};

int deep=0;
int maxdeep=0;

struct tree *insert(struct tree *root,int key)
{
  struct tree *x,*y,*z;
  x=y=NULL;
  z=new struct tree;
  z->data=key;
  z->left=z->right=NULL;
  z->deep=0;
  x=root;
  while(x!=NULL)
  {
    y=x;
    if(x->data>key)
      x=x->left;
    else
      x=x->right;
  }
  if(x==root)
  {
    root=new struct tree;
    root->data=key;
    root->left=root->right=NULL;
    root->deep=1;
  }
  else
  {
    if(y->data>key)
     {
       y->left=z;
       z->deep=y->deep+1;
     }
    else
     {
       y->right=z;
       z->deep=y->deep+1;
     }
  }
  return root;
}

void print(struct tree *root)
{
  //cout<<"aaa\n";
  if(root==NULL)
    return;
  else
   {
     print(root->left);
     cout<<root->data<<"\t";
     print(root->right);
   }
}

void cal(struct tree *root)
{
  deep++;
  int leaf=!(root->left) && !(root->right);
  if(leaf)
   {
     //cout<<deep<<endl;
     if(maxdeep<deep)
       maxdeep=deep;
     deep--;
     return;
   }
  else
  {
   if(root->left)
    {
     cal(root->left);
    }
   if(root->right)
    cal(root->right);
  }
  deep--;
}

int main(void)
{
  int a[]={6,4,8,1,5,7,9,10};
  struct tree *root=NULL;
  int n;
  n=sizeof(a)/sizeof(int);
  for(int i=0;i<n;i++)
    root=insert(root,a[i]);
  print(root);
  cout<<endl;
  //cout<<root->left->right->data<<endl;
  cal(root);
  cout<<maxdeep<<endl;
  return 0;
}
