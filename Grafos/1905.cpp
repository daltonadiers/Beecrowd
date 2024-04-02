#include <iostream>
#include <set>

using namespace std;

int lab[5][5];
set<pair<int,int>> visited;

void dfs(int x,int y){
    if(visited.count(make_pair(x,y))>0)return;
    visited.insert(make_pair(x,y));
    if(lab[x][y]==1)return;
    for(int i=0; i<4;i++){
        if(x-1>=0)dfs(x-1,y);
        if(x+1<5)dfs(x+1,y);
        if(y-1>=0)dfs(x,y-1);
        if(y+1<5)dfs(x,y+1);
    }
    return;
}

int main(){
    int t; cin >> t;
    while(t--){
        visited.clear();
        for(int i=0; i<5;i++)for(int j=0; j<5;j++)cin >> lab[i][j];
        dfs(0,0);
        if(visited.count(make_pair(4,4)))cout << "COPS\n";
        else cout << "ROBBERS\n";
    }
    return 0;
}