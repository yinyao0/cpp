#include<iostream>
using namespace std;

struct list
{
   int data;
   struct list *next;
};

struct list *insert(struct list *head,int key)
{
  struct list *x,*y;
  x=new struct list;
  x->data=key;
  x->next=NULL;
  if(head==NULL)
  {
    head=new struct list;
    head->data=key;
    head->next=NULL;
  }
  else
  {
    y=head->next;
    head->next=x;
    x->next=y;
  }
  return head;
}

void print(struct list *head)
{
  if(head==NULL)
    return;
  else
   {
     cout<<head->data<<"\t";
     print(head->next);
   }
}

void change(struct list *head)
{
  struct list *x,*y;
  x=y=head;
  while(x->data!=3)
   {
     x=x->next;
   }
  while(y->data!=6)
   {
    y=y->next;
   }
  y->next=x;
}

struct list *coltest(struct list *head)
{
  struct list *x,*y;
  x=y=head;
  x=x->next;
  if(y->next!=NULL)
  y=y->next->next;
  while(x!=y&&x!=NULL&&y!=NULL&&y->next!=NULL)
  {
    x=x->next;
    y=y->next->next;
  }
  if(x==y)
   return y;
  else
   return NULL;
}

struct list *check(struct list *head)
{
   struct list *first=NULL;
   first=coltest(head);
   if(first==NULL)
     return NULL;
   //cout<<first->data<<endl;
   struct list *x=head;
   while(x!=first)
   {
     x=x->next;
     first=first->next;
   }
   return x;
}

bool hasCycle(struct list *head) {
  struct list *x,*y;
  x=y=head;
  if(head==NULL||head->next==NULL)
    return false;
  x=x->next;
  if(y->next!=NULL)
  y=y->next->next;
  while(x!=y&&x!=NULL&&y!=NULL&&y->next!=NULL)
  {
    x=x->next;
    y=y->next->next;
  }
  if(x==y)
   return true;
  else
   return false;
 
}

int main(void)
{
   struct list *head=NULL;
   //int a[]={1,6,5,4,3,2};
   int a[]={};
   //int a[]={7032,15013,6890,8877,11344,320,13037,9414,6817,1566,14907,-2756,9931,-4488,11602,4887,1239,6231,-5366,8501,1142,-1367,-4140};
   int n,i=0;
   n=sizeof(a)/sizeof(int);
   for(i=0;i<n;i++)
   {
     head=insert(head,a[i]);
   }
   //print(head);
   //cout<<endl;
   //change(head);
   cout<<hasCycle(head)<<endl;
   /*struct list *result=NULL;
   result=check(head);
   if(result!=NULL)
    cout<<result->data<<endl;
   else
    cout<<"no circle\n";*/
   return 0;
}
