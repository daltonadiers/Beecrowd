/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1162
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int y;
    cin >> y;
    vector<int> vagoes;
    for(int i=0; i<y; i++){
        int x;
        cin >> x;
        for(int j=0; j<x; j++){
            int u;
            cin >> u;
            vagoes.push_back(u);
        }
        int verificador = 0;
         for (size_t i = 0; i < vagoes.size() - 1; ++i) {
            for (size_t j = 0; j < vagoes.size() - 1 - i; ++j) {
                if (vagoes[j] > vagoes[j + 1]) {
                    swap(vagoes[j], vagoes[j + 1]);
                    verificador++;
                    }
                }
            }
        cout << "Optimal train swapping takes " << verificador << " swaps." << endl;
            vagoes.clear();
    }
  return 0;
}
