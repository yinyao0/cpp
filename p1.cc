#include<iostream>
#include<string>
#include<stack>
using namespace std;

struct tree 
{
  int data;
  int count;
  struct tree *left;
  struct tree *right;
};

struct tree *insert(struct tree *root,int key)
{
   struct tree *x,*y,*z;
   z=new struct tree;
   z->data=key;
   z->count=0;
   z->left=z->right=NULL;
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
     root->count=0;
     root->left=root->right;
   }
   else
   {
     if(y->data>key)
      y->left=z;
     else 
      y->right=z;
   }
   return root;
}

void print(struct tree *root)
{
  if(root==NULL)
   return;
  else
   {
     //cout<<root->data<<"\t";
     print(root->left);
     //cout<<root->data<<"\t";
     print(root->right);
     cout<<root->data<<"\t";
   }
}

void order(struct tree *root)
{
  struct tree *x;
  stack<struct tree *> s;
  x=root;
  while(x!=NULL || !s.empty())
   {
     while(x!=NULL)
     {
      s.push(x);
      cout<<x->data<<"\t";
      x=x->left;
     }
     if(!s.empty())
      {
        x=s.top();
        s.pop();
        //cout<<x->data<<"\t";
        x=x->right;
      }
   }
}

void backorder(struct tree *root)
{
  struct tree *x;
  stack<struct tree *> s;
  //int leaf=1;
  x=root;
  cout<<endl;
  //leaf=!x->left && !x->right;
  while(x!=NULL || !s.empty())
  {
    //cout<<leaf<<endl;
    while(x!=NULL)
     {
       s.push(x);
       //x->count++;
       x=x->left;
     }
    if(!s.empty())
     {
       x=s.top();
       x->count++;
       s.pop();
       cout<<"ddddd"<<endl;
       if(!x->right && !x->left)
        {
         cout<<x->data<<"\t";
         x=x->right;
        }
       else
        {
          if(x->count>=2)
           {
            cout<<x->data<<"\t";
            x=s.top();
            s.pop();
           }
          else
           {
             x->count++;
             s.push(x);
             x=x->right;
           }
        }
     }
  }
}

int main(void)
{
  struct tree *root=NULL;
  int a[]={5,3,7,2,6,8};
  int n,i;
  i=n=0;
  n=sizeof(a)/sizeof(int);
  for(i=0;i<n;i++)
   root=insert(root,a[i]);
  print(root);
  //order(root);
  //backorder(root);
  cout<<endl;
  return 0;
}
