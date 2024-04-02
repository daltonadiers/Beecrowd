#include <iostream>

using namespace std;
#define MAX 110

int v,e;

double max(double a, double b){
    return a>b ? a : b;
}

int main(){
    //ios_base::sync_with_stdio(false);
    int i,j,k;
    while(cin >> v && v){
        cin >> e;
        double prob[MAX][MAX] = {{0}};
        while(e--){
            cin >> i >> j >> k;
            prob[i][j]=prob[j][i]=k*0.01;
        }
        for(i=1; i<=v; ++i)for(j=1; j<v; ++j)for(k=1; k<=v; ++k)prob[j][k]=max(prob[j][k], prob[j][i]*prob[i][k]); 
        printf("%.6f percent\n",prob[1][v]*100); 
    }
    return 0;
}