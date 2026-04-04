#include<bits/stdc++.h>
using namespace std;

// c-style array is passed by refrence 
void fxn(char maze[][10], int m, int n, int i, int j) 
{
    
    // corner case
    if( i >= m or j >= n) return ;
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
    maze[i][j] = '1' ; 
    fxn(maze, m, n, i, j + 1 ) ; 

    // maze[i][j] = '0' ; // backtracking no need as why hum 1 ko hataa ke 0 karee fir uss 0 ko 1 karee next line mein 
    // maze[i][j] = '1' ; // no need 
    fxn(maze, m, n, i + 1 , j ) ; 
    maze[i][j] = '0' ; // backtracking 

}
 
int main() 
{
    char maze[][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00"
	};

	int m = 4;
	int n = 4;

	 fxn(maze, m, n, 0, 0) ;

    return 0 ;
}