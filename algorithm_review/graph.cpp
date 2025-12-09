#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1e5;
//dijkstra算法求解单源最短路径
int dis[maxn],vis[maxn],graph[maxn][maxn],n;
void dijkstra(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        if(vis[p.second])continue;
        vis[p.second]=1;
        for(int i=0;i<n;i++){
            if(!vis[i] and dis[i]>p.first+graph[p.second][i]){
                dis[i]=p.first+graph[p.second][i];
                pq.push({dis[i],i});
            }
        }
    }
}

//floyd算法求解多源最短路径
int dist[maxn][maxn];
void floyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                dist[j][i]=dist[i][j];
            }
        }
    }
}

//Kruskal算法求解最小生成树
struct edge
{
    int u,v,w;
    bool operator<(const edge a)const{
        return w<a.w;
    }
};
vector<edge> E,ans;
int p[maxn];
int find(int x){
    if(p[x]!=x){
        p[x]=find(p[x]);
    }
}
void Kruskal(){
    for(int i=0;i<n;i++)p[i]=i;
    sort(E.begin(),E.end());
    for(edge e:E){
        int x=find(e.u),y=find(e.v);
        if(x!=y){
            p[x]=y;
            ans.push_back(e);
        }
    }
}


//Prim算法求解最小生成树