/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/2176
*/
#include <iostream>
#include <string>

using namespace std;
int main(){
    string str;
    cin>>str;
    int count=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='1')
            count++;
    }
    if(count%2==0){
        str=str+'0';
    }
    else{
        str=str+'1';
    }
    cout << str << endl;

    return 0;
}
