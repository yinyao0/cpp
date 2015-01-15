#include<iostream>
#include<string>
#include<cstring>
using namespace std;

//LCS

void lcs(string s1,string s2)
{
  int c[100][100];
  int i,j;
  string s;
  i=j=1; 
  memset(c,0,100*100);
  for(i=1;i<s1.length();i++)
  {
   for(j=1;j<s2.length();j++)
    {
      if(s1[i]==s2[j])
       {
         c[i][j]=c[i-1][j-1]+1;
         //if(i=s.length()+1)
         //s.append(s1.substr(i,1));
       }
      else
       {
        if(c[i-1][j]>c[i][j-1])
         {
           c[i][j]=c[i-1][j];
         }
        else
         {
          c[i][j]=c[i][j-1];
         }
       }
    }
  }
 /*for(int x=1;x<i;x++)
  {
    for(int y=1;y<j;y++)
    {
      if(c[x][y]>c[x][y-1] && y<=s.length()+1)
        s.append(s1.substr(x,1));
    }
  }*/
 cout<<c[i-1][j-1]<<"\t"<<s<<endl;
}

int main(void)
{
  string query;
  string text;
  getline(cin,query);
  getline(cin,text);
  string s1="0";
  s1.append(query);
  string s2="0";
  s2.append(text);
  lcs(s1,s2);
  return 0;
}
