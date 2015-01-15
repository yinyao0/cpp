#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int LCS(const string& str1,const string& str2){
    int xlen=str1.size();       
    vector<int> tmp(xlen);        
    vector<int> arr(tmp);     
    int ylen=str2.size();       
    int maxele=0;               
    int pos=0;                  
    for(int i=0;i<ylen;i++){
        string s=str2.substr(i,1);
        arr.assign(xlen,0);     
        for(int j=0;j<xlen;j++){
            if(str1.compare(j,1,s)==0){
                if(j==0)
                    arr[j]=1;
                else
                    arr[j]=tmp[j-1]+1;
                if(arr[j]>maxele){
                    maxele=arr[j];
                    pos=j;
                }
            }      
        }
        tmp.assign(arr.begin(),arr.end());
    }
    string res=str1.substr(pos-maxele+1,maxele);
    return res.length();
}
int main(){
    string str1;
    string str2;
    getline(cin,str1);
    getline(cin,str2);
    int lcs=LCS(str1,str2);
    cout<<lcs<<endl;
    return 0;
}
