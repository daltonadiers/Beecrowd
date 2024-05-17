#include <iostream>

using namespace std;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int trilha[100001],t;
    int n,q,m,op,l,r,c;
    cin >> n >> q >> m;
    for(int i=1;i<=n; i++){
        cin >> t;
        trilha[i] = 1LL << t;
    }
    for(int i=0; i<q; i++){
        cin >> op;
        if(op==1){
            cin >> l >> r;
            long long int distincts =0;
            for(int j=l; j<=r; j++){
                distincts |= trilha[j];
            }
            cout << __builtin_popcountll(distincts) << "\n";
        }else if(op==2){
            cin >> c >> t;
            trilha[c] = 1LL << t;
        }
    }
    return 0;
}
/*
    Para entender o código:
    1LL é a mesma coisa que long long = 1, mas o que nos interessa é sua cadeia binária, de 64 bits
    000000000[...]00001
    Considere [...] = número de 0s faltantes para completar 64 bits
    Para cada T que lemos (monstro), guardamos em trilha[i], 1LL << T, que significa 1LL com os bits
    deslocados T posições à esquerda.
    Por exemplo, 1LL << 2 é igual a:
    00000000[...]00100
    Sendo assim, para cada consulta de L até R, faremos um OR em todos esses números armazenados em trilha[], de L até R,
    ou seja, para cada bit ligado em quaisquer das cadeias binárias, ele será mantido na cadeia final
    em exemplo:
    1010
OR  0011
=   1011
    Utilizando dessa estratégia, basta contar quantos bits estão ligados na cadeia final, e assim saberemos
    quantos números diferentes possuímos neste intervalo.
*/