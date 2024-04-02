#include <iostream>
#include <queue>
#include <set>
using namespace std;
int movementsx[]={2,-2,2,-2,1,-1,1,-1};
int movementsy[]={-1,-1,1,1,2,2,-2,-2};

void updateQueue(queue<pair<pair<char,char>,int>>& q, pair<pair<char,char>,int>& aux, set<pair<char,char>>& visited){
    for(int i=0; i<8; i++){
        char x = aux.first.first+movementsx[i];
        char y = aux.first.second+movementsy[i];
        if(visited.count(make_pair(x,y))==0 && x>=97 && x<=104 && y>=49 && y<=56)q.push(make_pair(make_pair(x, y), aux.second+1));
    }
}

int bfs(string& from, string& to){
    set<pair<char,char>> visited;
    queue<pair<pair<char,char>,int>> q; 
    q.push(make_pair(make_pair(from[0],from[1]),0));
    while(!q.empty()){
        pair<pair<char,char>,int> auxiliar = q.front(); q.pop();
        visited.insert(make_pair(auxiliar.first.first, auxiliar.first.second));
        if(auxiliar.first.first==to[0] && auxiliar.first.second==to[1])return auxiliar.second;
        updateQueue(q, auxiliar, visited);
    }
    return -1;   
}


int main(){
    string from, to;
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin>> from >> to)cout << "To get from " << from << " to " << to << " takes " << bfs(from,to) << " knight moves.\n";
    return 0;
}