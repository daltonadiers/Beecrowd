#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int V, E;
bool cycle = false;
vector<vi> LG;
vector<int> vis;

void DFSCycle(int u){
    vis[u] = 1;
    if(cycle) return;
    for(auto v : LG[u]){
        if(vis[v] == 1){
            cycle = true;
            return;
        }
        else if(!vis[v]) DFSCycle(v);
    }
    vis[u] = 2;
}

int main(){
    int t, src, dest; cin >> t;
    while(t--){
        cin >> V >> E;
        LG.assign(V + 1, vi());
        vis.assign(V + 1, 0);
        cycle = false;
        for(int i = 0; i < E; i++){
            cin >> src >> dest;
            LG[src].push_back(dest);
        } 
        for(int i = 1; i <= V; i++){
            if(!vis[i]) DFSCycle(i);
            if(cycle) break;
        }
        cout << (cycle ? "SIM" : "NAO") << endl;
    }
    return 0;
}