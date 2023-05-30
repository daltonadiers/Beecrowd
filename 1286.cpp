//issue available at: https://www.beecrowd.com.br/judge/pt/problems/view/1286
//Solved by dadiers

#include <iostream>
#include <vector>
#include <algorithm>
#define MAXIMO 50
using namespace std;

struct motoboy{
    int tempo;
    int npizzas;
};

bool ordena(const motoboy& motoboy1, const motoboy& motoboy2){
    if(motoboy1.npizzas == motoboy2.npizzas){
        return motoboy1.tempo < motoboy2.tempo;
    }else{
        return motoboy1.npizzas < motoboy2.npizzas;
    }
}

int main(){
    int n;
    while(cin >> n){
        if(n==0)break;
        int max;
        cin >> max;
        int matriz[MAXIMO][MAXIMO];
        matriz[0][1] = 0;
        matriz[0][0] = 0;
        vector <motoboy> apoio;
        motoboy m;
        for(int u=0; u<n;u++){
            cin >> m.tempo >> m.npizzas;
            apoio.push_back(m);
        }
        sort(apoio.begin(), apoio.end(), ordena);
        for(int i=1; i<=apoio.size(); i++){
            matriz[i][0] = apoio[i-1].npizzas;
            matriz[i][1] = apoio[i-1].tempo;
        }
        apoio.clear();
        //CONSTRUCAO DA MATRIZ ---------------------------------//
        int matrizAns[MAXIMO][MAXIMO];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<max+1; j++){
                if(i==0 || j==0){
                    matrizAns[i][j] = 0;
                }
        //--------------------------------------------------//        
                else{
                    if(j<matriz[i][0]){                         
                        matrizAns[i][j] = matrizAns[i-1][j];    
                    }else{
                        int valor1;
                        valor1 = matriz[i][1];             
                        int aux = matriz[i][0];            
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
       cout << matrizAns[n][max] << " min." << endl;
    }
    return 0;
}
