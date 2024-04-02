/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1198
*/
#include <iostream>
using namespace std;

int main(){
        long long int x,y;
         while(cin >> x >> y){
            if(x==y){
                cout << 0 << endl;
            }
            else if(x>y){
                cout << x-y << endl;
            }
            else{
                cout << y-x << endl;
            }
         }
    return 0;
}