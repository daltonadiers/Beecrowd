#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct vaga{
    int inicio, fim, tamanho;
    bool busy;
    vaga(int inicio_, int fim_, bool busy_) : inicio(inicio_), fim(fim_), tamanho(fim_-inicio_+1), busy(busy_){}
};
vector<vaga> vagas;
unordered_map<int,int> estacionouonde;

int buscaVaga(int placa, int comprimento){
    bool found = false;
    for(int i=0; i<(int)vagas.size(); i++){
        if(!vagas[i].busy && comprimento<=vagas[i].tamanho){
            found = true;
            if(comprimento==vagas[i].tamanho){
                vagas[i].busy=true;
                estacionouonde[placa]=vagas[i].inicio;
                //cout << "chegou e estacionou em: " << vagas[i].inicio << " ate " << vagas[i].fim << "\n";
            }else{
                int fim = vagas[i].fim;
                vagas[i].fim=vagas[i].inicio+comprimento-1;
                vagas[i].busy=true;
                vagas[i].tamanho = vagas[i].fim - vagas[i].inicio + 1;  
                estacionouonde[placa]=vagas[i].inicio;
                //cout << "chegou e estacionou em: " << vagas[i].inicio << " ate " << vagas[i].fim << "\n";
                vagas.insert(vagas.begin()+i+1, vaga(vagas[i].fim+1,fim,false));
            }
            break;
        }
    }
    if(found)return 10;
    return 0;
}

void liberaVaga(int placa){
    int inicio = estacionouonde[placa];
    int indice=0;
    for(int i=0; i<(int)vagas.size(); i++){
        if(vagas[i].inicio==inicio)indice=i;
    }
    vagas[indice].busy=false;
    if(indice<(int)vagas.size()-1 && !vagas[indice+1].busy){
        vagas[indice].fim = vagas[indice+1].fim;
        vagas[indice].tamanho = vagas[indice].fim - vagas[indice].inicio + 1;  
        vagas.erase(vagas.begin()+indice+1);
    }
    if(indice && !vagas[indice-1].busy){
        vagas[indice-1].fim = vagas[indice].fim;
        vagas[indice-1].tamanho = vagas[indice-1].fim - vagas[indice-1].inicio + 1;  
        vagas.erase(vagas.begin()+indice);
    }
}
void debbuger(){
    cout << "VAGAS\n";
    for(auto &e: vagas){
        cout << e.inicio << " " << e.fim << " " << e.tamanho << " " << e.busy << "\n";
    }
    cout << "\n";
}


int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tam, oc;
    while(cin >> tam >> oc){
        vagas.clear();
        vagas.push_back(vaga(1,tam, false));
        //debbuger();
        char inst;
        int placa, comprimento;
        unsigned long long faturamento = 0;
        for(int i=0; i<oc; i++){
            cin >> inst >> placa;
            if(inst=='C'){
                cin >> comprimento;
                faturamento+=buscaVaga(placa, comprimento);
                //debbuger();
            }else{
                liberaVaga(placa);
                //debbuger();
            }
        }
        cout << faturamento << "\n";
    }
    return 0;
}