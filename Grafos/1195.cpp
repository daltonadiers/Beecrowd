#include <iostream>

using namespace std;

struct node{
    int info;
    struct node *esq;
    struct node *dir;
};  
typedef struct node *Arvore;

void insere(Arvore& a, int valor){
    if(a==NULL){
        a = new node; a->info=valor;a->dir=NULL;a->esq=NULL;
    }else if (valor > a->info)
           insere (a->dir, valor); 
         else
           insere (a->esq, valor); 
}
void preorder(Arvore& a){
    if(a!=NULL){
        cout << " " << a->info;
        preorder (a->esq);
        preorder (a->dir);
  }
}

void inorder(Arvore& a){
    if(a!=NULL){
        inorder (a->esq); 
        cout << " " << a->info;
        inorder (a->dir);
  }
}
void posorder(Arvore& a){
    if(a!=NULL){
        posorder (a->esq);
        posorder (a->dir);
        cout << " " << a->info;
  }
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int c,n,val,caso=0;; cin >> c;
    while(c--){
        caso++;
        cin >> n;
        Arvore arv = NULL;
        for(int i = 0; i < n; i++){
			cin >> val;
			insere(arv, val);
		}
        cout << "Case " << caso << ":\n";
        cout << "Pre.:"; preorder(arv); cout << "\n";
        cout << "In..:"; inorder(arv); cout << "\n";
        cout << "Post:"; posorder(arv); cout << "\n\n";
    }
    return 0;
}