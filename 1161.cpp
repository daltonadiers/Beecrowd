/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1161
*/
#include <iostream>

using namespace std;

int main(){
    long long int a,b;
    while(cin >> a >> b){
        long long int c=1,d=1,e;
        for(int i=2; i<=a; i++){
            c *= i;
        }
        for(int i=2; i<=b; i++){
            d *= i;
        }
        e = c+d;
        cout << e << endl;
    }
    return 0;
}
