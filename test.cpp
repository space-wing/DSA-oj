#include<iostream>
using namespace std;
int main(){
  int next[105]{-1};
  string s;
  cin>>s;
  int l=s.length();
  int k=-1;
  for(int i=0;i<l-1;i++){
    while(k!=-1 and s[i]!=s[k]) k=next[k];
    k++;
    if(s[i+1]==s[k])next[i+1]=next[k];
    else next[i+1]=k;
  }
  for(int i=0;i<l;i++) cout<<s[i]<<" ";
  cout<<endl;
  for(int i=0;i<l;i++) cout<<next[i]<<" ";
}
