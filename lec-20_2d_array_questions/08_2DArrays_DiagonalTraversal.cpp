#include<bits/stdc++.h>
using namespace std ; 
 
// void diagonalTraversal(int mat[][10] , int m , int n )
// {
//     //int i = m - 1 , j = 0 ;
//     int rows_starting = m -1 ; //  row starts at 
//     int col_starting = 0 ; //  column starts at
    

//     while(rows_starting >= 0 and col_starting < n )
//     {
//       int i = rows_starting , j = col_starting;
//       while(i >= 0 and i <= m - 1 and j >= 0 and j <= n-1)
//       {
//         cout<<mat[i][j]<<" ";
//         i++ ; j++;
//         if(i == 0 and j == n-1) return ; 
//       }
//       cout<<endl;
//       if(rows_starting > 0) rows_starting--;
//       if(i <= j) col_starting++;
//     }

// }

void printDiagonal(int mat[][10] , int m , int n , int i , int j)
{
    // while(i < m and j < n)
    // {
    //     cout<<mat[i++][j++]<<" ";
    // }cout<<endl;

    // or 
    int diaglen = min(m-i , n-j);
    for (int k = 0; k < diaglen; k++)
    {
        cout<<mat[i+k][j+k]<<" ";
    }cout<<endl;
}

void diagonalTraversal(int mat[][10] , int m , int n)
{
    // iterate over diagonals starting points
    // starting points could be of 2 form --> (0 , j) or (i , 0)

    // (0,j) se shuru hoone waale Diagonal
    for (int j = 0; j < n; j++)
    {
        printDiagonal(mat , m , n , 0 , j);
    }


    // (i,0) se shuru hoone waale Diagonal 
    // i --> 1 se issliye shuru kiya hai taaki  (0,0) waala diagonal 2 baar include na ho jaaye , kyonki wo ek baar already include ho gya hai (0,j) mein 
    for (int i = 1; i < m; i++)
    {
        printDiagonal(mat , m , n , i , 0);
    }
}
 
void diagTraversal(int mat[][10] , int m , int n)
{
    // iterate over diagonals starting points
    // starting points could be of 2 form --> (0 , j) or (i , 0)


    // (i,0) se shuru hoone waale Diagonal 
    // i --> 1 se issliye taaki (0,0) waala diagonal 2 baar include na ho jaaye , kyonki wo ek baar already include ho gya hai (0,j) mein
    for (int i = n-1; i >= 1; i--)
    {
        printDiagonal(mat , m , n , i , 0);
    }

    // (0,j) se shuru hoone waale Diagonal
    for (int j = 0; j < n; j++)
    {
        printDiagonal(mat , m , n , 0 , j) ;
    }

}

int main() 
{
    	int mat[10][10] = {
		{11, 12, 13, 14},
		{15, 16, 17, 18},
		{19, 20, 21, 22}
	};

	int m = 3;
	int n = 4;

	diagonalTraversal(mat, m, n);
    // diagTraversal(mat , m , n);
 
    return 0 ;
}