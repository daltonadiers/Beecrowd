#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, ncases=0; cin >> t;
    while(t--){
        ncases++;
        int np, dist;
        cin >> np >> dist;
        vector<int> volta;
        char inst, lixo, lastInst='B';
        int pedraDist, lastDist=0, maiorSalto=0;
        //LE E CALCULA A IDA JÁ NA ENTRADA
        //CRITERIO: SEMPRE PULAR NAS PEDRAS GRANDES, NÃO PULAR DUAS PEDRAS S EM SEQUENCIA
        //AS PEDRAS RESTANTES (GRANDES E AS PEQUENAS NAO UTILIZADAS), SAO JOGADAS NO VECTOR VOLTA
        for(int i=0; i<np; i++){
            cin >> inst >> lixo >> pedraDist;
            if(inst=='B'){
                if(pedraDist-lastDist>maiorSalto)maiorSalto=pedraDist-lastDist;
                lastDist=pedraDist;
                volta.push_back(pedraDist);
                lastInst='B';
            }else{
                if(lastInst=='S'){
                    lastInst='B';
                    volta.push_back(pedraDist);
                }else if(lastInst=='B'){
                    lastInst='S';
                    if(pedraDist-lastDist>maiorSalto)maiorSalto=pedraDist-lastDist;
                    lastDist=pedraDist;
                }
            }
        }
        if(lastDist<dist && dist-lastDist>maiorSalto)maiorSalto=dist-lastDist;
        if(!volta.empty() && dist-(int)volta[volta.size()-1]>maiorSalto)maiorSalto=dist-(int)volta[volta.size()-1];
        //CALCULAMOS A VOLTA
        for(int i=(int)volta.size()-1; i>0; i--){
            if(i-1 >= 0 && volta[i]-volta[i-1]>maiorSalto)maiorSalto=volta[i]-volta[i-1];
        }
        if(!volta.empty() && volta[0]>maiorSalto)maiorSalto=volta[0];
        if(volta.empty())maiorSalto=dist; //SE NAO HÁ PEDRA PARA A VOLTA, A DISTANCIA CERTAMENTE SERÁ O TAMANHO DO RIO
        cout << "Case " << ncases << ": " << maiorSalto << "\n";
    }
    return 0;
}