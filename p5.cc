#include<iostream>
using namespace std;


void fun(int a[],int b[],int sum,int key,int i,int j)
{
  int k=0;
  sum+=a[i];
  if(sum==key)
   {
     b[j]=i;
     for(int x=0;x<4;x++)
       cout<<b[x]<<"\t";
     cout<<endl;
     return;
   }
  else if(sum<key)
   {
     cout<<sum<<endl;
     k=i;
     b[j++]=i++;
     fun(a,b,sum,key,i,j);
     i=k;
     sum-=a[i];
     b[j--]=0;
     cout<<sum<<endl;
   }
  else
   return;
}

int main(void)
{
  int a[]={3,5,6,7};
  int sum=0;
  int n,b[4],i;
  cin>>n;
  i=0;
  for(i=0;i<4;i++)
   b[i]=0;
  fun(a,b,sum,n,0,0);
  return 0;
}
