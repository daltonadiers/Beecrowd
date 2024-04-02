/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/3209
*/
#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
    for(int i=0; i<x; i++){
        int k;
        int t = 0;
        cin >> k;
        for(int j=0; j<k; j++){
            int m;
            cin >> m;
            t+=m-1;
        }
        cout << t+1 << endl;
    }
    return 0;
}

