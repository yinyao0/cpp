#include<iostream>
#include<vector>
using namespace std;

int dostart(vector<int> &gas, vector<int> &cost,int start)
{
   int gsum=0;
   int csum=0;
   for(int i=start;i<gas.size();i++)
   {
     gsum+=gas[i];
     csum+=cost[i];
     if(gsum>=csum) continue;
     else return -1;
   }  
  for(int i=0;i<start;i++)
   {
     gsum+=gas[i];
     csum+=cost[i];
     if(gsum>=csum) continue;
     else return -1;
   }
  return 1;
}

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) 
{
  int ret=0;
  for(int i=0;i<gas.size();i++)
   {
     ret=dostart(gas,cost,i);
     if(ret==-1)
       continue;
     else
       return i;
   }
  return -1;
}

int main(void)
{
  vector<int> gas,cost;
  gas.push_back(2);
  gas.push_back(1); 
  gas.push_back(3);
  cost.push_back(3);
  cost.push_back(2);
  cost.push_back(1);
  cout<<canCompleteCircuit(gas,cost)<<endl;
  return 0;  
}
