/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1436
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int verificador = 1;
    vector<int> vec;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a;
        for(int j=0;j<a;j++){
            cin >> b;
            vec.push_back(b);
        }
        int q = (vec.size()/2);
        cout << "Case " << verificador << ": " << vec[q] << endl;
        verificador++;
        vec.clear();
    }
    return 0;
}
