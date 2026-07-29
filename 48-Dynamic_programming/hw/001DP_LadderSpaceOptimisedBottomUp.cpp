// in bottom up solution , try to optimise the space from O(n) to O(k)
// at any instance , we need path counts of last 'k' numbers only 

/*

Suppose there is a ladder with n steps.  A person standing at the
bottom of the  ladder and  wants to reach to its top. Assume the
person can take a jump of size 1 to k at a time. Then, count the
number of ways, the person can reach the top of the ladder.

Example
	Input : n = 4, k = 3
	Output: 7
	Explanation : [1, 1, 1, 1],
	              [1, 1, 2],
	              [1, 2, 1],
	              [2, 1, 1],
	              [2, 2],
	              [1, 3],
	              [3, 1]

*/

#include<bits/stdc++.h>
using namespace std;

// time : O(n)
// space : O(k)

// rolling window optimization , it will give result correctly for both n <= k , k <= n , but preffer it for k <= n
int fxnBottomUpSpaceOptimised(int n , int k)
{
    // state : dp[i%k] represents total number of ways to reach ith stair
    vector<int> dp(k , 0) ;
    dp[0] = 1 ; // there is only 1 way to reach 0th stair from 0th stair 


    int ways = 1 ; // ways stores the sum of all valid previous states needed to compute dp[i].
                   // Before computing dp[i]:
                   // ways = dp[i-1] + dp[i-2] + ... + dp[max(0, i-k)] 
                   // total number of ways to reach ith stair : sum of all these previous k stairs 
    // Before computing dp[i], ways should always equal
    // dp[i-1] + dp[i-2] + dp[i-3] + ...... + dp[i-(k-1)] + dp[i-k]
    
    for(int i = 1 ; i <= n ; i++) // current stair : i
    {
        // For the first k stairs, the sliding window is still growing.
        // Once i >= k, the oldest value leaves the window and is replaced. 
            int oldValue  = dp[i % k] ;
            dp[i % k] = ways ; 
            ways += dp[i % k] - oldValue  ; 

    }

    return dp[n % k] ;
}
 
// we can also prefer using a deque or maintaining a full dp array and can apply sliding window concept for k size window because the logic is easier to verify
/*
dp[i] = windowSum;
windowSum += dp[i];

if (i >= k)
    windowSum -= dp[i-k];
*/
int fxnBottomUpSpaceOptimised2(int n , int k) // only change is dp initialization 
{
    // state : dp[i%k] represents total number of ways to reach ith stair
    vector<int> dp(k) ;
    dp[0] = 1 ; // there is only 1 way to reach 0th stair from 0th stair 


    int ways = 1 ; // ways stores the sum of all valid previous states needed to compute dp[i].
                   // Before computing dp[i]:
                   // ways = dp[i-1] + dp[i-2] + ... + dp[max(0, i-k)] 
                   // total number of ways to reach ith stair : sum of all these previous k stairs 
    // Before computing dp[i], ways should always equal
    // dp[i-1] + dp[i-2] + dp[i-3] + ...... + dp[i-(k-1)] + dp[i-k]
    
    for(int i = 1 ; i <= n ; i++) // current stair : i
    {
        // For the first k stairs, the sliding window is still growing.
        // Once i >= k, the oldest value leaves the window and is replaced.
            int oldValue  = dp[i % k] ;
            dp[i % k] = ways ; 

            // if(i < k)
            // {
            //     ways += dp[i % k] ;
            // }
            // else ways += dp[i % k] - oldValue  ; 
            
            // or 

            ways += dp[i % k] ;

            if(i >= k) ways -= oldValue  ;

    }

    return dp[n % k] ;
}


int main() 
{
    int n = 4 , k = 3 ;

    cout<<fxnBottomUpSpaceOptimised2(n , k)<<endl;
 
    return 0 ;
}