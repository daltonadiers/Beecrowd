/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1210
*/
#include <iostream>
#include <cstring>

#define MAX 2123
#define INF 112345678

using namespace std;

int n,m,p;
int c[MAX], v[MAX];
int memo[MAX][MAX];
int nxt[MAX][MAX];

int dp(int t, int age){
    int ch1, ch2=INF;
    if(t==n+1)return 0;
    if(memo[t][age]!=-1)return memo[t][age];
    ch1= c[0]+p-v[age]+dp(t+1,1);
    if(age<m)ch2=c[age]+dp(t+1,age+1);
    nxt[t][age]= ch1<=ch2 ? 1: age+1;
    return memo[t][age] = min(ch1,ch2);
}



int main(){
    int init, i,t,age,first;
    while(cin >> n >> init >> m >> p){
        for(i=0; i<=m-1; i++)cin >> c[i];
        for(i=1; i<=m;i++)cin >> v[i];
        memset(memo, -1, sizeof(memo));
        cout << dp(1,init) << "\n";
        t=1;age=init;first=1;
        do{
            if(nxt[t][age]==1){
                if(!first)cout << " ";
                cout << t;
                first=0;
            }
            age = nxt[t++][age];
        }while(t<=n);
        if(first)cout << "0\n";
        else cout << "\n";
    }
    return 0;
}