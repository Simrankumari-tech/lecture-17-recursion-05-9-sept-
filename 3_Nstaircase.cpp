#include<iostream>
using namespace std;
int stairs(int n){

// base case
if(n == 0) return 1;    // when k is fixed
if(n<0) return 0;
return stairs(n-1) +stairs(n-2) +stairs(n-3);

}
int nstairs(int n , int k){
    if(n == 0) return 1;    // when k isnt't fixed
if(n<0) return 0;
int ans =0;
for(int i =1; i<=k ; i++){
    ans+= nstairs(n-i , k) ;
}
return ans;
}
int main(){
cout << nstairs(6,3) << endl;
return 0;
}