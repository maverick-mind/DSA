#include<bits/stdc++.h>
using namespace std;



int fxnTopDown(int n , vector<int> & dp)
{
    // state : dp[n] stores minimum steps to reach n to 1 

    // base case 
    if(n == 1) return dp[n] = 0 ; 

    // lookup before recursion call
    if(dp[n] != -1) return dp[n];


    // recurrence relation
    int ans = INT_MAX ;
    if(n % 3 == 0)
    {
        ans = min(ans ,fxnTopDown(n/3 , dp));
    } 
    if(n % 2 == 0)
    {
        ans = min(ans , fxnTopDown(n/2 , dp));
    }
    ans = min(ans , fxnTopDown(n-1 , dp));

    // memoizaiton before return 
    return dp[n] = ans + 1 ; // 1 step from minStepsReqFromPrevNum to current number 
}



 
int fxnBottomUp(int n)
{
    // state : dp[i] will store minimum steps to reach from 1 to i
    vector<int>dp(n+1 , -1) ; 
    dp[0] = -1 ; // none of our use 
    dp[1] = 0 ; // zero steps required to reach 1 from 1 

    for(int i = 2 ; i < dp.size() ; i++)
    {
        int minStepsReqFromPrevNum = INT_MAX; 

        if(i % 2 == 0)
        {
            minStepsReqFromPrevNum = min(minStepsReqFromPrevNum , dp[i/2]);
        }
        if(i % 3 == 0)
        {
            minStepsReqFromPrevNum = min(minStepsReqFromPrevNum , dp[i/3]);           
        }
        
        minStepsReqFromPrevNum = min(minStepsReqFromPrevNum , dp[i-1]);

        dp[i] = minStepsReqFromPrevNum + 1 ; // tabulation
    }

    return dp[n];
}
 
int main() 
{
    int n = 100 ;

    cout<<"bottom up : "<<fxnBottomUp(n)<<endl;

    vector<int>dp(n+1 , -1);
    cout<<"top down : "<<fxnTopDown(n,dp)<<endl;
 
    return 0 ;
}