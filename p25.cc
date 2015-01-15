#include<iostream>
#include<vector>
using namespace std;

struct TreeNode 
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *insert(struct TreeNode *root,int key)
{
  struct TreeNode *x,*y,*z;
  z=new struct TreeNode;
  z->val=key;
  z->left=z->right=NULL;
  x=root;
  while(x!=NULL)
  {
    y=x;
    if(x->val>key)
      x=x->left;
    else
      x=x->right;
  }
  if(x==root)
  {
    root=new struct TreeNode;
    root->val=key;
    root->left=root->right=NULL;
  }
  else
  {
    if(y->val>key)
      y->left=z;
    else 
      y->right=z;
  }
  return root;
}



int max(struct TreeNode *root)
{
	if (root == NULL)
		return 0;
	int min = root->val, max = root->val;


	vector<struct TreeNode*> pre_node;
	vector<int> val;
	pre_node.push_back(root);

	while(!pre_node.empty())
	{
		struct TreeNode *left_leaf = NULL;
		struct TreeNode *right_leaf = NULL;
		if(pre_node.back() != NULL)
		{
			left_leaf = pre_node.back()->left;
			right_leaf = pre_node.back()->right;
			if (pre_node.back()->val < min)
			{
				min = pre_node.back()->val;
			}
			else if (pre_node.back()->val > max)
			{
				max = pre_node.back()->val;
			}
		}		
		pre_node.pop_back();
		if(right_leaf != NULL)
		{
			pre_node.push_back(right_leaf);
		}
		if(left_leaf != NULL)
		{
			pre_node.push_back(left_leaf);
		}
	}
	return max - min;
}

int main(void)
{
  TreeNode *root=NULL;
  int a[]={123.-3435.4324,2342343,-8098,432,-434,234};
  int n=0;
  n=sizeof(a)/sizeof(int);
  for(int i=0;i<n;i++)
   root=insert(root,a[i]);
  cout<<max(root)<<endl;  
  return 0;
}
