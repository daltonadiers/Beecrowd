#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 123

int padj[MAX][MAX][10];
char mapa[MAX][MAX];
int n, p;
bool found;


struct forBfs{
    int i, j, moves;
    forBfs(int i_, int j_, int moves_) : i(i_), j(j_), moves(moves_){}
};  

vector<pair<int,int>> portais;
vector<pair<int,int>> duendes;

int moveX[] = {0,0,1,-1};
int moveY[] = {1,-1,0,0};

void bfs(int i, int j, int duende){
    bool visited[MAX][MAX];
    found = false;
    memset(visited, false, sizeof visited);
    queue<forBfs> q;
    q.push(forBfs(i,j,0));
    while(!q.empty()){
        forBfs top = q.front();
        q.pop();
        if(mapa[top.i][top.j]=='X'){ 
            padj[top.i][top.j][duende]=top.moves;
            found=true;
        }
        for(int i=0; i<4; i++){
            int auxI = top.i + moveX[i];
            int auxJ = top.j + moveY[i];
            if(auxI >=0 && auxI<n && auxJ>=0 && auxJ<n && !visited[auxI][auxJ] && mapa[auxI][auxJ]!='#'){
                visited[auxI][auxJ]=true;
                q.push(forBfs(auxI, auxJ, top.moves+1));
            }
        }
    }
}
vector<int> solves;
void solve(vector<pair<int,int>> &port){
    int maxDist = 0;
    for(int i=0; i<(int)duendes.size();i++){
        if(padj[port[i].first][port[i].second][i] !=-1){ 
            //cout << "eu chego entrar aqui?\n";
            int dist = padj[port[i].first][port[i].second][i];
            maxDist = max(maxDist, dist);
        }else{
            //cout << "return\n";
            return;
        } 
    }
    solves.push_back(maxDist);
}



int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        memset(padj, -1, sizeof padj);
        portais.clear();
        duendes.clear();
        solves.clear();
        cin >> n >> p;
        for(int i=0; i<n; i++)for(int j=0; j<n;j++){
            cin >> mapa[i][j];
            if(mapa[i][j]=='G'){
                duendes.push_back({i,j});
            }else if(mapa[i][j]=='X')portais.push_back({i,j});
        }
        //CASO HAJAM MENOS PORTAIS DO QUE DUENDUES, PODEMOS ENCERRAR O TESTE ATUAL
        if(portais.size()<duendes.size()){
            cout << "-1\n";
            continue;
        }
        bool passPadj = true;
        int counterDuendes =-1;
        //PARA CADA DUENDE, IREMOS CALCULAR TODAS SUAS ADJASCÊNCIAS A X ATRAVÉS DE BFS,
        //GUARDANDO O NUMERO DE MOVIMENTOS NA MATRIZ PADJ[i][j][duende], sendo i e j coordenadas do portal, e "duende" o identifier do duende
        for(auto &p:duendes){
            counterDuendes++;
            bfs(p.first, p.second, counterDuendes);
            if(!found){
                passPadj= false;
                break;
            }
        }
        //CASO UM DUENDE NAO TENHA NENHUMA ADJASCÊNCIA, PODEMOS ENCERRAR AQUI MESMO E IMPRIMIR -1, VERIFICAMOS ATRAVES DA BOOL passPadj
        if(!passPadj){
            cout << "-1\n";
            continue;
        }

        //USE FOR DEBUG
        /*for(auto &e:padj){
            cout << "Player of position " << e.first.first << " " << e.first.second << " adjs: \n";
            for(auto &s: e.second.adj) cout << "Im I of X: " << s.first.first << " Im J of X X: " << s.first.second << " weight: " << s.second << "\n";
            cout << "\n";
        }*/

        //AQUI FAREMOS UM BRUTE FORCE TESTANDO TODAS AS PERMUTAÇÕES POSSIVEIS DE SOLUÇÕES
        //PARA ISSO, PRECISAMOS ORDENAR O VECTOR PORTAIS, PARA QUE A FUNCAO next_permutation FUNCIONE ADEQUADAMENTE
        sort(portais.begin(), portais.end());
        do{
            solve(portais);
        }while(next_permutation(portais.begin(), portais.end()));
        sort(solves.begin(), solves.end());
        //ORDENAMOS O VETOR, E IMPRIMIMOS A SOLUÇÃO DE MENOR VALOR
        //CASO O TAMANHO DO VETOR SEJA 0, OU SEJA, NÃO HÁ SOLUÇÃO, IMPRIMIMOS -1
        cout << (solves.size() ? solves[0] : -1) << "\n";
    }
    return 0;
}