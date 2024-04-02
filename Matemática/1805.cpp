#include <iostream>

using namespace std;

unsigned long long int calc(unsigned long long int &a, unsigned long long int &b){
    return ((b-a+1)*(a+b))/2;
}

int main(){
    unsigned long long int a,b;
    cin >> a >> b;
    cout << calc(a,b) << "\n";
    return 0;
}