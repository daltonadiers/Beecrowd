#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> t1;
    vector<int> t2;
    for(int i=0; i<t;i++){
        int a; cin >> a;
        t1.push_back(a);
    }
    for(int i=0; i<t;i++){
        int a; cin >> a;
        t2.push_back(a);
    }
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    int counter=0;
        for(int i=t-1; i>=0;){
            bool encontrou = false;
            bool parar = false;
            for(int j=t-1; j>=0;){
                if(i<0)break;
                if(t2[i]>t1[j]){
                    encontrou = true;
                    counter++;
                    i--;
                    if(j<=0) parar = true;
                    j--;
                }else{
                    j--;
                }
            }
            if(parar)break;
            if(!encontrou)break;
        }
        cout << counter << endl;
    return 0;
}