#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 112345

bool vis[MAX];

int reverse(int n){
    int rev =0;
    while(n!=0){
        rev= rev*10;
        rev = rev +n%10;
        n = n/10;
    }
    return rev;
}

int bfs(int &origem, int &dest){
    memset(vis, false, sizeof vis);
    queue<pair<int, int>> q;
    q.push({origem,0});
    vis[origem]=true;
    while(!q.empty()){
        int top = q.front().first;
        int moves = q.front().second;
        q.pop();
        if(top==dest)return moves;
        int rev = reverse(top);
        if(!vis[rev] && rev<=10000){
            vis[rev]=true;
            q.push({rev, moves+1});
        }
        if(!vis[top+1] && rev<=10000){
            q.push({top+1,moves+1});
            vis[top+1]=true;
        }
    }
    return -1;
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    int origem, destino;
    int n;
    cin >> n;
    while(n--){
        cin >> origem >> destino;
        cout << bfs(origem, destino) << "\n";
    }
    return 0;    
}