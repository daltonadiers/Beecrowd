/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1110
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    while(true){
        int y;
        cin >> y;
        vector<int> pilha;
        vector<int> discard;
        if(y==0){
            break;
        }
        else{
            for(int i=y; i>0; i--){
                pilha.push_back(i);
            }
                while(pilha.size()>=2){
                    discard.push_back(pilha.back());
                    pilha.pop_back();
                    int last_element = pilha.back();
                    pilha.pop_back();
                    pilha.insert(pilha.begin(), last_element);
            }
            int o = discard.size();
            cout << "Discarded cards: ";
            for(int i=0; i<o-1; i++){
                cout << discard[i] << ", ";
            }
            cout << discard[o-1] << endl;
            cout << "Remaining card: " << pilha[0] << endl;
        }
    }
  return 0;
}
