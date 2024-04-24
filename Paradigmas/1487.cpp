#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct capoio{
    int peso;
    int dano;
    capoio(int peso_, int dano_) : peso(peso_), dano(dano_){}
};

void printer(vector<vector<int>> &matrizAns, int a, int t){
    for(int i=0; i<a; i++){
            for(int j=0; j<t;j++){
                cout << matrizAns[i][j] << " "; 
            }
            cout << "\n";
    }
}

int main(){
    int n, t, cason=0;
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin >> n >> t && n && t){
        cason++;
        int d,p;
        vector<capoio> atracoes;
        for(int i=0; i<n;i++){
            cin >> d >> p;
            capoio c = capoio(d,p);
            atracoes.push_back(c);
            for(int j=0; j<t/d;j++)atracoes.push_back(c);
        }
        
       vector<vector<int>> matrizAns(atracoes.size() + 1, vector<int>(t + 1, 0));
       for(int i=0; i<(int)atracoes.size()+1; i++){
            for(int j=0; j<=t; j++){
                if(i==0 || j==0){
                    matrizAns[i][j] = 0;
                }
        //--------------------------------------------------//        
                else{
                    if(j<atracoes[i].peso){                         
                        matrizAns[i][j] = matrizAns[i-1][j];    
                    }else{
                        int valor1;
                        valor1 = atracoes[i].dano;             
                        int aux = atracoes[i].peso;            
                        if((j-aux)>0){ 
                            valor1+= matrizAns[i-1][j-aux];   
                        }
                        if(valor1>=matrizAns[i-1][j]){      
                            matrizAns[i][j] = valor1;
                        }else{                              
                            matrizAns[i][j]=matrizAns[i-1][j];
                        }
                    }
                }
            }
       } 
        //printer(matrizAns, atracoes.size()+1, t+1);  // FOR DEBUG
        cout << "Instancia " << cason << "\n" << matrizAns[atracoes.size()][t] << "\n\n";
    }
    return 0;
}