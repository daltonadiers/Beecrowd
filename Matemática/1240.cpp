#include <iostream>
#include <string>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        if(a.length()>=b.length()){
            int c = a.length() - b.length();
            int d = b.length();
            string x = a.substr(c, d);
            if(x==b){
                cout << "encaixa" << endl;
            }else{
                cout << "nao encaixa" << endl;
            }
        }else{
            cout << "nao encaixa" << endl;
        }
    }
    return 0;
}