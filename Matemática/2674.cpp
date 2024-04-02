#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;
#define MAX 112345

vector<int> primos;
set<int> primosSet;

void fillPrime(){
    primos.push_back(1);//primosSet.insert(1);
    primos.push_back(2);primosSet.insert(2);
    for(int i=3; i<MAX; i++){
        int mySize = (int)primos.size();
        bool primo=true;
        for(int j=1; j<mySize-1;j++){
            if(i%primos[j]==0){
                primo=false;break;
            }
        }
        if(primo){
            primos.push_back(i);
            primosSet.insert(i);
        }
    }
}
bool superPrime(int n){
    string x = to_string(n);
    int q = x.length();
    for(int i=0; i<q;i++){
        int a = stoi(string(1, x[i]));
        if(primosSet.count(a)==0)return false;
    }
    return true;
}


int main(){
    fillPrime();
    int n;
    while(cin >> n){
        if(primosSet.count(n)>0){
            if(superPrime(n))cout << "Super\n";
            else cout << "Primo\n";
        }else{
            cout << "Nada\n";
        }
    }
    return 0;
}