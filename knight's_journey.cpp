#include<iostream>
using namespace std;
int p,q,np;
bool isFound;

bool is_in_map(int x,int y){
    return x>=1 && x<=p && y>=1 && y<=q;
}

struct point
{
    int x;
    char y;
}path[1005];

bool mark[30][30];

int dir[8][2]={
    {-1,-2},{1,-2},{-2,-1},{2,-1},
    {-2,1},{2,1},{-1,2},{1,2}
};

void dfs(int x,int y){
    if(isFound)return;
    mark[x][y]=1;
    path[np].x=x;
    path[np].y='A'+y-1;
    np++;
    if(np==p*q){
        isFound=true;
        return;
    }
    int nx,ny;
    for(int i=0;i<8;i++){
        nx=x+dir[i][0];
        ny=y+dir[i][1];
        if(is_in_map(nx,ny)&&!mark[nx][ny]){
            dfs(nx,ny);
        }
    }
    if(isFound)return;
    mark[x][y]=0;
    np--;

}


int main(){
    int t;
    cin>>t;
    for(int tt=0;tt<t;tt++){
        isFound=false;
        np=0;
        cout<<"Scenario #"<<tt+1<<":"<<endl;
        cin>>p>>q;
        for(int i=0;i<p*q;i++){
            path[i].x=0;
            path[i].y=' ';
        }
        for(int i=0;i<=p;i++){
            for(int j=0;j<=q;j++){
                mark[i][j]=false;
            }
        }
        dfs(1,1);
        if(isFound){
            for(int i=0;i<p*q;i++){
                cout<<path[i].y<<path[i].x;
            }
            cout<<endl;
        }
        else{
            cout<<"impossible"<<endl;
        }
        cout<<endl;
    }
}