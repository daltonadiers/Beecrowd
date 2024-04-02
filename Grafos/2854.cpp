#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<string,vector<string>> familias;
set<string> visited;

void dfs(string src){
    visited.insert(src);
    for(auto& e: familias[src]){
        if(visited.count(e)==0)dfs(e);
    }
}

int main(){
    int v,e;
    string a,lixo,b;
    cin >> v >> e;
    for(int i=0; i<e; i++){
        cin >> a >> lixo >> b;
        familias[a].push_back(b);
        familias[b].push_back(a);
    }
    int ans=0;
    for(auto& e: familias){
        if(visited.count(e.first)==0){
            ans++;
            dfs(e.first);
        }
    }
    cout << ans << "\n";
    return 0;
}