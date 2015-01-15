#include<iostream>
#include<vector>
using namespace std;

int find(vector<int> a,int key)
{
  for(int i=0;i<a.size();i++)
   {
      if(a[i]==key)
        return 1;
   }
  return 0;
}

int main(void)
{
  vector<int> a;
  a.push_back(2);
  a.push_back(4);
  a.push_back(9);
  a.push_back(3);
  a[2]=23;
  for(int i=0;i<a.size();i++)
   cout<<a[i]<<"\t";
  cout<<endl;
  cout<<find(a,9)<<endl;
  return 0;
}
