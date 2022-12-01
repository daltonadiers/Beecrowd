/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1151
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> fibo;
    fibo.push_back(0);
    fibo.push_back(1);
    fibo.push_back(1);
    int x;
    cin >> x;
    for(int i=3; i<x; i++){
        int k;
        k = fibo[i-1] + fibo[i-2];
        fibo.push_back(k);
    }
    for(int l=0; l<x-1; l++){
        cout << fibo[l] << " ";
    }
    cout << fibo[x-1] << endl;
    return 0;
}

