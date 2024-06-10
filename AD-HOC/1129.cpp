/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1129
*/


#include <iostream>
#include <vector>

using namespace std;

int main(){
    while(true){
    int x;
    cin >> x;
    if(x==0)break;
    for(int i=0; i<x; i++){
        int numero, vapo=0;
        vector <int> num;
        for(int j=0; j<5; j++){
            int y;
            cin >> y;
            num.push_back(y);
        }
        for(int k=0; k<5; k++){
            if(num[k]<=127){
                numero = k;
                vapo +=1;
            }
        }
        if(vapo>1 || vapo==0){
            cout << "*" << endl;
        }
        if(vapo==1){
            if(numero==0){
                cout << "A" << endl;
            }
            if(numero==1){
                cout << "B" << endl;
            }
            if(numero==2){
                cout << "C" << endl;
            }
            if(numero==3){
                cout << "D" << endl;
            }
            if(numero==4){
                cout << "E" << endl;
            }
        }
    }
    }
    return 0;
}
