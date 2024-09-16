#include<iostream>
#include<cmath>
using namespace std;
bool issafe(int mat[][9], int i, int j , int n, int number){
    for(int k=0; k<n;k++){  // har row col m check kar rhe hai ki number row col m presenr n ho
        if(mat[k][j] == number || mat[i][k]== number) return false; // agar present hai to safe nahi hai rakhna
    }
n = sqrt(n);  // an sub grid m check karenge uske liye 
int si =(i/n) * n;// grid ka first row and
int sj= (j/n)* n; // first col nikalne hoga
for(int i= si; i<si+n; i++){ // loop chalega sub grid mein
    for(int j= sj; j<sj+n; j++){
        if(mat[i][j] == number) return false; // agar number prsent hai to false kr do
    }
}
return true; // means its safe
}
bool solvesudoku(int mat[][9] , int i, int j , int n){
    // base case
    if(i== n){    // i== n tak jana means print ho gya sudoku
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
return true;
    }
    if(j== n) return solvesudoku(mat ,i+1, 0, n);  // agr j== n tk gya to new i p jake j ko zero s suru karenge
    if(mat[i][j] !=0) return solvesudoku(mat, i,j +1, n); // agar already number hai to j ko j+1 kr denge

    // recursive case
 // ek empty cell ham fill kare baki recursion karega
 for(int number =1; number<=n; number++){
    if (issafe(mat , i , j , n ,number)){
        mat[i][j] = number;
        bool kybaakiemptycellfillhogye = solvesudoku(mat ,i, j+1, n);
        if (kybaakiemptycellfillhogye) return true;
        mat[i][j] =0; //backtracking
    }
 }
 return false;

}
int main(){
    int mat[][9] ={
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};
    solvesudoku(mat ,0 , 0, 9);
    return 0;
    }
