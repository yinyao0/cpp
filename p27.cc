#include<iostream>
#include<set>
#include<string>
#include<vector>

using namespace std;

int main(void)
{
  string s="abcdefg"; 
  set<string> v;
  v.insert("aaaa");
  v.insert("bbbb");
  v.insert("cccc");
  set<string>::iterator it;
  it=v.find("aaa");
  if(it!=v.end())
   cout<<*it<<endl;
  else
   cout<<"nothing\n";
  cout<<s.substr(1)<<endl;
  return 0;
}
