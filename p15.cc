#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int maxnum;

int compare(int b[],int key)
{
  int max1=0;
  for(int i=0;i<4;i++)
  {
    if(max1<b[i])
     max1=b[i];
  }
  if(max1<key)
   return 1;
  else
   return 0;
}

int choose(int a[])
{
  int b[4];
  maxnum=0;
  for(int i=0;i<10;i++)
   {
     if(a[i]>maxnum)
      maxnum=a[i];
   }
  for(int i=0;i<10;i++)
  {
    if(i<4)
     b[i]=a[i];
    else if(i>=4 && i<=8) 
    {
      if(compare(b,a[i]))
       {
         //cout<<i<<endl;
         return a[i];
       } 
    }
   else
    {
      return a[i];
    }
  } 
}


int main(void)
{
  int a[10];
  int count,k,n;
  count=k=0;
  cin>>n;
  /*srand(time(NULL));
  for(int i=0;i<10;i++)
   {
     a[i]=rand()%10;
   }
  for(int i=0;i<10;i++)
   cout<<a[i]<<"\t";
  cout<<endl;*/
  //cout<<choose(a)<<endl;
  //cout<<maxnum<<endl;
  for(int i=0;i<n;i++)
   {
     srand(i);
     for(int j=0;j<10;j++)
      a[j]=rand()%10;
     //for(int j=0;j<10;j++)
     //  cout<<a[j]<<"\t";
     //cout<<endl;
     if(maxnum==choose(a))
      k++;
     count++;
   }
  double p;
  p=(double)k/(double)count;
  //cout<<k<<"    "<<count<<endl;
  cout<<p<<endl;
  return 0;
}
