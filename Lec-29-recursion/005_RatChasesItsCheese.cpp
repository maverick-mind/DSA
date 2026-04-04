#include<bits/stdc++.h>
using namespace std;

// c-style array is passed by refrence 
void fxn(char maze[][10], int m, int n, int i, int j) 
{
    // cout<<"hi"<<endl;
    // corner case
    if( i < 0 or j < 0) return ; // to control movement in left and top direction
    if( i >= m or j >= n) return ; // to control movement in right and down direction
    if(maze[i][j] == 'X') return ;

    // base case 
    if(i == m - 1 and j == n - 1 )
    {
        maze[i][j] = '1'; // include the last cell in your path 
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<maze[i][j]<<" ";
            }cout<<endl;
        }cout<<endl;
         maze[i][j] = '0'; // backtrcking to the last cell
        return ;
    }


    // recurrence relation 
    // include the current cell (i,j) in your path , and move recursively to right and down

     // i,jth cell is already part of the path that we are building // you cannot use the same cell twice while building a path
    if(maze[i][j] == '1') return ; 



    maze[i][j] = '1' ; 

    // but aisaa karne se ye 4 blocks ke bich mein fass gya hai , pahle right gya fir top gya fir left gya fir down gya , aur ye baar baar hota gya , top avoid this hum fix ye karenge ki , next call tabhi hogy agar wo cell aleady 1 nahi hai , yaani wo pahle se part of the path nahi hai 
    fxn(maze, m, n, i, j + 1 ) ; // right direction
    fxn(maze, m, n, i - 1  , j ) ; // top direction
    fxn(maze, m, n, i, j - 1) ; // left direction
    fxn(maze, m, n, i + 1 , j ) ; // down direction
    maze[i][j] = '0' ; // backtracking 

}
 
int main() 
{
    char maze[][10] = {
		"0000",
		"X0X0",
		"000X",
		"0X00"
	};

	int m = 4;
	int n = 4;

	 fxn(maze, m, n, 0, 0) ;

    return 0 ;
}