/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1329
*/


#include <iostream>
#include <vector>

using namespace std;

int main(){
    int x;
    vector <int> moeda;
    int mary=0,john=0;
    while(true){
    cin >> x;
    if(x==0){
        break;
    }
    else{
    for(int i=0; i<x; i++){
        int y;
        cin >>y;
        moeda.push_back(y);
    }
    for(int k=0; k<x; k++){
        if(moeda[k]==0){
            mary += 1;
        }
        if(moeda[k]==1){
            john +=1;
        }
    }
    cout << "Mary won " << mary << " times and John won " << john << " times" << endl;
    mary = 0;
    john = 0;
    moeda.clear();
    }
    }
    return 0;
}

