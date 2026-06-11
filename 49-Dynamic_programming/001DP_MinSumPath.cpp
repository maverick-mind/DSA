#include<bits/stdc++.h>
using namespace std;
 

int fxnTopDown(int i , int j , const vector<vector<int>> & grid , int m , int n , vector<vector<int>> & dp)
{
    // state : dp[i][j] denotes minimum cost to reach [m-1 , n-1] fro [i,j]
    // for [i,j] as [0,0] would have larger value as compared to [i,j] as [m-2,n-1] or [m-1,n-2]

    // corner case 
    if(i >= m or j >= n) return INT_MAX ;

    // base case 
    if(i == m - 1 and j == n - 1) return 0 ; // from i as m-1 and j as n-1 , total cost to reach m-1 , n-1 would be 0

    // lookups 
    if(dp[i][j] != -1) return dp[i][j];


    // recurrence relation 
    // one can either go right or below 
    int costFromBelow = INT_MAX ; 
    if(i + 1 <= m -1)  costFromBelow = grid[i+1][j] + fxnTopDown(i+1 , j , grid , m , n , dp);

    int costFromRight = INT_MAX ;
    if(j + 1 <= n -1)costFromRight = grid[i][j+1] + fxnTopDown(i , j + 1 , grid , m , n , dp);

    dp[i][j] = min(costFromBelow , costFromRight);
    return dp[i][j];
}


int fxnTopDown2(int i , int j , const vector<vector<int>> & grid , int m , int n , vector<vector<int>> & dp)
{
    // state : dp[i][j] denotes minimum cost to reach [m-1 , n-1] fro [i,j]
    // for [i,j] as [0,0] would have larger value as compared to [i,j] as [m-2,n-1] or [m-1,n-2]

    // corner case 
    if(i >= m or j >= n) return INT_MAX ;

    // base case 
    if(i == m - 1 and j == n - 1) return grid[m-1][n-1] ; // from whereEver you have come to this position , the cost of this grid postion will be added

    // lookups 
    if(dp[i][j] != -1) return dp[i][j];


    // recurrence relation 
    // one can either go right or below 
    int costFromBelow =  fxnTopDown2(i+1 , j , grid , m , n , dp);

    int costFromRight =  fxnTopDown2(i , j + 1 , grid , m , n , dp);

    dp[i][j] = min(costFromBelow , costFromRight) + grid[i][j]; // from whereEver you have come on [i,j] the cost of grid[i][j] will also be added 

    return dp[i][j];
}

int fxnBottomUp(const vector<vector<int>> & grid)
{
    int m = grid.size() ;
    int n = grid[0].size();

    vector<vector<int>> dp(m , vector<int>(n));
    // state : dp[i][j] stores minimum path cost from grid[0][0] to grid[i][j]
    dp[0][0] = grid[0][0];
    for(int idx = 1 ; idx < n ; idx++)
    {
        dp[0][idx] = dp[0][idx-1] + grid[0][idx];
    }
    for(int idx = 1 ; idx < m ; idx++)
    {
        dp[idx][0] = dp[idx-1][0] + grid[idx][0];
    }

    for(int i = 1 ; i < m ; i++)
    {
        for(int j = 1 ; j < n ; j++)
        {
            dp[i][j] = grid[i][j] + min(dp[i-1][j] , dp[i][j-1]);
        }
    }

    return dp[m-1][n-1];


}

int main() 
{
    vector<vector<int>> grid = {
                                {1,3,1},
                                {1,5,1},
                                {4,2,1}
                               };

    int m = grid.size() ;
    int n = grid[0].size();
    // the state of dp depends on 2 things [row,col] thus it should be 2D vector
    vector<vector<int>> dp(m , vector<int>(n, -1));

    cout<<grid[0][0] + fxnTopDown(0 , 0 , grid , m , n , dp)<<endl;

    vector<vector<int>> dp2(m , vector<int>(n, -1));
    cout<<fxnTopDown2(0 , 0 , grid , m , n , dp2)<<endl;

    cout<<fxnBottomUp(grid)<<endl;
 
    return 0 ;
}