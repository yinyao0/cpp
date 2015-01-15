#include<iostream>
using namespace std;

    int singleNumber(int A[], int n) {
        int one,two,three;
        one=two=three=0;
        for(int i=0;i<n;i++)
        {
            //cout<<one<<endl;
            two|=(one&A[i]);
            one^=A[i];
            three=~(one&two);
            cout<<two<<endl;
            one&=three;
            
            two&=three;
            cout<<one<<endl;
        }
        return one;
        
    }

int main(void)
{
  int A[]={1};
  int n=0;
  n=sizeof(A)/sizeof(int);
  cout<<singleNumber(A,n)<<endl;
  return 0;
}
