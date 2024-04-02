#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        vector<int> notas;
        int n; cin >> n;
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            notas.push_back(a);
        }
        int soma =0;
        for(int i=0; i<notas.size(); i++){
            soma += notas[i];
        }
        int media = soma/notas.size();
        double ac=0;
        for(int i=0; i<notas.size(); i++){
            if(notas[i]>media){
                ac++;
            }
        }
        double y = notas.size();
        double percentual = (ac*100)/y;
        cout << fixed << setprecision(3) << percentual << "%" << endl;
    }
    return 0;
}