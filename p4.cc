#include<iostream>
using namespace std;

struct graph
{
  int vexnum,arcnum;
  int a[100][100];
};

struct graph *creat(struct graph *G)
{
  int i,j;
  i=j=0;
  G=new struct graph;
  cout<<"please input the number of the vertex and the arc\n";
  cin>>G->vexnum>>G->arcnum;
  cout<<"please input all the arc\n";
  for(i=0;i<G->vexnum;i++)
   {
     for(j=0;j<G->vexnum;j++)
      {
        cin>>G->a[i][j];
      }
   }
  return G;
}

int find(int r[],int k,int n)
{
  int i=0;
  for(i=0;i<n;i++)
   {
     if(r[i]==k)
       return 1;
   }
  return 0;
}

void hamiton(struct graph *G,int r[],int k,int x)
{
   int i,j,n;
   i=j=0;
   n=G->vexnum;
   for(i=0;i<n;i++)
    {
      if(r[n-1]!=-1&&G->a[r[n-1]][0]==1&&k==0)
       {
         for(int y=0;y<n;y++)
           cout<<r[y]<<"\t";
         cout<<endl;
         return;
         //cout<<"k-->"<<k<<" "<<"x-->"<<x<<endl;
       }
      if(G->a[k][i]==1)
       {
        if(!find(r,k,n))
        {
         r[x++]=k;
         j=k;
         k=i;
         hamiton(G,r,k,x);
         r[--x]=-1;
         k=j;
        }
       }
    }
   return;
}

int main(void)
{
  int i,j;
  i=j=0;
  struct graph *G=NULL;
  //G=new struct graph;
  G=creat(G);
  /*for(i=0;i<G->vexnum;i++)
   {
     for(j=0;j<G->vexnum;j++)
       cout<<G->a[i][j]<<"\t";
     cout<<endl;
   }*/
  int r[G->vexnum];
  for(i=0;i<G->vexnum;i++)
    r[i]=-1;
  hamiton(G,r,0,0);
  return 0;
}
