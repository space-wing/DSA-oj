#include<iostream>
#include<string>
using namespace std;

//KMP (为了便于后面周期序列的求解 故此处next数组长度为l+1)
int* getNext(string s){
    int l=s.length();
    int* next=new int[l+1];
    int i=0,k=-1;
    next[0]=-1;
    while(i<=l){
        while(k!=-1 and s[i]!=s[k])k=next[k];
        next[++i]=++k;
    }
    return next;
}

//改进后的NEXT数组
int* getNext_star(string s){
    int* next=getNext(s);
    int l=s.length();
    for(int i=1;i<l;i++){
        if(next[i]!=-1 and s[i]==s[next[i]])next[i]=next[next[i]];        
    }
    return next;
}

//判断是否为周期序列
bool isCycle(string s){
    int l=s.length();
    int* next=getNext(s);
    if(l-next[l] and l-next[l]!=l and l%(l-next[l])==0)return true;
    return false;
}

int main(){
    string s;
    getline(cin,s);
    if(isCycle(s))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}