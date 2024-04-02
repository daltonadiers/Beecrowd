//issue available at: https://www.beecrowd.com.br/judge/pt/problems/view/1288
//Solved by dadiers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct capoio{
    int peso;
    int dano;
};

bool ordena(const capoio& capoio1, const capoio& capoio2){
    if(capoio1.peso==capoio2.peso){
        return capoio1.dano < capoio2.dano;
    }else{
        return capoio1.peso < capoio2.peso;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int y;
        cin >> y;
        //balas de canhao
        int matriz[y+1][2];
        matriz[0][1] = 0;
        matriz[0][0] = 0;
        vector <capoio> apoio2;
        capoio c;
        for(int u=1; u<=y;u++){
            // "Leia o dano e o peso indice: " << u << endl;
            cin >> c.dano >> c.peso;
            apoio2.push_back(c);
        }
        sort(apoio2.begin(), apoio2.end(), ordena);
        for(int i=1; i<=apoio2.size(); i++){
            matriz[i][0] = apoio2[i-1].peso;
            matriz[i][1] = apoio2[i-1].dano;
        }
        apoio2.clear();
        //---------------------------------------------------//
        //"Leia a capacidade do canhão: ";
        int cpcd;
        cin >> cpcd;
        // "Leia a resistencia do castelo: ";
        int resistencia;
        cin >> resistencia;
       //----------------------------------------------------//
       int matrizAns[y+1][cpcd+1];
       for(int i=0; i<y+1; i++){
            for(int j=0; j<cpcd+1; j++){
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
    if(matrizAns[y][cpcd]>=resistencia){
        cout << "Missao completada com sucesso" << endl;
    }else{
        cout << "Falha na missao" << endl;
    }
    }
}
