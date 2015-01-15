#include<iostream>
#include<string>
using namespace std;

int main(void)
{
  string s1;
  getline(cin,s1);
  cout<<s1<<endl;
  s1.insert(1,"123");
  cout<<s1<<endl;
  string s2;
  s2.append(s1.substr(0,2));
  //s1.append(p);
  cout<<s2<<endl;
  return 0;
}
