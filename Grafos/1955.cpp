#include <iostream>

using namespace std;
#define MAX 1123

int n, ag[MAX][MAX], vis[MAX];

int dfs(int u, int c){
    int v, ans=1;
    if(vis[u]) return vis[u]==c;
    vis[u]=c;
    for(v=0;v<n;v++){
        if(ag[u][v]) ans &= dfs(v, c^3);
    }
    return ans;
}

int main(){
    int u, v, ans=1;
    cin >> n;
    for(u=0; u<n;u++){
        for(v=0; v<n;v++){
            cin >> ag[u][v];
            ag[u][v] = !ag[u][v];
        }
    }
    for(u=0; u<n;u++){
        if(!vis[u])ans &=dfs(u,1);
    }
    if(ans)cout << "Bazinga!\n"; else cout << "Fail!\n";
    return 0;
}