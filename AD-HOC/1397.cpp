/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1397
*/

#include <iostream>

using namespace std;

int main(){
    int x;
    int p=0, s=0;
    while(true){
        cin >> x;
        if(x==0){
            break;
        }
        else{
            int j,k;
            for(int i=0; i<x; i++){
                cin >> j >> k;
            
            if(j>k){
                p+=1;
            }
            if(j<k){
                s+=1;
            }
            }
            cout << p << " " << s << endl;
            s = 0;
            p = 0;
        }

    }
    return 0;
}