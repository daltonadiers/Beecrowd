/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1068
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool testador(string e){
    bool flag=false;
    int q = e.size();
    for(int i=0; i<q; i++){
        if(e[i]==41 && flag==false){
            return false;
        }
        else if(e[i]==40){
            return true;
        }
    }
}

bool testa(string w){
    if(testador(w)==false){
        return false;
    }
    else{
        int q = w.size();
        int verificador =0;
        for(int i=0; i<q; i++){
            if(w[i]==40){
                for(int j=i; j<q; j++){
                    if(w[j]==41){
                        verificador++;
                    }
                }
                if(verificador==0){
                return false;
            }
            else{
                verificador =0;
            }
            }
        }
        return true;
    }
}

int main(){
    string expressao;
    while(getline(cin, expressao)){
        int q = expressao.size();
        int verificador1 = 0;
        int verificador2 = 0;
        for(int i=0; i<q; i++){
            if(expressao[i]==40){
                verificador1++;
            }
            else if(expressao[i]==41){
                verificador2++;
            }
        }
        if(testa(expressao)){
            if(verificador1==verificador2){
                cout << "correct" << endl;
            }
            else{
                cout << "incorrect" << endl;
            }
        }
        else{
            cout << "incorrect" << endl;
        }
    }
  return 0;
}
