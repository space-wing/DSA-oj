#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int main(){
    int P,Q,R;
    cin>>P;
    string name[40];
    map<string,int> index_name;
    for(int i=0;i<P;i++){
        cin>>name[i];
        index_name[name[i]]=i;
    }
    cin>>Q;   
    int graph[40][40]{0};
    for(int i=0;i<Q;i++){
        string from,to;
        int cost;
        cin>>from>>to>>cost;
        int from_index=index_name[from];
        int to_index=index_name[to];
        graph[from_index][to_index]=cost;
        graph[to_index][from_index]=cost;
    }
    int floyd[40][40],path[40][40];
    for(int i=0;i<P;i++){
        for(int j=0;j<P;j++){
            floyd[i][j]=1e9;
            path[i][j]=j;
            if(i==j)floyd[i][j]=0;
            if(graph[i][j]){
                floyd[i][j]=graph[i][j];
            }
        }
    }
    for(int k=0;k<P;k++){
        for(int i=0;i<P;i++){   
            for(int j=0;j<P;j++){
                if(floyd[i][k]+floyd[k][j]<floyd[i][j]){
                    floyd[i][j]=floyd[i][k]+floyd[k][j];
                    path[i][j]=path[i][k];
                }
            }
        }
    }
    cin>>R;
    for(int i=0;i<R;i++){
        string start,end;
        cin>>start>>end;
        int start_index=index_name[start];
        int end_index=index_name[end];
        int k=start_index;
        while(k!=end_index){
            cout<<name[k]<<"->("<<to_string(floyd[k][path[k][end_index]])<<")->";
            k=path[k][end_index];
        }
        cout<<end<<endl;
    }
}