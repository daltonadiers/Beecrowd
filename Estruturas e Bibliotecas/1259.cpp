/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1259
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int x;
    cin >> x;
    vector<int> pares;
    vector<int> impares;
    for(int i=0; i<x; i++){
        int a;
        cin >> a;
        if(a%2==0){
            pares.push_back(a);
        }
        else{
            impares.push_back(a);
        }
    }
        sort(pares.begin(), pares.end());
        sort(impares.begin(), impares.end());
        int q = pares.size();
        int w = impares.size();
        for(int i=0; i<q; i++){
            cout << pares[i] << endl;
        }
        for(int i=w-1; i>=0; i--){
            cout << impares[i] << endl;
        }
    return 0;
}
