#include<iostream>
#include<string>
using namespace std;
int kmp[1000005]{0};
int main(){
    int t,total=0;
    string s;
    while(cin>>t){
        total++;
        if(!t)break;
        cin>>s;
        int l=s.length();
        cout<<"Test case #"<<total<<endl;
        int i=0,k=-1;
        kmp[i]=k;
        while(i<l){
            while(k!=-1 and s[i]!=s[k])k=kmp[k];
            kmp[++i]=++k;
            if(i!=i-k and i%(i-k)==0){
                cout<<i<<" "<<i/(i-k)<<endl;
            }
        }
        cout<<endl;
    }
}