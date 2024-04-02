#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 1123

int matriz[MAX][MAX];
int x,y;
bool visited[MAX][MAX];

void bfs(int i, int j){
    //visited.insert(make_pair(i,j));
    queue<pair<int,int>> q;
    pair<int,int> teste;
    q.push(make_pair(i,j));
    visited[i][j]=true;
    while(!q.empty()){
        pair<int,int> aux = q.front(); q.pop();
        if(aux.first+1 < x && !visited[aux.first+1][aux.second] && matriz[aux.first+1][aux.second]==1){teste.first = aux.first+1; teste.second=aux.second;q.push(teste);visited[teste.first][teste.second]=true;}
        if(aux.first-1 >= 0 && !visited[aux.first-1][aux.second] && matriz[aux.first-1][aux.second]==1){teste.first = aux.first+-1; teste.second=aux.second;q.push(teste);visited[teste.first][teste.second]=true;}
        if(aux.second+1 < y && !visited[aux.first][aux.second+1] && matriz[aux.first][aux.second+1]==1){teste.first = aux.first; teste.second=aux.second+1;q.push(teste);visited[teste.first][teste.second]=true;}
        if(aux.second-1 >= 0 && !visited[aux.first][aux.second-1] && matriz[aux.first][aux.second-1]==1){teste.first = aux.first; teste.second=aux.second-1;q.push(teste);visited[teste.first][teste.second]=true;}
    }
}

int main(){
    int ans=0;
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> y;
    memset(visited, false, sizeof visited);
    for(int i=0; i<x; i++)for(int j=0; j<y;j++)cin>> matriz[i][j];
    for(int i=0; i<x; i++)for(int j=0; j<y;j++){
        if(!visited[i][j] && matriz[i][j]==1){
            ans++;
            bfs(i,j);
        }
    }
    cout << ans << "\n";
    return 0;
}