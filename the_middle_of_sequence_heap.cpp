#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n,mid,a,b,minn,maxn;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> maxh;
    priority_queue<int> minh;
    cin>>mid;
    cout<<mid<<endl;
    int k=n%2==0?n/2-1:n/2;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        minn=min(a,b);
        maxn=max(a,b);
        if(minn>=mid){
            minh.push(mid);
            maxh.push(minn);
            maxh.push(maxn);
            mid=maxh.top();
            maxh.pop();
        }
        else if(maxn<=mid){
            maxh.push(mid);
            minh.push(minn);
            minh.push(maxn);
            mid=minh.top();
            minh.pop();
        }
        else{
            maxh.push(maxn);
            minh.push(minn);
        }
        cout<<mid<<endl;
    }
    if(n%2==0)cin>>k;
}
// wcnm 为什么n不一定是奇数 我上早八 阿弥诺斯 艹艹艹
// 我阐述你的梦 娘希匹
// 啊啊啊 debugde了两小时 我真服了 