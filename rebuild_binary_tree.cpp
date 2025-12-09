#include<iostream>
using namespace std;
int zhong[200000],hou[100000];

void rebuild(int zl,int zr,int hl,int hr){
    if(zl>zr||hl>hr)return;
    cout<<hou[hr]<<' ';
    if(zl==zr)return;
    int k=hou[hr],i;
    for(int j=zl;j<=zr;j++){
        if(zhong[j]==k){
            i=j;
            break;
        }
    }
    rebuild(zl,i-1,hl,i-zl+hl-1);
    rebuild(i+1,zr,i-zl+hl,hr-1);
}

int main(){
    int n=0;
    while(cin>>zhong[n++]){};
    for(int i=0;i<n;i++)hou[i]=zhong[i+n/2];
    rebuild(0,n/2-1,0,n/2-1);
}