/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1221
*/
#include <iostream>
#include <math.h>

using namespace std;

bool isprime(int n){
    if(n==1 || n==0){
        return false;
}
    else{
        int j = sqrt(n)+1;
        for(int i=j; i>1; i-- ){
            if(i==n){
                continue;
            }
            else if(n%i==0){
                return false;
            }
        }
        return true;
    }
}

int main(){
        int x;
        cin >> x;
        for(int i=0; i<x; i++){
            int r;
            cin >> r;
            if(isprime(r)){
                cout << "Prime" << endl;
            }
            else{
                cout << "Not Prime" << endl;
            }
        }
    return 0;
}
