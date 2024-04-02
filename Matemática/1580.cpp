#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define MAX 1123
#define P 1000000007
typedef long long ll;

ll expbin(int a, int e){
    if(e==0)return 1;
    if(e & 1) return (a*expbin(a, e-1))%P;
    ll b= expbin(a, e/2);
    return (b*b)%P;
}

int main(){
    string x;
    ll fact[MAX],numerador, denominador;
    int freq[26];
    fact[0]=1;
    for(int i=1; i<MAX; i++)fact[i]=(fact[i-1]*i)%P;
    while(cin >> x){
        int n = x.length();
        memset(freq,0,sizeof(freq));
        for(int i=0; i<n;i++)freq[x[i]-'A']++;
        numerador=fact[n]; denominador=1;
        for(int i=0; i<26; i++){
            denominador*=fact[freq[i]];
            denominador%=P;
        }
        denominador = expbin(denominador, P-2);
        ll ans = (numerador*denominador)%P;
        cout << ans << "\n";
    }
    return 0;
}