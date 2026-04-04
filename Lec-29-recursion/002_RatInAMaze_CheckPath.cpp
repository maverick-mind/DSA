// check if there exists a path from (0,0) to (n-1 , m-1)

#include<bits/stdc++.h>
using namespace std;

bool fxn( char maze[][10] , int m , int n , int i , int j )
{

    // base case 
    if((i == m - 1 and j == n - 1) and maze[i][j] !='X') return true ;

    // corner case 
    if( i >= m or j >= n) return false ;
    if(maze[i][j] == 'X') return false ;

    // recurrence relation
    // f(i,j) : check if there exists a path from (i , j)th cell to (m-1 , n-1)th cell

    // decide the next step

    // option 1 : move right
   // bool r = fxn(maze , m , n , i , j + 1 );

    // option 2 : move down 
   //  bool d = fxn(maze , m , n , i + 1  , j );

    // return ( r or d);

    return fxn(maze , m , n , i , j + 1 ) or fxn(maze , m , n , i + 1  , j ) ;

}
 
int main() 
{
    char maze[][10] = {
                    "0000" , 
                    "00X0" ,
                    "000X" ,
                    "0X00"
    };
    int m = 4 , n = 4 ;

    fxn(maze , m , n , 0 , 0) ? cout<<"Path exists " : cout<<"Path does not exists";
 
    return 0 ;
}