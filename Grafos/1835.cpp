#include <bits/stdc++.h>
using namespace std;

int V, E;
map<int, vector<int>> LG;
vector<bool> vis;

void dfs(int v) noexcept{
    vis[v] = true;
    for(auto &e : LG[v])
        if(!vis[e])
            dfs(e);
}

int main(){
    int t, u, v, cases = 0; cin >> t;
    while(t--){
        int ans = 0;
        LG.clear();
        cases++;
        cin >> V >> E;
        if(V == 1){
            cout << "Caso #" << cases << ": " << "a promessa foi cumprida\n";
            continue;
        }
        else if(!E){
            cout << "Caso #" << cases << ": " << "ainda falta(m) " << V - 1 << " estrada(s)\n";
            continue;
        }
        for(int i = 1; i <= V; i++)
            LG[i] = vector<int>();
        for(int i = 0; i < E; i++){
            cin >> u >> v;
            LG[u].push_back(v);
            LG[v].push_back(u);
        }
        vis.assign(V + 1, false);
        for(auto &e : LG){
            if(!vis[e.first]){
                dfs(e.first);
                ans++;
            }
        }
        if(!(ans - 1))
            cout << "Caso #" << cases << ": " << "a promessa foi cumprida\n";
        else
            cout << "Caso #" << cases << ": " << "ainda falta(m) " << ans - 1 << " estrada(s)\n";
    }
    return 0;
}