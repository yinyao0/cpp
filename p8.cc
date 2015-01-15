#include<iostream>
using namespace std;

int prime(int key)
{
  int i=0;
  for(i=2;i<key;i++)
   {
     if(key%i==0)
      return 0;
   }
  return 1;
}

void analysis(int key,int a[],int k,int from)
{
  int i=0;
  //int x=0;
  for(i=from;i<=key;i++)
   {
    if(prime(i))
    {
     key=key-i;
     a[k++]=i;
     //cout<<key<<" "<<i<<endl;
     if(key<0)
       return;
     else if(key==0)
      {
        for(int j=0;j<k;j++)
         cout<<a[j]<<"\t";
        cout<<endl;
        return;
      }
     else
      {
        //cout<<key<<endl;
        //key=key-i;
        //a[k++]=i;
        analysis(key,a,k,i);
        key=key+i;
        a[--k]=0;
      }
    }
   }
}

int main(void)
{
  int number=0;
  cin>>number;
  int a[30]={0};
  //cout<<prime(3)<<endl;
  analysis(number,a,0,2);
  //for(int i=0;i<10;i++)
  //  cout<<a[i]<<"\t";
  //cout<<endl;
  return 0;
}
