#include<iostream>
using namespace std;
int kmp[100005];
int min_cycle_put(string str){
    int ans=0x11111111;
    int l=str.length(),k=-1,i=0;
    kmp[i]=k;
    while(i<=l){
        while(k!=-1 and str[i]!=str[k]){
            k=kmp[k];
        }
        k++;
        kmp[++i]=k;
    }
    k=l-kmp[l];
    if(l%k==0){
        if(k==l) return l;
        return 0;
    }
    else{
        return (l/k+1)*k-l;
    }
}
int main(){
    string str;
    cin>>str;
    int l=str.length();
    string str0;
    for(int i=l-1;i>=0;i--){
        str0.push_back(str[i]);
    }
    if(l==1){
        cout<<1<<endl;
        return 0;
    }        
    else cout<<min(min_cycle_put(str),min_cycle_put(str0))<<endl;
}
