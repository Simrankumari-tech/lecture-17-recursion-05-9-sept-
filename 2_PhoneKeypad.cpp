#include<iostream>
using namespace std;
string key[] ={
    " " , " ", "ABC" , "DEF" , "GHI" , "JKL" , "MNO" ,"PQRS" , "TUV" ,"WXYZ"
};
string contact[]={
    "JIYA" ,"ANKIT"
};
void phonekeypad(string &ip , string &op, int i){
    // base case
if(i == ip.size()){
    for(int j= 0; j<2 ; j++){
        if(contact[j] == op) cout << op << endl;
    }
    return ;
}

    // recursive case
    int digit = ip[i] - '0';
    for(int k= 0; k<key[digit].size() ; k++){
        char ch = key[digit][k];

        op.push_back(ch) ;
        phonekeypad(ip , op ,i+1);
        op.pop_back();
    }
}
int main(){
    string ip , op;
    cin >> ip;
phonekeypad(ip, op, 0);
return 0;
}