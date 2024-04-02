#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#define INF ((int)1e9)

using namespace std;

typedef pair <int , int > ii;
typedef vector <ii > vii;


int N, M;
vector <int> dist;
vector <vii> LG;
int lastSrc=-1000000;

void dijkstra(int s){
    dist.assign(N+1, INF);
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
bool normalize(int b, int a){
    for(auto& e: LG[b]){
        if(e.first==a){
            e.second=0;
            return true;
        }
    }
    return false;
}

int main(){
    bool first=true;
    while(true){
        cin >> N >> M;
        if(!N && !M)break;
        if(first)first=false;
        else cout << "\n";
        dist.clear();LG.clear();lastSrc=-1000000;
        LG.resize(N+1);
        int a,b,c; 
        for(int i=0; i<M; i++){
            cin >> a >> b >> c;
            if(normalize(b,a))LG[a].push_back(make_pair(b, 0));
            else LG[a].push_back(make_pair(b, c));
        }
        int k; cin >> k;
        while(k--){
            int source, dest; 
            cin >> source >> dest;
            if(source!=lastSrc){
                dijkstra(source);
                lastSrc=source;
            }
            if(dist[dest]==INF)cout << "Nao e possivel entregar a carta\n";
            else cout << dist[dest] << "\n";
        }
    }
    cout << "\n";
    return 0;
}