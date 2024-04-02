/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/2862
*/
#include <iostream>
#include <string>

using namespace std;

int main(){
    int x;
    cin >> x;
    for(int i=0; i<x; i++){
        int j;
        cin >> j;
        if(j>8000){
            cout << "Mais de 8000!" << endl;
        }
        else{
            cout << "Inseto!" << endl;
        }
    }
    return 0;
}

