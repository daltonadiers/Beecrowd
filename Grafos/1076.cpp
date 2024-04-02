/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1076
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef vector<int> vi;
int n,v,e,counter =0;
unordered_map<int,vi> grafo;
unordered_map<int, bool> visited;

void dfs(int nodo){
    visited[nodo]=true;
    for(auto& e: grafo[nodo]){
        if(!visited[e]){
            counter++;
            dfs(e);
        }
    }
}



int main(){
    int t, a,b; cin >> t;
    while(t--){
      cin >> n >> v >> e;
        for(int i=0; i<e; i++){
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        dfs(n); cout << counter*2 << endl;
        visited.clear(); grafo.clear(); counter=0;
    }
    return 0;
}