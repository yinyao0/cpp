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
   x->next=NULL;
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

struct list *change(struct list *head,struct list *x,struct list *y)
{
  struct list *p1,*p2,*p3,*p4,*p;
  p=new struct list;
  p->next=head;
  p->data=0;
  p1=p;
  while(p1!=x)
    {
     p2=p1;
     p1=p1->next;
    }
  p1=p1->next;
  p3=p;
  while(p3!=y)
    {
      p4=p3;
      p3=p3->next;
    }
  p3=p3->next;
  if(p4->next==p1)
  {
    p2->next=y;
    y->next=x;
    x->next=p3;
  }
  else
  {
   p2->next=y;
   y->next=p1;
   p4->next=x;
   x->next=p3;
  }
  return p->next;
}


/*struct list *sortlist(struct list *head)
{
  struct list *x,*y,*z;
  for(x=head;x!=NULL;x=x->next)
  {
   for(y=x;y!=NULL;y=y->next)
    {
      if(x->data > y->data)
       {
         head=change(head,x,y);
         z=x;
         x=y;
         y=z;
       }
    }
  }
 return head;
}

struct list *sortlist(struct list *head)
{
  struct list *x,*y,*z,*t;
  for(x=head;x!=NULL;x=x->next)
  {
    y=x->next;
    if(y==NULL)
      break;
    t=head;
    while(t!=y)
    {
      if(y->data < t->data)
       {
         head=change(head,t,y);
         if(t==x)
          x=y;
         z=t;
         t=y;
         y=z;
         //cout<<x->data<<"\t"<<t->data<<endl;
       }
      t=t->next;
    }
  }
  return head;
}*/

struct list *sortlist(struct list *head)
{
  struct list *x,*y,*z,*t,*k,*before;
  before=new struct list;
  before->data=0;
  before->next=head;
  for(x=head;x!=NULL;x=x->next)
  {
    y=x->next;
    if(y==NULL)
     break;
    z=before->next;
    t=before;
    while(z!=y)
    {

      if(z->data > y->data)
      {
        x->next=y->next;
        t->next=y;
        y->next=z;
        k=z;
        z=y;
        y=k;
        k=y;
        y=x;
        x=k;
      }
      z=z->next;
      t=t->next;
      //cout<<"t->"<<t->data<<"\t"<<"z->"<<z->data<<"\t"<<"x->"<<x->data<<"\t"<<"y->"<<y->data<<endl;
      //print(before->next);cout<<endl;
    }
  }
  return before->next;
}

int main(void)
{
 int a[]={4,7,9,3,1,6};
 //int a[]={4,3,1,6};
 int n=sizeof(a)/sizeof(int);
 struct list *head=NULL;
 for(int i=0;i<n;i++)
  head=insert(head,a[i]);
 print(head);
 cout<<endl;
 head=sortlist(head);
 print(head);//cout<<endl;
 //cout<<x->data<<"\t"<<y->data<<endl;
 cout<<endl;
 return 0;
}
