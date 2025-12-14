#include<iostream>
#include<string>
#include<set>
using namespace std;

bool similar(string a,string b){
    int l1=a.length(),l2=b.length();
    if(l1<l2)return similar(b,a);
    if(l1-l2>1)return false;
    if(l1==l2){
        int flag=0;
        for(int i=0;i<l1 and flag!=2;i++){
            if(a[i]!=b[i])flag++;
        }
        return flag<=1;
    }
    else{
        int i=0,j=0,flag=0;
        while(i<l1 and j<l2){
            if(a[i]==b[j]){
                i++,j++;
            }
            else{
                if(flag)return false;
                flag=1;
                i++;
            }
        }
    }
    return true;
}
string dic[10005];
set<string> dictionary;
int main(){
    int n=0;
    while(cin>>dic[n]){
        if(dic[n]=="#")break;
        n++;
        dictionary.insert(dic[n-1]);
    }
    string s;
    while(cin>>s){
        if(s=="#")break;
        else{
            if(dictionary.find(s)!=dictionary.end()){
                cout<<s<<" is correct"<<endl;
                continue;
            }
            cout<<s<<":";
            for(int i=0;i<n;i++){
                if(similar(s,dic[i])){
                    cout<<' '<<dic[i]<<endl;
                }
            }
            cout<<endl;
        }
    }

}