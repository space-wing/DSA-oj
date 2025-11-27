#include<iostream>
#include<algorithm>
#include<vector> 
#include<cmath>
using namespace std;
struct point
{
    int x;
    int y;
    int z;
    int num;
    double distance(point& other)
    {
        return sqrt((x - other.x) * (x - other.x) +
                    (y - other.y) * (y - other.y) +
                    (z - other.z) * (z - other.z));
    }
};
struct distances
{
    point x1;
    point x2;
    double dist;
    bool operator<(const distances& other)const
    {   
        if(dist!=other.dist)return dist > other.dist;
        else{
            if(x1.num!=other.x1.num)return x1.num < other.x1.num;
            else return x2.num < other.x2.num;
        }
    }
};
int main(){
    int n;
    cin>>n;
    vector<point> points(n);
    for(int i=0;i<n;i++){
        cin>>points[i].x>>points[i].y>>points[i].z;
        points[i].num=i;
    }
    vector<distances> dists;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(i!=j){
                distances d;
                d.x1=points[i];
                d.x2=points[j];
                d.dist=points[i].distance(points[j]);
                dists.push_back(d);
            }
        }
    }
    sort(dists.begin(),dists.end());
    for(auto& dist:dists){
        cout<<"("<<dist.x1.x<<","<<dist.x1.y<<","<<dist.x1.z<<")-("<<dist.x2.x<<","<<dist.x2.y<<","<<dist.x2.z<<")="<<fixed;
        cout.precision(2);
        cout<<dist.dist<<endl;
    }
}