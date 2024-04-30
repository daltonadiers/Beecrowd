#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool order(const int &a, const int &b){
    return b < a;
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, sum;
    while(cin >> n >> k){
        vector<int> arr(n);
        vector<int> aux(n);
        aux[0] = 0;
        arr[0] = 0;
        for(int i = 1; i < n; i++){
            cin >> aux[i];
            arr[i] = aux[i] - aux[i - 1];
        }
        sort(arr.begin(), arr.end(), order);
        //for(auto &e: arr)cout << e << " ";
        sum = 0;
        for(int i = k - 1; i < n; i++){
            sum += arr[i];
        }
        cout << sum << "\n";
    }
    return 0;
}
