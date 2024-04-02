#include <iostream>
#include <string>
#include <queue>
using namespace std;

char tratado[16];

void trataCentavos(const string& cents){
    if(cents.length()==2){
        tratado[15]=cents[1]; tratado[14]=cents[0];
    }else{
        tratado[15]=cents[0]; tratado[14]='0';
    }
}
void insereVirgulas(){
    tratado[13]='.';
    tratado[9]=',';
    tratado[5]=',';
    tratado[1]=',';
}
void fillArray(){
    for(int i=0;i<16;i++)tratado[i]='-';
}
void trataDinheiro(const string& din){
    queue<char> fila;
    for(int i=(int)din.size()-1;i>=0;i--){
        fila.push(din[i]);
    }
    int i=12;
    while(!fila.empty()){
        if(i==9 || i==5 || i==1)i--;
        else{
            char c = fila.front(); fila.pop();
            tratado[i]=c;
            i--;
        }
    }
}
void printer(){
    bool first = true;
    cout << "$";
    for(int i=0; i<16; i++){
        if(first){
            if(tratado[i]!='-' && tratado[i]!=','){
                cout << tratado[i];
                first=false;
            }
        }else{
            cout << tratado[i];
        }
    }
    cout << "\n";
}

int main(){
    string dinheiro, centavos;
    while(cin >> dinheiro >> centavos){
        fillArray();
        trataCentavos(centavos);
        insereVirgulas();
        trataDinheiro(dinheiro);
        printer();
    }
    return 0;
}