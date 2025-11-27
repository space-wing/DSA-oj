#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;
int main()
{
  int v,a;
  cin>>v>>a;
  int degree[10005]{0},total=v; 
  vector<int> point[10005];
  for(int i=0;i<a;i++){
    int m,n;
    cin>>m>>n;
    degree[n]++;
    point[m].push_back(n);
  }  
  while(total){
    for(int i=1;i<=v;i++){
      if(degree[i]==0){
        cout<<'v'<<i<<" ";
        degree[i]--;
        total--;
        for(int j=0;j<point[i].size();j++){
          degree[point[i][j]]--;
        }
        break;
      }
    }
  }
}   