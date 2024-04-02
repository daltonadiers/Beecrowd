#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define MAX 212

int l,h;
vector<vector<int>> ladrilhos1(MAX, vector<int>(MAX));
vector<vector<int>> ladrilhos2(MAX, vector<int>(MAX));
vector<vector<int>> ladrilhos3(MAX, vector<int>(MAX));
set<pair<int,int>> visited1; set<pair<int,int>> visited2; set<pair<int,int>> visited3;
int minimumReached = 1123456789;
int minimumActual=0;

void dfs(int i, int j, vector<vector<int>>& m, int verificador){
    switch(verificador){
        case 1:
            if(visited1.count(make_pair(i,j))>0)return;
            visited1.insert(make_pair(i,j));
        break;
        case 2:
            if(visited2.count(make_pair(i,j))>0)return;
            visited2.insert(make_pair(i,j));
        break;
        case 3:
            if(visited3.count(make_pair(i,j))>0)return;
            visited3.insert(make_pair(i,j));
        break;
    }
    minimumActual++;
    if(i+1<l && m[i+1][j]==m[i][j])dfs(i+1,j,m,verificador);
    if(i-1>=0 && m[i-1][j]==m[i][j])dfs(i-1,j,m,verificador);
    if(j+1<h && m[i][j+1]==m[i][j])dfs(i,j+1,m,verificador);
    if(j-1>=0 && m[i][j-1]==m[i][j])dfs(i,j-1,m,verificador);
}   

void trataMatrizes(){
    for(int i=0; i<l;i++)for(int j=0;j<h;j++){
        if(ladrilhos1[i][j]==0)ladrilhos1[i][j]=1;
        if(ladrilhos2[i][j]==0)ladrilhos2[i][j]=2;
        if(ladrilhos3[i][j]==0)ladrilhos3[i][j]=3;
    }
}


int main(){
    cin >> l >> h;
    for(int i=0; i<l;i++)for(int j=0;j<h;j++){
        cin >> ladrilhos1[i][j]; ladrilhos2[i][j]=ladrilhos3[i][j]=ladrilhos1[i][j];
    }
    trataMatrizes();
    for(int i=0; i<l;i++)for(int j=0;j<h;j++){
        minimumActual=0;
        if(visited1.count(make_pair(i,j))==0)dfs(i,j, ladrilhos1,1);
        if(minimumActual<minimumReached && minimumActual)minimumReached=minimumActual;
        minimumActual=0;
        if(visited2.count(make_pair(i,j))==0)dfs(i,j, ladrilhos2,2);
        if(minimumActual<minimumReached && minimumActual)minimumReached=minimumActual;
        minimumActual=0;
        if(visited3.count(make_pair(i,j))==0)dfs(i,j, ladrilhos3,3);
        if(minimumActual<minimumReached && minimumActual)minimumReached=minimumActual;
    }
    cout << minimumReached << endl;
    return 0;
}