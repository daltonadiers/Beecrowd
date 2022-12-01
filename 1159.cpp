/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1159
*/
#include <iostream>
using namespace std;

int main(){
    while(true){
        int x, s;
        cin >> x ;
        if(x==0){
            break;
        }
        else{
        if(x%2!=0){
            x++;
        }
        s = x+(x+2)+(x+4)+(x+6)+(x+8);
        cout << s << endl;
    }
    }
    return 0;
}

