/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1120
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool all_zeros(const vector<int>& fim){
              for (const auto& x : fim) {
                if (x != 0) {
                  return false;
                }
              }
              return true;
            }

int main(){
    while(true){
        int x;
        string y;
        cin >> x >> y;
        vector<int> digits;
        vector<int> fim;
        if(x==0 && y=="0"){
            break;
        }
        else{
            for (char c : y) {
                digits.push_back(c - '0');
            }
            int k = digits.size();
            bool flag = false;
            for(int i=0; i<k; i++){
                if(digits[i]!=x){
                         fim.push_back(digits[i]);
                }
            }
                if(all_zeros(fim)){
                    cout << 0;
                }
                else{
                    int q = fim.size();
                    for(int i=0; i<q; i++){
                        if(fim[i]>0){
                            flag = true;
                        }
                        if(flag){
                            cout << fim[i];
                        }
                    }
                }
                cout << endl;
        }
        }

  return 0;
}
