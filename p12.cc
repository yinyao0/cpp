#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct graph
{
  int vexnum,arcnum;
  int a[100][100];
};

void creat(struct graph *G)
{
  cout<<"please input the number of the vertex and arc\n";
  cin>>G->vexnum>>G->arcnum;
  cout<<"please input every arc\n";
  for(int i=0;i<G->vexnum;i++)
   {
     for(int j=0;j<G->vexnum;j++)
      {
        cin>>G->a[i][j];
      }
   } 
}

int max_flow(struct graph *G,int start,int end)
{
  int res[G->vexnum][G->vexnum];
  int pre[G->vexnum];
  int i,j,min,maxflow;
  i=j=maxflow=0;
  min=99999;
  queue<int> q;
  for(i=0;i<G->vexnum;i++)
   {
     for(j=0;j<G->vexnum;j++)
       res[i][j]=G->a[i][j];
   }
  while(1)
   {
     //cout<<"ddddd\n";
      for(i=0;i<G->vexnum;i++)
       pre[i]=-1;
      q.push(start);
      while(!q.empty())
      {
        i=q.front();
        q.pop();
        for(j=0;j<G->vexnum;j++)
         {
           if(res[i][j]>0 && pre[j]==-1)
            {
              pre[j]=i;
              q.push(j);
            }
         }
      }
     //cout<<pre[end]<<endl;
     if(pre[end]==-1)
       break;
     for(i=end;i!=start;i=pre[i])
       {
         if(res[pre[i]][i]<min)
           min=res[pre[i]][i];
       }
     for(i=end;i!=start;i=pre[i])
      {
        res[pre[i]][i]-=min;
        res[i][pre[i]]+=min;
      }
     maxflow+=min;
   }
  return maxflow;
}

int main(void)
{
  struct graph *G=NULL;
  G=new struct graph;
  creat(G);
  cout<<max_flow(G,0,5)<<endl;
  return 0;
}
