// count the total number of  paths from (0,0) to (n-1 , m-1)

#include<bits/stdc++.h>
using namespace std;
 

int fxn( char maze[][10] , int m , int n , int i , int j )
{
    // corner case 
    if(i >= m or j >= n) return 0 ; 
    if(maze[i][j] == 'X') return 0 ;

    // base case 
    if(i == m-1 and j == n-1) return 1 ;

    // recurrence relation
    // int a = 0  , b = 0 ;
    // a += fxn(maze , m , n , i , j + 1 ) ;
   
    // b += fxn(maze , m , n , i + 1  , j ) ; 

    // return a + b;

    // 
    return fxn(maze , m , n , i , j + 1 ) + fxn(maze , m , n , i + 1  , j ) ;

}

int main() 
{
 char maze[][10] = {
                    "0000" , // output : 3 
                    "00X0" ,
                    "000X" ,
                    "0X00"
    };
    int m = 4 , n = 4 ;

    cout<<fxn(maze , m , n , 0 , 0);
 
 
 
    return 0 ;
}