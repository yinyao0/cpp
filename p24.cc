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
  if(head==NULL)
  {
    head=new struct list;
    head->data=key;
    head->next=NULL;
  }
  else
  {
    x=new struct list;
    x->data=key;
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
     cout<<head->data;
     print(head->next);    
   }
}

struct list *reverse(struct list *head)
{
   struct list *p1,*p2,*p3;
   p1=head;
   p2=p1->next;
   p3=p2->next;
   p1->next=NULL;
   while(p2!=NULL)
   {
     p2->next=p1;
     p1=p2;
     p2=p3;
     if(p3!=NULL)
     p3=p3->next;
   }
   return p1;
}

struct list *merge(struct list *l1,struct list *l2)
{
   struct list *head=NULL;
   struct list *p1,*p2,*p3,*p4;
   head=l1;
   p1=l1;
   p2=p1->next;
   p3=l2;
   p4=p3->next;
   while(p1!=NULL && p3!=NULL)
   {
     p1->next=p3;
     p3->next=p2;
     p1=p2;
     p3=p4;
     if(p2!=NULL && p4!=NULL)
      {
        p2=p2->next;
        p4=p4->next;
      }
   }
   return head;
}

void reorder(struct list *head)
{
  struct list *l1,*l2;
  struct list *fast,*slow;
  fast=slow=head;
  while(fast!=NULL&&fast->next!=NULL)
  {
    l1=slow;
    fast=fast->next->next;
    slow=slow->next;
  }
  if(fast!=NULL&&fast->next==NULL)
   {
     l1=slow;
   }
  l2=l1->next;
  l1->next=NULL;
  l1=head;
  l2=reverse(l2);
  //print(l2);cout<<endl;
  //print(head);cout<<endl;
  head=merge(l1,l2);
}

int main(void)
{
   struct list *head=NULL;
   //int a[]={1,9,8,7,6,5,4,3,2};
   //int a[]={1,6,5,4,3,2};
   int a[]={1,3,2};
   int n,i;
   i=0;
   n=sizeof(a)/sizeof(int);
   for(int i=0;i<n;i++)
    head=insert(head,a[i]);
   print(head);
   cout<<endl;
   reorder(head);
   print(head);
   cout<<endl;
   return 0;
}
