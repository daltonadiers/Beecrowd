/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1387
*/
#include <iostream>


using namespace std;

int main(){
    int x,y;
    while(true){
        cin >> x >> y;
        if(x==0 && y==0){
            break;
        }
        else{
            cout << x+y << endl;
            x =0;
            y=0;
        }
    }
    return 0;
}

