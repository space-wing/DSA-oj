#include<iostream>
using namespace std;
int num[10005], num0[10005];
int temp[10005];
void merge_sort(int l,int r){
    if(l==r)return;
    if(l==r-1){
        if(num[l]>num[r]){
            temp[l]=num[r],temp[r]=num[l];
            num[l]=temp[l],num[r]=temp[r];
        }
        return;
    }
    int mid=(l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int l1=l,l2=mid+1,r1=mid,r2=r,k=l;
    while(l1<=r1 and l2<=r2){
        if(num[l1]<=num[l2])temp[k++]=num[l1++];
        else temp[k++]=num[l2++];
    }
    while(l1<=r1)temp[k++]=num[l1++];
    while(l2<=r2)temp[k++]=num[l2++];
    for(int i=l;i<=r;i++)num[i]=temp[i];
    return;
}
void quick_sort(int l,int r){
    if(l>=r)return;
    int k=num0[l];
    int i=l,j=r;
    while(i<j){
        while(i<j and num0[j]>k)j--;
        if(i<j)num0[i++]=num0[j];
        while(i<j and num0[i]<k)i++;
        if(i<j)num0[j--]=num0[i];
    }
    num0[i]=k;
    quick_sort(l,i-1);
    quick_sort(i+1,r);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>num[i],num0[i]=num[i];
    merge_sort(0,n-1);
    quick_sort(0,n-1);
    for(int i=0;i<n;i++)cout<<num[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)cout<<num0[i]<<" ";
}