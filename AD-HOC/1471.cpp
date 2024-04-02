/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1471
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int a,b;
    vector<int> inteiros;
    vector<int> sobreviventes;
    vector<int> mortos;
    while(cin >> a >> b){
        for(int i=1; i<=a; i++){
            inteiros.push_back(i);
        }
        for(int i=0; i<b; i++){
            int j;
            cin >> j;
            sobreviventes.push_back(j);
        }
        if(a==b){
        cout << "*" << endl;
    }
        else{
        for(int i=0; i<a; i++){
        if (find(sobreviventes.begin(), sobreviventes.end(), inteiros[i]) != sobreviventes.end()) {
        continue;
        }
        else{
            mortos.push_back(inteiros[i]);
        }
        }
        int w = mortos.size();
        for(int i=0; i<w; i++){
            if(i==w-1){
            cout << mortos[i] << " " << endl;
            }
            else{
               cout << mortos[i] << " ";
            }
        }
    }
        sobreviventes.clear();
        mortos.clear();
        inteiros.clear();
    }
  return 0;
}
