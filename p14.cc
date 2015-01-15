#include<iostream>
#include<vector>
using namespace std;

vector<int> v;
int count=0;


void fun(int order,int level,int n)
{
  v.push_back(order);
  if(level>=n/2)
   {
     for(int i=0;i<level;i++)
      cout<<v[i]<<"\t";
     cout<<endl;
     v.pop_back();
     count++;
     return;
   }
  else
   {
     for(int i=order+1;i<2*(level+1);i++)
       fun(i,level+1,n);
     v.pop_back();
   }
}

int main(void)
{
   int n=0;
   cin>>n;
   //v.push_back(1);
   fun(1,1,n);
   cout<<count<<endl;
   return 0;
}
