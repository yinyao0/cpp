#include<iostream>
using namespace std;

int single(int A[],int n)
{
  int i=0;
  int k=A[i];
  for(i=1;i<n;i++)  
   k=k^A[i];
  return k;
}

int main(void)
{
  int A[]={1,3,4,6,3,1,4};
  int n=0;
  n=sizeof(A)/sizeof(int);
  cout<<single(A,n)<<endl;
  return 0;
}


