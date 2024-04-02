/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1250
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int x;
    cin >> x;
    for(int h=0; h<x; h++){
      vector <int> alturas;
      vector <char> pulos;
      int counter = 0;
      int qt;
      cin >> qt;
      for(int i=0; i<qt; i++){
        int b;
        cin >> b;
        alturas.push_back(b);
      }
      for(int i=0; i<qt; i++){
        char a;
        cin >> a;
        pulos.push_back(a);
      }
      for (int i = 0; i < qt; ++i){
   if((alturas[i] == 1 || alturas[i] == 2) && pulos[i] == 'S')
    counter++;
   if(alturas[i] > 2 && pulos[i] == 'J')
    counter++;
  }
   cout << counter << endl;
    }
    return 0;
}
