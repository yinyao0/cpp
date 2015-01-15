#include<iostream>
#include<cmath>
using namespace std;

int count=0;

int detect(int a[],int x,int y,int n)
{
  int i;
  for(i=1;i<n;i++)
   {
     if(a[i]!=0)
      { 
        if(y==a[i]||fabs(a[i]-y)==fabs(i-x))
          return 0;
      }
   }
  return 1;
} 

void queue(int a[],int n,int k)
{
  int i;
  i=1;
  for(i=1;i<n;i++)
   {
     if(detect(a,k,i,n)==1)
      {
       a[k]=i;
       if(k==n-1)
       {
         count++;
         for(int j=1;j<n;j++)
           cout<<a[j]<<"\t";
         cout<<endl;
       }
       k++;
       queue(a,n,k);
       a[--k]=0;
       //k--;
      }
   }
   return;
} 


int main(void)
{
  int a[9];
  int i,n;
  i=0;
  n=sizeof(a)/sizeof(int);
  for(i=0;i<n;i++)
    a[i]=0;
  queue(a,n,1);
  //for(i=1;i<n;i++)
  //  cout<<a[i]<<"\t";
  //cout<<endl;
  //a[3]=2; 
  //cout<<detect(a,4,3,n)<<endl;
  cout<<count<<endl;
  return 0;
}
