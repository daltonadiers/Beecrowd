#include <iostream>
#include <cstring>

#define MAX 51
using namespace std;

int n;
int dias[MAX];

int solve(){
    int a=0, b=0;
    for(int i=0; i<n; i++){
        a = max(0, a+dias[i]);
        b = max(b, a);
    }
    return b;
}
int main(){
    ios_base::sync_with_stdio(false);
    int custo;
    while(cin >> n){
        memset(dias, 0, sizeof(dias));
        cin >> custo;
        for(int i=0; i<n; i++){
            cin >> dias[i]; dias[i]-=custo;
        }
        cout << solve() << "\n";
    }
    return 0;
}