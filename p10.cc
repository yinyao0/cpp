#include<iostream>
#include<string>
using namespace std;

int main(void)
{
  string s1="abcabcdefgabdabcdababcqwe";
  string s2;
  getline(cin,s2);
  cout<<s2<<endl;
  cout<<s1<<endl;
  int j=0;
  for(int i=0;i<s1.length();i++)
   {
     for(j=0;j<s2.length();j++)
      {
        if(s1[i+j]!=s2[j])
          break;
      }
     if(j==s2.length())
       break;
   }
 if(j==s2.length())
  cout<<"it is matched!\n";
 else
  cout<<"it is not matched!\n";
 return 0;
}
