#include<iostream>
#include<vector>
#include<string>
using namespace std;


vector <vector <string> > partition(string s)
{
  vector <vector<string> > vv;
  for(int i=0;i<s.length();i++)
  {
    vector<string> v1;
    for(int j=1;j<=s.length()-i;j++)
    {
      cout<<s.substr(i,j)<<endl;
      if(s.substr(i,j)==1 || )
      v1.push_back(s.substr(i,j));
    }
    vv.push_back(v1);
  }
  return vv;
}

int judge(string s,int len,int start,int end)
{
  if(len==0||len==1)
    return 1;
  if(s[start]!=s[end])
    return 0;
  return judge(s,len-2,start+1,end-1);
}

int main(void)
{
  string s;
  getline(cin,s);
  cout<<s<<endl;
  cout<<s.length()<<endl;
  //cout<<judge(s,s.length(),0,s.length()-1)<<endl;
  //cout<<s.substr(0,1)<<endl;
  partition(s);
  return 0;
}
