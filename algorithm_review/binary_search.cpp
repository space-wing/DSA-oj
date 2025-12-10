#include<iostream>

using namespace std;

int binary_search(int* num,int l,int r,int target){
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(num[mid]==target)return mid;
        else if(num[mid]<target)l=mid+1;
        else r=mid-1;
    }
    return -1;
}

