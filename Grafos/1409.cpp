// ZAK GALOU

#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define INF ((int)1e9)
#define MONSTER 10001
typedef pair<int, int > ii;
typedef vector<ii> vii;

struct magia{
    int custo, dano;
    magia(int custo_, int dano_) : custo(custo_), dano(dano_){}
};

int M,N,G,K;
vector<vii> LG;
vector<int> dist;
int pesoSalao[MONSTER];
vector<magia> magias;
int monsterMemo[MONSTER];
int damage,pos;


int pd(int vida){
    if(vida <= 0) return 0;
    if(monsterMemo[vida] != INF) return monsterMemo[vida];
    int custo = INF;
    for(size_t i=0; i<magias.size(); i++){
            custo = min(custo, pd(vida-magias[i].dano) + magias[i].custo);
    }
    return monsterMemo[vida] = custo;
}
void dijkstra(int s){
    dist.assign(N+1, INF);
    dist[s] = 0;
    priority_queue<ii,vector <ii>, greater <ii>> Q;
    Q.push(ii(0, s));
    while (!Q.empty ()){
        int u = Q.top (). second; Q.pop ();
        for(auto e : LG[u]){
            int v = e.first , w = pesoSalao[v];
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                Q.push(ii(dist[v], v));
            }
        }
    }
}
void cleaner(){
    LG.clear();
    magias.clear();
    dist.clear();
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int u,v,i, mana, dano, salao, vida;
    while(cin >> M >> N >> G >> K){
        if(!M && !N && !G && !K)break;
        cleaner();
        for(i = 0; i < MONSTER; i++) {
            monsterMemo[i] = INF;
            pesoSalao[i]=0;
        }
        for(i=0; i<M; i++){
            cin >> mana >> dano;
            magias.push_back(magia(mana, dano));
        }
        LG.resize(N+1);
        for(i=0; i<G; i++){
            cin >> u >> v;
            LG[u].push_back({v,0});
            LG[v].push_back({u,0});
        }
        for(i=0; i<K; i++){
            cin >> salao >> vida;
            monsterMemo[vida]=pd(vida);
            pesoSalao[salao]+=monsterMemo[vida];
        }
        dijkstra(1);
        cout << (dist[N]==INF ? -1 : dist[N]+pesoSalao[1]) << "\n";
    }
    return 0;
}