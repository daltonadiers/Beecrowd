#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct canos{
    int comprimento;
    int valor;
};

bool comparar(const canos& c1, const canos& c2){
    if(c1.comprimento!=c2.comprimento){
        return c1.comprimento < c2.comprimento;
    }else{
        return c1.valor < c2.valor;
    }
}

int main(){
    vector <canos> vec;
    canos c; c.comprimento=0;c.valor=0;
    vec.push_back(c);
    int n,t; cin >> n >> t;
    for(int i=0; i<n; i++){
        cin >> c.comprimento >> c.valor;
        int a = t/c.comprimento;
        for(int j=0; j<a; j++){
            vec.push_back(c);
        }
    }
    sort(vec.begin(), vec.end(), comparar);
    int o = vec.size();
    vector<vector<int>> matriz(o, vector<int>(t + 1));
    for(int i=0; i<o; i++){
        for(int j=0; j<t+1; j++){
            if(i==0 || j==0){
                matriz[i][j]=0;
            }
            else{
                if(j<vec[i].comprimento){
                    matriz[i][j] = matriz[i-1][j];
                }else{
                    int valor1;
                    valor1 = vec[i].valor;
                    int aux = vec[i].comprimento;
                if((j-aux)>0){
                    valor1+= matriz[i-1][j-aux];
                }
                if(valor1>=matriz[i-1][j]){
                    matriz[i][j] = valor1;
                    
                }else{
                    matriz[i][j]=matriz[i-1][j];
                }
            }
            }
        }
    }
    cout << matriz[o-1][t] << endl;
    return 0;
}