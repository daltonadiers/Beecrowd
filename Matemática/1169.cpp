/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1169
*/
#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
            for(int j=0; j<x; j++){
                int y;
                cin >> y;
                if(y == 64){
                    cout << "1537228672809129 kg" << endl;
                }
                else{
                unsigned long long q=1;
                for(int i=0; i<y; i++){q *= 2;}
                    q = ((q/12)/1000);
                    cout << q << " kg" << endl;
                }
    }
    return 0;
}