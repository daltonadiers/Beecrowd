#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct auxiliando{
    int caracteres;
    int pedidos;
};

bool comparador(const auxiliando& a, const auxiliando& b) {
    if(a.caracteres != b.caracteres) return a.caracteres < b.caracteres;
    return a.pedidos < b.pedidos;
}

int main(){
    int captotal, nfrases;
    int teste =1;
    while(true){
       cin >> captotal >> nfrases; 
       vector<auxiliando> apoio;
       if(captotal == 0 && nfrases == 0)break;
       auxiliando abc;
       abc.caracteres = 0;
       abc.pedidos = 0;
       apoio.push_back(abc);
       for(int i=0; i<nfrases; i++){
            cin >> abc.caracteres >> abc.pedidos;
            apoio.push_back(abc);
       }
       sort(apoio.begin(), apoio.end(), comparador);
        int ans[nfrases+1][captotal+1];
        for(int i=0; i<nfrases+1; i++){
                for(int j=0; j<captotal+1; j++){
                    if(i==0 || j==0){
                        ans[i][j]=0;
                    }
                    else{
                        if(j<apoio[i].caracteres){
                            ans[i][j] = ans[i-1][j];
                        }else{
                        int valor1;
                        valor1 = apoio[i].pedidos;
                        int aux = apoio[i].caracteres;
                        if((j-aux)>0){ 
                            valor1+= ans[i-1][j-aux];
                        }
                        if(valor1>=ans[i-1][j]){
                            ans[i][j] = valor1;    
                        }else{
                            ans[i][j]=ans[i-1][j];
                        }
                    }
                    }
                }
            }
            cout << "Teste " << teste << endl;
            cout << ans[nfrases][captotal] << endl;
            cout << endl;
            teste++;     
    }
    return 0;
}