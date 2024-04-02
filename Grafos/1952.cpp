#include <bits/stdc++.h>
using namespace std;

#define MAX 112
#define INF 112345678

struct pos{
    int i,j,k;
    pos(){}
    pos(int _i, int _j, int _k):i(_i),j(_j),k(_k){}
};

int n,m,l, dist[MAX][MAX][MAX];
int di[]={2,1,-2,-1,2,1,-2,-1,2,0,-2,0,2,0,-2,0,1,0,-1,0,1,0,-1,0};
int dj[]={1,2,1,2,-1,-2,-1,-2,0,2,0,-2,0,2,0,-2,0,1,0,-1,0,1,0,-1};
int dk[]={0,0,0,0,0,0,0,0,1,1,1,1,-1,-1,-1,-1,2,2,2,2,-2,-2,-2,-2};

int bfs(pos s, pos t){
    queue<pos> q;
    for(int i=1; i<=n; i++)for(int j=1; j<=m; j++)for(int k=1; k<=l;k++)dist[i][j][k]=INF;
    dist[s.i][s.j][s.k] = 0; q.push(s);
    while(!q.empty()){
        pos u = q.front(); q.pop();
        for(int mov=0; mov<24;mov++){
            int _i=u.i+di[mov],_j=u.j+dj[mov],_k=u.k+dk[mov];
            if(_i>=1 && _i<=n && _j>=1 && _j<=m && _k>=1 && _k<=l && dist[_i][_j][_k]==INF){
                dist[_i][_j][_k] = dist[u.i][u.j][u.k]+1;
                q.push(pos(_i,_j,_k));
            }
        }
    }
    return dist[t.i][t.j][t.k];
}

int main(){
    pos s,t;
    cin >> n >> m >> l;
    cin >> s.i >> s.j >> s.k >> t.i >> t.j >> t.k;
    cout << bfs(s,t) << "\n";
}