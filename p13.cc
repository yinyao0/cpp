#include<iostream>
#include<queue>
#include<functional>
using namespace std;

int a[20][20];
int worker[20],task[20];
int mincost=999;

int find(int worker[],int i,int n)
{
  for(int j=0;j<n;j++)
   {
     if(worker[j]==i)
      return 1;
   }
  return 0;
}

void fun(int cost,int k,int n)
{
  if(cost<mincost && k>=n)
   {
     mincost=cost;
     for(int i=0;i<n;i++)
       cout<<worker[i]<<"\t";
     cout<<endl;
   }
  else
   {
     for(int i=0;i<n;i++)
      {
        if(worker[k]==-1 && !find(worker,i,n))
        {
          worker[k]=i;
          //task[i]=k;
          cost+=a[k][i];
          //cout<<mincost<<endl;
          fun(cost,++k,n);
          worker[--k]=-1;
          cost-=a[k][i];
          //task[--i]=0;
        }
      }
   }
}

int main(void)
{
  //priority_queue< int,vector<int>,greater<int> > q;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
   {
     for(int j=0;j<n;j++)
       cin>>a[i][j];
   }
  for(int i=0;i<n;i++)
   {
     worker[i]=task[i]=-1;
   }
  fun(0,0,n);
  cout<<mincost<<endl;
  return 0;
}
