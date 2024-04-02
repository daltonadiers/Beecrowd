/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1533
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int a, k;
    while(true){
        vector<int> suspeitos;
        vector<int> sus;
        cin >> a;
        if(a==0){
            break;
        }
        else{
            for(int i=0; i<a; i++){
                cin >> k;
                sus.push_back(k);
            }
            suspeitos = sus;
            sort(sus.begin(), sus.end());
            int o = sus[a-2];
            for(int i=0; i<a; i++){
                if(o==suspeitos[i]){
                    cout << i+1 << endl;
                    i=a;
                }
            }
        }
        suspeitos.clear();
            sus.clear();
    }
  return 0;
}




