#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int v,e;
map<int,vector<int>> mapa;
set<int> visited;

void trataMap(int v){
    for(int i=1; i<=v;i++){
        mapa[i]=vector<int>();
    }
}
void dfs(int src){
    visited.insert(src);
    for(auto e : mapa[src]){
        if(visited.count(e)==0)dfs(e);
    }
}

int main(){
    int ve,ue,num=0;;
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> v >> e && v && e){
        mapa.clear();
        visited.clear();
        num++;
        trataMap(v);
        for(int i=0; i<e; i++){
            cin >> ve >> ue;
            mapa[ve].push_back(ue);
            mapa[ue].push_back(ve);
        }
        int ans=0;
        for(auto e:mapa){
            if(visited.count(e.first)==0){
                ans++;
                dfs(e.first);
            }
        }
        cout << "Teste " << num << "\n";
        cout << (ans>1 ? "falha" : "normal") << "\n\n";
    }
    return 0;
}