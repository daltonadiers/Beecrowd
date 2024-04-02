#include <iostream>

using namespace std;

int global =0;

int fibonacci(int a){
    if(a==0)return 0;
    if(a==1)return 1;
    global+=2;
    return fibonacci(a-1) + fibonacci(a-2);
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        int j = fibonacci(t);
        cout << "fib(" << t << ") = " << global << " calls = " << j << endl;
        global =0;
    }
    return 0;
}