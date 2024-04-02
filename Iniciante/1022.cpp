/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1022
*/
#include <iostream>

using namespace std;

int mdc(int a, int b) {
  if (b == 0) {
    return a;
  }
  return mdc(b, a % b);
}

int main(){
    int x;
    cin >> x;
    cin.ignore();
    for(int w=0; w<x; w++){
        int a,b,c,d;
        char lixo, op;
        cin >> a >> lixo >> b >> op >> c >> lixo >> d;
        if(op=='+'){
            int l,j,k;
            l = a*d;
            j = c*b;
            k = b*d;
            int p = (l+j);
            cout << p << "/" << k << " = ";
            int s = mdc(p,k);
            cout << p/s << "/" << k/s << endl;
        }
        else if(op=='-'){
            int l,j,k;
            l = a*d;
            j = c*b;
            k = b*d;
            int p = (l-j);
            cout << p << "/" << k << " = ";
            int s = mdc(p,k);
            if(s<0){
                s=s*-1;
            }
            cout << p/s << "/" << k/s << endl;
        }
        else if(op=='*'){
            int l = a*c;
            int j = b*d;
            cout << l << "/" << j << " = ";
            int s = mdc(l,j);
            cout << l/s << "/" << j/s << endl;
        }
        else if(op=='/'){
            int l=a*d;
            int j=c*b;
            cout << l << "/" << j << " = ";
            int s = mdc(l,j);
            cout << l/s << "/" << j/s << endl;
        }
    }
  return 0;
}
