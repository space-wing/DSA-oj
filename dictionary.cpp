#include<iostream>
#include<map>
using namespace std;
int main(){
    char c[25];
    map<string,string> dic;
    string s;
    while(1){
        cin.getline(c,25);
        if(c[0]=='\0')break;
        string s1,s2;
        int i=-1,flag=0;
        while(c[++i]!='\0'){
            if(c[i]==' ')flag=1;
            else{
                if(flag)s2+=c[i];
                else s1+=c[i];
            }
        }
        dic[s2]=s1;
    }
    while(cin>>s){
        if(dic.find(s)!=dic.end())cout<<dic[s]<<endl;
        else cout<<"eh"<<endl;
    }
}