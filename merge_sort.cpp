#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;
int num[100005]{0};
int ans=0;
void merge_sort(int left,int right){
    if(left>=right)return;
    int mid=(left+right)/2;
    merge_sort(left,mid);
    merge_sort(mid+1,right);
    int i=left,j=mid+1;
    vector<int> temp;
    while(i<=mid&&j<=right){
        if(num[i]<=num[j]){
            temp.push_back(num[i]);
            i++;
        }else{
            ans+=mid-i+1;
            temp.push_back(num[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(num[i]);
        i++;
    }
    while(j<=right){
        temp.push_back(num[j]);
        j++;
    }
    for(int k=0;k<temp.size();k++){
        num[left+k]=temp[k];
    }
}
int main(){
    int n;
    while(cin>>n){
        ans=0;
        if(n==0)break;
        for(int i=0;i<n;i++){
            cin>>num[i];       
        }
        merge_sort(0,n-1);
        cout<<ans<<endl; 

    }
}