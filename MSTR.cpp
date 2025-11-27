#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int graph[30][30]{0};
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        char from;
        cin>>from;
        int num;
        cin>>num;
        for(int j=0;j<num;j++){
            char to;
            cin>>to;
            int to_index=to-'A';
            int path;
            cin>>path;
            graph[i][to_index]=path;
            graph[to_index][i]=path;
        }
    }
    bool visited[30]{false};
    int total=n;
    visited[0]=true;
    total--;
    int result=0;
    while(total--){
        int min_index=-1,min_value=1e9;
        for(int i=0;i<n;i++){
            if(visited[i]){
                for(int j=0;j<n;j++){
                    if(graph[i][j]&&!visited[j]){
                        if(graph[i][j]<min_value){
                            min_value=graph[i][j];
                            min_index=j;
                        }
                    }
                }
            }
        }
        visited[min_index]=true;
        result+=min_value;
    }
    cout<<result;
}
