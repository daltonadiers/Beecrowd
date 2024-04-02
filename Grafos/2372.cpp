#include<bits/stdc++.h>

#define INF ((int)1e9)

using namespace std;

typedef pair <int , int > ii;
typedef vector <ii > vii;

int N, M;
vector <int> dist;
vector <vii> LG;
vector<int> maiores;

void dijkstra(int s){
    dist.assign(N, INF);
    dist[s] = 0;
    priority_queue <ii , vector <ii >, greater <ii > > Q;
    Q.push(ii(0, s));
    while (!Q.empty ()){
        int u = Q.top (). second; Q.pop ();
        for(auto e : LG[u]){
            int v = e.first , w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                Q.push(ii(dist[v], v));
            }
        }
    }
}

int main(){
    cin >> N >> M;
    int u,v,w;
    LG.assign(N,vii());
    for (int i = 0; i < M; i++){
        cin >> u >> v>> w;
        LG[u].push_back(ii(v,w));
        LG[v].push_back(ii(u,w));
    }
    
    for (int i = 0; i < N; ++i) {
        int maiorDist=0;
        dijkstra(i);
        for(auto& e:dist){
            if(e>maiorDist)maiorDist=e;
        }
        maiores.push_back(maiorDist);
    }
    sort(maiores.begin(), maiores.end());

    cout << maiores[0] << endl;

    return 0;
}