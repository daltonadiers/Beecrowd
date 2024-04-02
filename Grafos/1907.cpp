#include <iostream>
#include <queue>

using namespace std;
#define MAX 11234

char matriz[MAX][MAX];
int n,m;

void dfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;
        if (matriz[x][y] != '.') continue;
        matriz[x][y] = 'o';
        if (x-1 >= 0 && matriz[x-1][y] == '.') q.push({x-1, y});
        if (x+1 < n && matriz[x+1][y] == '.') q.push({x+1, y});
        if (y-1 >= 0 && matriz[x][y-1] == '.') q.push({x, y-1});
        if (y+1 < m && matriz[x][y+1] == '.') q.push({x, y+1});
    }
}

int main(){
    while(cin >> n >> m){
        for(int i=0; i<n;i++)for(int j=0;j<m;j++){
            cin >> matriz[i][j];
        }
        int ans = 0;
        for(int i=0; i<n;i++)for(int j=0;j<m;j++){
        if(matriz[i][j]=='.'){
                ans++;
                dfs(i,j);
        }         
        }
        cout << ans << "\n";
    }
    return 0;
}