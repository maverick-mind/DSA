#include<bits/stdc++.h>
using namespace std;
 
// Time : O(2^n) : n*n + (n-1)*(n-1) + ..... 3*3 + 2*2 + 1*1 choices in each function call
// Space: O(n)
int fxnRec(int n , vector<int> & prices)
{
    // base case 
    if(n == 0) return 0 ; // fxn(0) : maximum profit for a rod of length 0
    
    // recurrence relation 

    int ans = INT_MIN ; 

    // to select peices to be cut , we have choices from [1 to n]
    for(int i = 1 ; i <= n ; i++) // adjust below 0 based indexing and 
    {                             // rod length , 1 based size 
        // if i length rod is cut 
        ans = max(ans , prices[i-1] + fxnRec(n - i , prices)) ; 
    }

    return ans ;
}
 

// Time : O(n²) : For every state k, for loop goes [1....k]
// Space: O(n) : due to 1D dp vector and fxn call stack 
int fxnTopDown(int n , vector<int> & prices , vector<int> & dp)
{
    // state : dp[i] stores maximum profit we can make by cutting rod of i length in all possible combinations available 

    // base case 
    if(n == 0) return dp[0] = 0 ; // rod of this much length cannot be sold , thus no profit made on this 

    // lookups : 
    if(dp[n] != -1) return dp[n];
    
    // recurrence relation 

    int ans = INT_MIN ; 

    // to select peices to be cut , we have choices from [1 to n]
    for(int i = 1 ; i <= n ; i++) // adjust below 0 based indexing and 
    {                             // rod length , 1 based size 
        // if i length rod is cut 
        ans = max(ans , prices[i-1] + fxnTopDown(n - i , prices , dp)) ; 
    }

    return dp[n] = ans ;
}

// time : O(n^2)
// space : O(n)
int fxnBottomUp(int n , vector<int> & prices)
{
    // state : dp[i] stores maximum profit you can make by cutting rod of length i
    vector<int> dp(n + 1 , 0);

    
    for(int i = 1 ; i <= n ; i++)
    {
        int maxSoFar = INT_MIN;
        for(int j = 1 ; j <= i ; j++)
        {
            maxSoFar = max(maxSoFar , prices[j-1] + dp[i - j]) ;
        }
        dp[i] = maxSoFar ;
    }

    return dp[n] ;
}
 

int main() 
{
    vector<int> prices = {1,5,8,9,10,17,17,20} ; 
    int n = prices.size() ; // initial rod length 
    
    cout<<fxnRec(n , prices)<<endl;

    vector<int> dp(n+1 ,-1);
    cout<<fxnTopDown(n , prices , dp)<<endl;

    cout<<fxnBottomUp(n , prices)<<endl;
 
 
    return 0 ;
}