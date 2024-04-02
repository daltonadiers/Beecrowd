#include <iostream>

using namespace std;

#define MAX 123

char mapa[MAX][MAX], letter;
int visited[MAX][MAX];
int c, l;
string op;

void fillVisited(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            visited[i][j]=0;
        }
    }
}
int bfs(int x, int y){
    if(x<0 || y<0 || x>=l || y>=c)return 0;
    if(visited[x][y])return 0;
    if(mapa[x][y]!='.')visited[x][y]=1;
    if(mapa[x][y]=='*')return 1;
    else if(mapa[x][y]=='>'){
        op="increment"; letter='y';return bfs(x, y+1); 
    }
    else if(mapa[x][y]=='^'){
        op="decrement"; letter='x';return bfs(x-1, y);
    }
    else if(mapa[x][y]=='v'){
        op="increment"; letter='x';return bfs(x+1, y);
    }
    else if(mapa[x][y]=='<'){
        op="decrement"; letter='y';return bfs(x, y-1);
    }
    else if(mapa[x][y]=='.'){
        if(op=="increment" && letter=='y')return bfs(x, ++y);
        else if(op=="increment" && letter=='x')return bfs(++x, y);
        else if(op=="decrement" && letter=='x')return bfs(--x, y);
        else if(op=="decrement" && letter=='y')return bfs(x, --y);
    }
    return 0;
}

int main(){
    cin >> c >> l;
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            cin >> mapa[i][j];
        }
    }
    if(bfs(0,0))cout << "*\n";
    else cout << "!\n";
    return 0;
}