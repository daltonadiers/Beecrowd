#include <iostream>
#include <string>

using namespace std;

int myA[9], myB[9];
int counter =0;

void zerar(){
    for(int i=0; i<9;i++){
        myA[i]=0;myB[i]=0;
    }
}
void soma(){
    for(int i=8; i>=0;i--){
        if(myA[i]+myB[i]>=10){
            counter++;
            myA[i-1]++;
        }
    }
}

int main(){
    string a,b;
    while(cin >> a >> b){
        if(a=="0" && b=="0")break;
        counter =0;
        int tamA = (int)a.length();
        int tamB = (int)b.length();
        int indAtual=8;
        for(int i=tamA-1; i >= 0; i--){
            string auxA = a.substr(i,1);
            myA[indAtual] = stoi(auxA);
            indAtual--;    
        }
        indAtual=8;
        for(int i=tamB-1; i>=0; i--){
            string auxB = b.substr(i,1);
            myB[indAtual] = stoi(auxB);
            indAtual--;
        }
        soma();
        if(counter==0)cout << "No carry operation.\n";
        else if(counter==1){
            cout << "1 carry operation.\n";
        }else{
            cout << counter << " carry operations.\n";
        }
        zerar();
    }
    return 0;
}