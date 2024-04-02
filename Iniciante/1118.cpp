/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1118
*/
#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    int t=2;
    while(t){
        float n1, n2;
        for(int i=0; i<1;){
            cin >> n1;
            if(n1<=10 && n1>=0){
                i++;
            }
            else{
                cout << "nota invalida" << endl;
            }
        }
        for(int j=0; j<1;){
            cin >> n2;
            if(n2<=10 && n2>=0){
                j++;
            }
            else{
                cout << "nota invalida" << endl;
            }
        }
        float m=(n1+n2)/2;
        cout << "media = " << fixed << setprecision(2) << m << endl;
        for(int u=0; u<1;){
        cout << "novo calculo (1-sim 2-nao)" << endl;
        int s;
        cin >> s;
        if(s==2){
            u++;
            t=0;
        }
        if(s==1){
            u++;
        }
        else{
            continue;
        }
        }
    }
    return 0;
}
