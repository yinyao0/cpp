#include<iostream>
#include<cmath>
using namespace std;

int reverse(int x)
{
  int i=0;
  int a[35];
  int n,result;
  n=result=0;
  while(x!=0)
  {
    a[i++]=x%10;
    x=x/10;
  }
  n=i;
  for(i=0;i<n;i++)
  {
    //cout<<a[i]<<endl;
    result+=a[i]*pow(10,n-i-1);
  }
  return result;
}

int main(void)
{
  int temp=0;
  cin>>temp;
  cout<<reverse(temp)<<endl;
  return 0;
}
