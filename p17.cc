#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int b[50];
int mini=999;

void pick(int a[],int n,int result[],int y,int money)
{
  if(money<0)
    return;
  if(money==0)
   {
    if(mini>y)
    {
     for(int i=0;i<y;i++)
       b[i]=result[i];
     mini=y;
    }
   }
  for(int i=n-1;i>=0;i--)
  {
    money=money-a[i];
    result[y++]=a[i];
    pick(a,n,result,y,money);
    money=money+a[i];
    result[--y]=0;
  }
}


int main(void)
{
  int a[20],result[50];
  int n=0;
  int money=0;
  memset(a,0,20);
  memset(result,0,50);
  memset(b,0,50);
  cout<<"please input the number of coins\n";
  cin>>n;
  cout<<"please input the money\n";
  cin>>money;
  cout<<"please input each coins\n";
  for(int i=0;i<n;i++)
    cin>>a[i];
  pick(a,n,result,0,money);
  for(int i=0;i<mini;i++)
    cout<<b[i]<<"\t";
  cout<<endl;
  return 0;
}
