/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1410
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int a,d;
    while(true){
        vector<int> def;
        vector<int> atk;
        cin >> a >> d;
        if(a==0 && d==0){
            break;
        }
        else{
         for(int i=0; i<a; i++){
            int j;
            cin >> j;
            atk.push_back(j);
         }
         for(int i=0; i<d; i++){
            int k;
            cin >> k;
            def.push_back(k);
         }
         sort(atk.begin(), atk.end());
         sort(def.begin(), def.end());
         int p,e;
         p = atk[0];
         e = def[1];
         if(p>=e){
            cout << "N" << endl;
         }
         else{
            cout << "Y" << endl;
         }
        }
    }
  return 0;
}
