#include<iostream>
using namespace std;

void merge(int a[],int p,int q,int r)
{
  int b[r/2+1],c[r/2+1];
  int i=p;
  int j,m,n,k;
  j=m=n=k=0;
  for(i=p;i<=q;i++)
    b[j++]=a[i];
  m=j;
  j=0;
  for(i=q+1;i<=r;i++)
    c[j++]=a[i];
  n=j;
  i=j=0;
  k=p;
  while(i<m && j<n)
   {
     if(b[i]<c[j])
      {
        a[k++]=b[i++];
      }
     else
        a[k++]=c[j++];
   }
  while(i<m)
   a[k++]=b[i++];
  while(j<n)
   a[k++]=c[j++];
}

void merge_sort(int a[],int p,int r)
{
  if(p<r)
   {
     int q=(p+r)/2;
     merge_sort(a,p,q);
     merge_sort(a,q+1,r);
     merge(a,p,q,r);
   }
}

int main(void)
{
  int a[]={1,3,5,7,2,4,6,8};
  int i,n;
  i=0;
  n=sizeof(a)/sizeof(int);
  for(i=0;i<n;i++)
    cout<<a[i]<<"\t";
  cout<<endl;
  //merge(a,0,4,n-1);
  merge_sort(a,0,n-1);
  for(i=0;i<n;i++)
    cout<<a[i]<<"\t";
  cout<<endl;
  return 0;
}
