#include<iostream>
#include<set>
#include<string>
using namespace std;

int main(void)
{
  set<string> a;
  a.insert("aaaa");
  a.insert("bbbbb");
//  cout<<a<<endl;
  set<string>::iterator it;
  for(it=a.begin();it!=a.end();it++)
   cout<<*it<<endl;
  return 0;
}
