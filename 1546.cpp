/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1546
*/
#include <iostream>
using namespace std;
int main(){
    int u;
    cin >> u;
    for(int i=0; i<u; i++){
        int l;
        cin >> l;
        for(int j=0; j<l; j++){
            int r;
            cin >> r;
            if(r==1){
                cout << "Rolien" << endl;
            }
            else if(r==2){
                cout << "Naej" << endl;
            }
            else if(r==3){
                cout << "Elehcim" << endl;
            }
            else if(r==4){
                cout << "Odranoel" << endl;
            }
        }
    }
  return 0;
}
