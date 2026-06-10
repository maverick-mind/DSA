#include<bits/stdc++.h>
using namespace std;


int fxnTopDown(int n , int k , vector<int> & dp)
{
    // state : dp[i] denotes total number of ways to reach ith stair 

    // base case 
    if(n < 0) return 0 ; // for n < 0 we cannot store dp[n]
    else if(n == 0) return dp[n] = 1 ; // 1 way to be at 0th stair , is to stand over there

    // lookups
    if(dp[n] != -1) return dp[n];


    // recurrence relation 
    int totalWays = 0 ; 
    for(int i = 1 ; i <= k ; i++)
    {
        totalWays += fxnTopDown(n-i , k , dp);
    }

    // memoization 
    dp[n] = totalWays ; 

    return dp[n];

}

 
int fxnBottomUp(int n , int k)
{
    // state : dp[i] denotes total number of ways to reach ith stair

    vector<int>dp(n+1); 
    dp[0] = 1 ; // starting at 0th stair , there is 1 ways to reach 0th stair 
    dp[1] = 1 ;

    for(int i = 2 ; i <= n ; i++)
    {   int totalWays = 0 ; // total ways to reach ith stair
        for(int j = 1 ; j <= k ; j++)
        {
            if(i - j >= 0)
            {
                totalWays +=  (dp[i-j]); // total ways to reach ith stair from jth stair 
            }
            else{ // we can break , bcoz j is always increasing 
                break ;
            }
        }
        dp[i] = totalWays ;
    }
    return dp[n];
} 

// dp[i] would be : sum of all the elements from dp[0] to dp[i-1]  - sum of all the elements from dp[0] to dp[(i-k) - 1]
// if we store this sum along the way from [0...n] , then we can find each dp[i] in constant time , and thus we can do transition optimization 
// now time : O(n) , earlier without transition optimization O(n*k)
int fxnBottomUpTransitionOptimised(int n , int k)
{
    // state : dp[i] denotes total number of ways to reach ith stair

    vector<int>dp(n+1); 
    vector<int> prefixSum(n + 1 , 0) ; 
    // prefixSum[i] will store , Sum of all the paths to reach ANY of the stairs in [0,i] from 0
    // that means : path from [0 to 0] : 1  + path from [0 to 1] : 1 + paths from [0 to 2] : 2 + ...and so on paths from [0 to i]


    dp[0] = 1 ; // starting at 0th stair , there is 1 ways to reach 0th stair 
    dp[1] = 1 ;
    prefixSum[0] = 1 ; // total path to reach all the elements from [0...to...0] is : 1 
    prefixSum[1] = 2;  // total paths to reach all the elements from [0..to..1] is : 2 (0 to 0 : 1 , 0 to 1 : 1 , adding all 1 + 1 = 2)

    for(int i = 2 ; i <= n ; i++)
    {  
        if(i <= k)
        {
            dp[i] = prefixSum[i-1];
        }else{
            dp[i] = prefixSum[i-1] - prefixSum[(i - k) - 1];
        }
        prefixSum[i] = dp[i] + prefixSum[i - 1] ; 
    }
    return dp[n];
} 

int main() 
{
    int n = 4 ; 
    int k = 3 ;

    cout<<fxnBottomUp(n , k)<<endl;

    vector<int> dp(n+1 , -1);
    cout<<fxnTopDown(n,k,dp)<<endl;

    cout<<fxnBottomUpTransitionOptimised(n , k)<<endl;
 
    return 0 ;
}