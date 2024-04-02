#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF ((int)1e9)
typedef pair<int, int> ii;
typedef vector<ii> vii;
int v, e;
vector<int> dist;
vector<vii> LG;
vector<int> caminho;
vector<int> path;

void updateVec(int pai, int add){
    vector<int> path;
    for(auto& e:caminho){
        if(e==pai){
            path.push_back(e);
            break;
        }path.push_back(e);
    }
    path.push_back(add);
    caminho.clear();
    caminho = path;
}

void dijkstra(int s) {
    dist.assign(v + 1, INF);
    path.assign(v + 1, -1);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push(ii(0, s));
    caminho.push_back(s);
    while (!Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        for (auto e : LG[u]) {
            int w = e.first, v = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                Q.push(ii(dist[v], v));
                path[v] = u;
            }
        }
    }
}
const string showpath(int dest){
    if(path[dest] == -1)return "\n";
    string s = "";
    vector<int> temp;
    int atual = dest;
    while(atual != -1){
        temp.push_back(atual);
        atual = path[atual];
    }
    reverse(temp.begin(), temp.end());
    for(size_t i = 0; i < temp.size() - 1; i++)s += to_string(temp[i]) + " ";
    s += to_string(temp.back()) + "\n";
    return s;
}

int main() {
    int c1, c2, p, d;
    while (cin >> v >> e && v && e) {
        LG.assign(v + 1, vii());
        for (int i = 0; i < e; i++) {
            cin >> c1 >> c2 >> p;
            LG[c1].push_back(ii(p, c2));
            LG[c2].push_back(ii(p, c1));
        }
        cin >> d;
        dijkstra(d);
        if(dist[1]>120)cout << "It will be " << dist[1]-120 << " minutes late. Travel time - " << dist[1] << " - best way - " << showpath(1);
        else cout << "Will not be late. Travel time - " << dist[1] << " - best way - " << showpath(1);
    }
    return 0;
}