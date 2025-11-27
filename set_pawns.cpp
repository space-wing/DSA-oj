#include<iostream>
using namespace std;
int n,k,board[10][10]{0},ans;
int record[10][2]{0};

bool is_legal(int x,int y){
    return x>=0 and x<n and y>=0 and y<n and board[x][y] and record[x][0] and record[y][1];
}

void dfs(int x,int cnt){
    if(n-x<cnt) return;
    if(cnt==0){
        ans++;
        return;
    }

    for(int j=x;j<n;j++){
        for(int i=0;i<n;i++){
            if(is_legal(x,i)){
                record[x][0]=0;
                record[i][1]=0;
                dfs(x+1,cnt-1);
                record[x][0]=1;
                record[i][1]=1;
            }
        }   
    }
}

int main(){
    while(cin>>n>>k){
        if(n==-1 and k==-1)break;
        char c;
        ans=0;
        for(int i=0;i<n;i++){
            record[i][0]=1;
            record[i][1]=1;
            for(int j=0;j<n;j++){
                cin>>c;
                if(c=='.')board[i][j]=0;
                else board[i][j]=1;
            }
        }
        dfs(0,k);
        cout<<ans<<endl;
    }
}