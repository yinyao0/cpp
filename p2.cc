#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

struct graph
{
  int vexnum,arcnum;
  int a[100][100];
  vector<int> visited;
};


void creat(struct graph *G)
{
  cout<<"please input the vertex and the arc of the graph\n";
  cin>>G->vexnum>>G->arcnum;
  cout<<"please input all the arcs\n";
  for(int i=0;i<G->vexnum;i++)
   {
     for(int j=0;j<G->vexnum;j++)
       cin>>G->a[i][j];
   }
}


int find(vector<int> visited,int key)
{
  for(int i=0;i<visited.size();i++)
   {
     if(visited[i]==key)
       return 1;
   }
  return 0;
}

void bfs(struct graph *G,int pos,queue<int> q)
{
  if(!find(G->visited,pos))
   {
    cout<<pos<<endl;
    G->visited.push_back(pos);
   }
  for(int i=0;i<G->vexnum;i++)
   {
     if(G->a[pos][i]!=0 && !find(G->visited,i))
      {
        q.push(i);
        G->visited.push_back(i);
        cout<<i<<endl;
      }
   }
  while(!q.empty())
   {
     pos=q.front();
     q.pop();
     bfs(G,pos,q);
   }
}

void dfs(struct graph *G,int pos)
{
  //if(!find(G->cisited,pos))
  //  G->visited.push_back(i);
  if(G->visited.size()==1)
   cout<<pos<<endl;
  for(int i=0;i<G->vexnum;i++)
   {
     if(!find(G->visited,i) && G->a[pos][i]!=0)
      {
       G->visited.push_back(i);
       cout<<i<<endl;
       dfs(G,i);
      }
   }

}

int main(void)
{
  struct graph *G=NULL;
  queue<int> q;
  G=new struct graph;
  creat(G);
  for(int i=0;i<G->vexnum;i++)
  {
    for(int j=0;j<G->vexnum;j++)
     cout<<G->a[i][j]<<"\t";
    cout<<endl;
  }
  int start=0;
  cin>>start;
  //cout<<"it is bfs\n";
  //bfs(G,start,q);
  G->visited.push_back(start);
  cout<<"it is dfs\n";
  dfs(G,start);
  //for(int i=0;i<G->visited.size();i++)
  //  cout<<G->visited[i]<<"\t";
  //cout<<endl;
  return 0;
}
