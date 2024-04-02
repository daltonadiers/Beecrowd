#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

map<char, vector<char>> letras;
set<char> visited;
int ans=0, caso=0;
vector<char> auxiliar;

void printer(){
    sort(auxiliar.begin(), auxiliar.end());
    for(auto e : auxiliar)cout << e << ",";
    cout << "\n";auxiliar.clear();
}

void fillLetters(int n){
    for(int i=97; i<97+n; i++)letras[i]=vector<char>();
}
void dfs(char c){
    visited.insert(c);
    auxiliar.push_back(c);
    for(auto e : letras[c]){
        if(visited.count(e)==0)dfs(e);
    }
}

int main(){
    int n,v,e;cin>> n;
    char a,b;
    while(n--){
        ans=0; caso++;
        visited.clear();
        cin >> v >> e;
        letras.clear();
        fillLetters(v);
        for(int i=0; i<e; i++){
            cin >> a >> b;
            letras[a].push_back(b);
            letras[b].push_back(a);
        }
        cout << "Case #" << caso << ":\n";
        for(auto e: letras){
            if(visited.count(e.first)==0){
                ans++;
                dfs(e.first);
                printer();
            }
        }
        cout << ans << " connected components\n\n";
    }
    return 0;
}