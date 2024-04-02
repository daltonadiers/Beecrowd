#include <bits/stdc++.h>

using namespace std;

char matriz[52][52];
bool visited[52][52];
int v,a;

int di[4]={-1,0,0,+1};
int dj[4]={0,-1,+1,0};

bool is_valid(int i, int j){
    return 0 <= i && i < v && 0 <= j && j < a;
}

void flood(int i, int j){
    if(!is_valid(i,j) || visited[i][j] || matriz[i][j]=='X')return;
    visited[i][j] =true;
    matriz[i][j]= 'T';
    for(int k = 0; k<4; k++){
        flood(i + di[k], j + dj[k]);
    }
}

int main(){
    while(cin >> v >> a && v && a){
        for(int i=0; i<v; i++){
            for(int j=0; j<a; j++){
                cin >> matriz[i][j];
            }
        }
        memset(visited,false,sizeof(visited));
        for(int i=0; i<v; i++){
            for(int j=0; j<a; j++){
                if(matriz[i][j]=='T')flood(i,j);
            }
        }
        for(int i=0; i<v; i++){
            for(int j=0; j<a; j++){
                cout << matriz[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}