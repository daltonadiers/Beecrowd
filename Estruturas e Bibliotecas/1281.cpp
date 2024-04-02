/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1281
*/
#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        map<string, float> disp;
        map<string, int> comp;
        int d;
        cin >> d;
        for(int j=0; j<d; j++){
            string v;
            float a;
            cin >> v >> a;
            disp[v] = a;
        }
        int c;
        cin >> c;
        for(int o=0; o<c; o++){
            string v;
            int a;
            cin >> v >> a;
            comp[v] = a;
        }
        float sum = 0.0;
        for (auto const& [key, value] : disp) {
            auto it = disp.find(key);
            if (it != disp.end()) {
                auto it2 = comp.find(key);
                if (it2 != comp.end()) {
                    sum += value * it2->second;
                }
            }
        }
        cout << "R$ " << fixed << setprecision(2) << sum << endl;
    }
    return 0;
}
