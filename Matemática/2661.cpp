#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll n;
vi p;

void sieve(){
    p.push_back(2);
    int m = sqrt(n);
    for(int i=3; i<=m;i++){
        int flag =0, r = sqrt(i);
        for(int j=0; j<(int)p.size() && p[j]<=r && flag; j++){
            flag |= (i%p[j]==0);
        }
        if(!flag)p.push_back(i);
    }
}
int fact(){
    int ans=0;
    for(int i=0;i<(int)p.size() && n>1;i++){
        if(n%p[i]==0){
            ans++;
            n/=p[i];
            while(n%p[i]==0)n/=p[i];
        }
    }
    return ans + (n>1);
}

int main(){
    int k;
    cin >> n;
    if(n==1)cout << "0\n";
    else{
        sieve();
        k=fact();
        cout << (1ll <<k)-1-k << "\n";
    }
    return 0;
}