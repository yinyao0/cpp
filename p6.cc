#include<iostream>
using namespace std;

int quick(int a[],int p,int r)
{
  int i,j,t=0;
  i=j=p;
  for(i=p;i<r;i++)
  {
    if(a[i]<a[r])
     {
       t=a[i];
       a[i]=a[j];
       a[j]=t;
       j++;
     }
  }
  t=a[r];
  a[r]=a[j];
  a[j]=t;
  return j;
}

void quick_sort(int a[],int p,int r)
{
  if(p<r)
   {
     int q=quick(a,p,r);
     quick_sort(a,p,q-1);
     quick_sort(a,q+1,r);
   }
}

int main(void)
{
  int a[]={3,7,1,2,8,9,4};
  int i,n;
  i=0;
  n=sizeof(a)/sizeof(int);
  for(i=0;i<n;i++)
   cout<<a[i]<<"\t";
  cout<<endl;
  //cout<<quick(a,0,n-1)<<endl;
  quick_sort(a,0,n-1);
  for(i=0;i<n;i++)
   cout<<a[i]<<"\t";
  cout<<endl;
  return 0;
}
