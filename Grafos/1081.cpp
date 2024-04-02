#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

map<int, vector<int>> graph;
set<int> visited;
string spaces="";

void dfs(int v){
    visited.insert(v);
    if(graph[v].size()>0){
        spaces+="  ";
    for(auto e:graph[v]){
        if(visited.count(e)==0){
            cout << spaces << v << "-" << e << " pathR(G," << e << ")\n";
            dfs(e);
        }else{
            cout << spaces << v << "-" << e << "\n";
        }
    }
    spaces.pop_back();spaces.pop_back();
    }
}

int main(){
    int n,v,e, casos=0;; cin >> n;
    int a,b;
    while(n--){
        visited.clear(); graph.clear(); spaces="";
        casos++;
        cin >> v >> e;
        for(int i=0; i<e; i++){
            cin >> a >> b;
            graph[a].push_back(b);
        }
        for(auto& e: graph)sort(e.second.begin(), e.second.end());
        cout << "Caso " << casos << ":\n";
        for(auto e:graph){
            if(visited.count(e.first)==0){
                dfs(e.first);
                cout << "\n";
            }
        }
    }
    return 0;
}