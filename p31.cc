#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main(void)
{
   const char *p1="abcdefg";
   char *p2=(char *)malloc(8);
   char *p;
   printf("%s\n",p1);
   p=p2;
   while(*p1!='\0')
     *p2++=*p1++;
   printf("%s\n",p);
   return 0;
}
