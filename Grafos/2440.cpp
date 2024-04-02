#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int V, E; // V -> Vertices / E -> Edges
vector<vi> LG;
vector<bool> visited;

void dfs(int u){
    visited[u] = true;
    for(auto n : LG[u])
        if(!visited[n])
            dfs(n);
}

int main(){
    int src, dest, ans = 0;
    cin >> V >> E;
    LG.assign(V + 1, vi());
    for(int i = 0; i < E; i++){
        cin >> src >> dest;
        LG[src].push_back(dest);
        LG[dest].push_back(src);
    }
    visited.assign(V + 1, false);
    for(int i = 1; i <= V; i++){
        if(!visited[i]){
            ans++;
            dfs(i);
        }
    }
    cout << ans << endl;
    return 0;
}