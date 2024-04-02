#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

typedef vector<string> vs;
unordered_map<string,bool> vis;
unordered_map<string,vs> adj;
int v,a, ansP=0;
string busca = "*", partida="Entrada";

void setAllFalse(){
    for(auto& e:vis){
        e.second=false;
    }
}

void bfs(){
    queue<pair<string,int>> q;
    q.push(make_pair(partida,0));
    vis[partida]=true;
    while(!q.empty()){
        pair aux = q.front(); q.pop();
        vis[aux.first]=true;
        if(aux.first==busca){
            ansP+=aux.second; partida="*";busca="Saida"; return;
        }
        const vs& vetor = adj[aux.first];
        for(size_t i=0; i<vetor.size(); i++){
            if(!vis[vetor[i]])q.push(make_pair(vetor[i],aux.second+1));
        }
    }
}

int main(){
    cin >> v >> a;
    string entry1, entry2;
    for(int i=0; i<a; i++){
        cin >> entry1 >> entry2;
        adj[entry1].push_back(entry2);
        adj[entry2].push_back(entry1);
    }
    bfs(); setAllFalse(); bfs();
    cout << ansP << "\n";
    return 0;
}