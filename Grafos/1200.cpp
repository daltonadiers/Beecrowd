#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode{
    char value;
    TreeNode* right;
    TreeNode* left;
    TreeNode(char x): value(x), right(nullptr), left(nullptr){}
};

vector<char> path;

void insert(TreeNode*& root, char val){
    if(!root){
        root = new TreeNode(val);
        return;
    }
    if(val <= root->value) {
        insert(root->left, val);
    }else{
        insert(root->right, val);
    }
    return;
}
bool contains(TreeNode*& root, char val){
    if(root==nullptr)return false;
    if(root->value==val)return true;
    return contains(root->left,val) || contains(root->right,val);;
    return false;
}
void infixa(TreeNode* root) {
    if(root != nullptr) {
        infixa(root->left);
        path.push_back(root->value);
        infixa(root->right);
    }
}
void prefixa(TreeNode* root){
    if(root!=nullptr){
        path.push_back(root->value);
        prefixa(root->left);
        prefixa(root->right);
    }
}
void posfixa(TreeNode* root){
    if(root!=nullptr){
        posfixa(root->left);
        posfixa(root->right);
        path.push_back(root->value);
    }
}
void printer(){
    for(int i=0; i<(int)path.size(); i++){
        if(i!=(int)path.size()-1)cout << path[i] << " ";
        else cout << path[i] << "\n";
    }
    path.clear();
}

int main(){
    TreeNode* root = nullptr;
    string instruct; char letter;
    while(cin >> instruct){
        if(instruct=="I"){
            cin >> letter;
            insert(root, letter);
        }else if(instruct=="P"){
            cin >> letter;
            if(contains(root, letter))cout << letter << " existe\n";
            else cout << letter << " nao existe\n";
        }else if(instruct=="INFIXA"){
            infixa(root);
            printer();
        }
        else if(instruct=="PREFIXA"){
            prefixa(root);
            printer();
        }
        else if(instruct=="POSFIXA"){
            posfixa(root);
            printer();
        }
    }
    return 0;
}