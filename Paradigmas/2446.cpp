#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int valor, nmoedas1;
    int temp;
    bool flag = false;
    vector <int> moedas;
    moedas.push_back(0);
    cin >> valor >> nmoedas1;
    for(int i=0; i<nmoedas1; i++){
        cin >> temp;
        if(temp<valor){
            moedas.push_back(temp);
        }
        if(temp==valor){
            flag = true;
        }
    }
    if(flag){
        cout << "S" << endl;
    }else{
        int nmoedas = moedas.size();
        sort(moedas.begin(), moedas.end());
        //CONSTRUÇÃO DA MATRIZ//
        vector<vector<int>> matrizAns(2, vector<int>(valor+1, 0));
        //PREENCHIMENTO
        for(int i=0; i<nmoedas+1; i++){
            for(int j=0; j<valor+1; j++){
                if(j==0){
                    matrizAns[1][j]=0;
                }else{
                    if(j<moedas[i]){
                        matrizAns[1][j] = matrizAns[0][j];
                    }else if(moedas[i]==j){
                        if(moedas[i]>matrizAns[0][j]){
                            matrizAns[1][j]=moedas[i];
                        }else{
                            matrizAns[1][j]=matrizAns[0][j];
                        }
                    }else if(j>moedas[i]){
                        int col = j-moedas[i];
                        int aux = moedas[i]+matrizAns[0][col];
                        if(aux>matrizAns[0][j]){
                            matrizAns[1][j]=aux;
                        }else{
                            matrizAns[1][j]=matrizAns[0][j];
                        }
                    }
                }
            }
            swap(matrizAns[0], matrizAns[1]);
            matrizAns[1] = vector<int>(matrizAns[1].size(), 0);
        }
        if(matrizAns[0][valor]==valor){
            cout << "S" << endl;
        }else{
            cout << "N" << endl;
        }
    }
    return 0;
}