/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1536
*/
#include <iostream>
using namespace std;
int main(){
    int x;
    cin >> x;
    for(int i=0; i<x; i++){
     int gd, inf, gf, ind;
      //para melhor entendimento, usei como orientação Grêmio e Inter, onde as variáveis gd e gf representam gremio dentro e gremio fora, inf e ind representam inter fora e dentro;
     char lixo;
     cin >> gd >> lixo >> inf;
     cin >> ind >> lixo >> gf;
     int gti, gtg;
     gti = inf+ind;
     gtg = gf+gd;
     if(gti>gtg){
        cout << "Time 2" << endl;
     }
     else if(gtg>gti){
        cout << "Time 1" << endl;
     }
     else if(gtg==gti){
        if(gf>inf){
            cout << "Time 1" << endl;
        }
        else if(inf>gf){
            cout << "Time 2" << endl;
        }
        else if(inf==gf){
            cout << "Penaltis" << endl;
        }
     }
    }
  return 0;
}


