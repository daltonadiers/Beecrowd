/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1235
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    int x;
    cin >> x;
    cin.ignore();
    for(int p=0; p<x; p++){
        string principal;
        getline(cin, principal);
        string corrigida;
        int q = principal.size();
        int r = (q/2)-1;
        for(int i=r; i>=0; i--){
            corrigida.push_back(principal[i]);
        }
        for(int i=q; i>r; i--){
            corrigida.push_back(principal[i]);
        }
        int pos = q/2;
        corrigida.erase(pos, 1);
        cout << corrigida << endl;
        principal.clear();
        corrigida.clear();
    }
  return 0;
}
