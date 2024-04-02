#include <iostream>

using namespace std;

int squares[101];

void fillSquare(){
    squares[0] = 0;
    for(int i=1; i<=100;i++){
        squares[i] = i*i+squares[i-1];
    }
}

int main(){
    fillSquare();
    int n;
    while(cin >> n && n){
        cout << squares[n] << "\n";
    }
    return 0;
}