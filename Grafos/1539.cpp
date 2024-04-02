#include <bits/stdc++.h>
using namespace std;

#define INF ((int)1e9)

typedef pair<float, int> fi;

struct edge {
    uint x;
    uint y;
    uint r;
    vector<fi> vi;
    edge() {}
    edge(uint _x, uint _y, uint _r) : x(_x), y(_y), r(_r) {}
};

int N;
edge LG[101];
vector<float> dist;

void intercept() noexcept {
    float local_dist;
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i != j) {
                local_dist = sqrt(((LG[i].x - LG[j].x) * (LG[i].x - LG[j].x)) + ((LG[i].y - LG[j].y) * (LG[i].y - LG[j].y)));
                if (LG[i].r >= local_dist){
                    LG[i].vi.push_back(fi(local_dist, j));
                }
                if (LG[j].r >= local_dist){
                    LG[j].vi.push_back(fi(local_dist, i));
                }
            }
        }
    }
}

void dijkstra(int u) noexcept {
    dist.assign(N + 1, INF);
    dist[u] = 0;
    priority_queue<fi, vector<fi>, greater<fi>> Q;
    Q.push(fi(0, u));
    while (!Q.empty()) {
        int next = Q.top().second; Q.pop();
        for (auto &e : LG[next].vi) {
            int v = e.second; 
            float w = e.first; 
            if (dist[v] > dist[next] + w) {
                dist[v] = dist[next] + w;
                Q.push(fi(ceil(dist[v]), v));
            }
        }
    }
}

int main() {
    int x, y, r, k, u, v;
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N && N) {
        for (int i = 1; i <= N; ++i) {
            cin >> x >> y >> r;
            LG[i] = edge(x, y, r);
        }
        intercept();
        cin >> k;
        int theLastDijk=-1;
        for (int i = 0; i < k; ++i) {
            cin >> u >> v;
            if(u!=theLastDijk){
                theLastDijk=u;
                dijkstra(u);
            }
            cout << ((dist[v] == INF) ? -1 : static_cast<int>(dist[v])) << "\n";
        }
    }
    return 0;
}