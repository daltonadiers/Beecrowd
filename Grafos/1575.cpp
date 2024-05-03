#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;
typedef pair<int,int> pii;
#define MAX 1000001

vector<pii> adjLepo;
vector<pii> adjGio;

struct forBfs{
    int i,j;
    vector<pii> path;
    forBfs(int i_, int j_) : i(i_), j(j_), path(vector<pii> ()){}
    forBfs(int i_, int j_, vector<pii> path_, pii n_) : i(i_), j(j_), path(path_){
        path.push_back(n_);
    }
};
int moveX[]={0,0,1,-1};
int moveY[]={1,-1,0,0};

void bfs(const pii &origem, const pii &dest, vector<pii> &path){
    //vector<vector<bool>> visited(MAX, vector<bool>(MAX, false)); // VECTOR[MAX][MAX] É GRANDE DEMAIS PARA SER ALOCADO, UTILIZAMOS SET NO LUGAR
    set<pair<int,int>> visited;
    visited.insert({origem.first, origem.second});
    queue<forBfs> q;
    q.push(forBfs(origem.first, origem.second));
    while(!q.empty()){
        forBfs top = q.front();
        q.pop();
        if(top.i == dest.first && top.j == dest.second){
            for(auto &e:top.path)path.push_back(e);
            break;
        }
        //CONSTRUCAO DE ADJASCENCIAS PARA A FILA
        for(int i=0; i<4; i++){
            if(top.i == dest.first && (i==2 || i==3))continue; //SE JA ESTAMOS NA LINHA CERTA, NAO PRECISAMOS TESTAR A TROCA DE LINHA
            if(top.j == dest.second && (i==0 || i==1))continue; //SE JA ESTAMOS NA COLUNA CERTA, NAO PRECISAMOS TESTAR A TROCA DE COLUNA
            int auxI = top.i + moveX[i];
            int auxJ = top.j + moveY[i];
            if(abs(auxI-dest.first)>abs(top.i-dest.first))continue; //SE A TROCA DE LINHA NOS DISTANCIA DA LINHA FINAL, PODEMOS DESCARTÁ-LA
            if(abs(auxJ-dest.second)>abs(top.j-dest.second))continue; //SE A TROCA DE COLUNA NOS DISTANCIA DA COLUNA FINAL, PODEMOS DESCARTÁ-LA
            if(auxI >=0 && auxJ>=0 && auxI<MAX && auxJ <MAX && !visited.count({auxI,auxJ})){
                q.push(forBfs(auxI, auxJ, top.path, {auxI,auxJ}));
                visited.insert({auxI,auxJ});
            }
        }
    }
}


int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    bool first = true;
    while(t--){
        if(!first)cout << "\n";
        else first=false;
        adjLepo.clear();
        adjGio.clear();
        int posI, posJ;
        cin >> posI >> posJ;
        adjGio.push_back({posI,posJ});  //CASA DE INICIO GIOVANNI
        cin >> posI >> posJ;
        adjLepo.push_back({posI,posJ});  //CASA DE INICIO LEPORELLO
        int paradas; cin >> paradas;
        int linha, coluna;
        for(int i=0; i<paradas;i++){    //PATH LEPORELLO
            cin >> linha >> coluna;
            bfs(adjLepo.back(), {linha,coluna}, adjLepo);
        }
        cin >> paradas;
        for(int i=0; i<paradas;i++){    //PATH GIOVANI
            cin >> linha >> coluna;
            bfs(adjGio.back(), {linha,coluna}, adjGio);
        }

        //FOR DEBUG
        /*cout << "EU SOU LEPORELLO: \n";
        for(auto &e:adjLepo)cout << e.first << " " << e.second << "\n";
        cout << "\n";
        cout << "EU SOU GIOVANNI: \n";
        for(auto &e:adjGio)cout << e.first << " " << e.second << "\n";
        cout << "\n";*/


        int indice = min((int)adjGio.size(), (int)adjLepo.size());
        bool ans =true;
        for(int i=0; i<indice; i++){
            if(i==(int)adjLepo.size()-1)break;
            if(adjGio[i]==adjLepo[i]){   //CASO ELES ESTIVERAM PRESENTES NA MESMA ESQUINA AO MESMO TEMPO
                ans=false;
                //cout << "NOS ENCONTRAMOS NA CASA: " << adjGio[i].first << " " << adjGio[i].second << "\n";
                break;
            }
        }
        cout << (ans ? "Yes" : "No") << "\n";
    }
    return 0;
}