#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m, ns, np;
    string app;
    while(cin >> n >> m && n && m){
        unordered_map<int, set<string>> servidores;
        for(int i=0; i<n; i++){
            cin >> ns;
            while(ns--){
                cin >> app;
                servidores[i].insert(app);
            }
        }
        int ans =0;
        for(int i=0; i<m; i++){
            cin >> np;
            set<int> isConnected;
            while(np--){
                cin >> app;
                for(int j=0; j<n; j++){
                    if(!isConnected.count(j) && servidores[j].count(app)){
                        ans++;
                        isConnected.insert(j);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}