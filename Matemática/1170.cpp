/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1170
*/
#include <iostream>

using namespace std;

int main(){
    int x, verificador;
    float comida;
    cin >> x;
    for(int i=0; i<x; i++){
        verificador=0;
        cin >> comida;
        while(comida>1){
            verificador++;
            comida = comida/2;
        }
        cout << verificador << " dias" << endl;
    }
    return 0;
}