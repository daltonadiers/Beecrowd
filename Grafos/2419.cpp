#include <bits/stdc++.h>

using namespace std;

char matriz[1123][1123];
int v,a, ans=0;

void validator(int i, int j){
    if(i==0 || j==0 || i==v-1 || j==a-1){
        ans++;
        return;
    }
    if(i>0 && matriz[i-1][j]=='.'){
        ans++;
        return;
    }
    if(i<v && matriz[i+1][j]=='.'){
        ans++;
        return;
    }
    if(j>0 && matriz[i][j-1]=='.'){
        ans++;
        return;
    }
    if(j<a && matriz[i][j+1]=='.'){
        ans++;
        return;
    }
}

int main(){
    cin >> v >> a;
    for(int i=0; i<v; i++){
        for(int j=0; j<a; j++){
            cin >> matriz[i][j];
        }
    }
    for(int i=0; i<v; i++){
        for(int j=0; j<a; j++){
            if(matriz[i][j]=='#'){
                validator(i,j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}