#include<iostream>
using namespace std;
int num[20005]{0},temp[20005],ans;
void merge_sort(int l,int r){
    if(l==r  )return;
    if(l+1==r){
        if(num[l]>num[r]){
            int temp0=num[r];
            num[r]=num[l];
            num[l]=temp0;
            ans++;
        }
        return;
    }
    int mid=(l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int r0=mid+1,t=l,l0=l;
    while(l0<=mid and r0<=r){
        if(num[l0]>num[r0]){
            temp[t++]=num[r0++];
            ans+=mid-l0+1;
        }
        else temp[t++]=num[l0++];
    }
    while(l0<=mid)temp[t++]=num[l0++];
    while(r0<=r)temp[t++]=num[r0++];
    for(int i=l;i<=r;i++)num[i]=temp[i];
}
int main(){
    int t;
    while(cin>>t){
        ans=0;
        if(t==0)return 0;
        for(int i=0;i<t;i++){
            cin>>num[i];
        }
        merge_sort(0,t-1);
        cout<<ans<<endl;
    } 
}