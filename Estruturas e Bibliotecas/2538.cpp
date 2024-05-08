#include <iostream>
#include <cstring>

using namespace std;
#define MAX 100001

int bit[MAX];
int n;

void update(int i, int x){
    for (; i < MAX; i += i&-i) bit[i] += x;
}
int query(int i){
    int sm = 0;
    for (; i > 0; i -= i&-i) sm += bit[i];
    return sm;
}
int query(int i, int j){
    return query(j) - (i==1? 0 : query(i-1));
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ip, m;
    while(cin >> ip >> m){
        memset(bit, 0, sizeof bit);
        int ans=0;
        for(int i=0; i<m; i++){
            int pc, na;
            cin >> pc >> na;
            int a = pc-ip>1 ? pc-ip : 1;
            int b = pc+ip<MAX ? pc+ip : MAX;
            if(query(a,b)<=na){
                update(pc, 1);
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}