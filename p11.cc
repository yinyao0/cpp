#include<iostream>
#include<string>
using namespace std;

int *get_next(string s)
{
  int *a;
  a=new int[s.length()];
  a[0]=-1;
  int i,j;
  i=1;
  j=0;
  while(i<s.length())
   {
     if(s[i]==s[j])
      {
        a[i++]=j;
        j++;
      }
     else if(s[i]!=s[j] && s[i]==s[0])
      {
        a[i++]=j;
        j=1;
      }
     else
      {
        a[i++]=j;
        j=0;
      }
   }
  return a;
}

int kmp(string s1,string s2,int *next)
{
  int j=0;
  for(int i=0;i<s1.length();)
   {
     if(j==-1 || s1[i]==s2[j])
      {
        i++;
        j++;
      } 
     else
      {
       j=next[j];
      }
     if(j==s2.length()-1)
      return 1;
   }
  return 0;
}

int main(void)
{
   int *next;
   //string s1="abababc";
   string s1="aabdjakdababcjdkababd";
   string s2;
   getline(cin,s2);
   next=get_next(s2);
   for(int i=0;i<s2.length();i++)
      cout<<next[i]<<"\t";
   cout<<endl;
   int k=kmp(s1,s2,next);
   if(k==1)
     cout<<"it is matched!\n";
   else
     cout<<"it is not matched!\n";
   return 0;
}
