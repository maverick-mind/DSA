// https://cses.fi/problemset/task/1158

// if creating int type array on stack : above 10^6 size array is danger zone for memory limit exceed
// if creating int type array on heap : above 10^6 size array is danger zone for memory limit exceed

// based on 0/1-knapsack 



#include<bits/stdc++.h>
using namespace std;

// time : O(n*x)
// space : O(x)
long long fxnBottomUp(vector<int> & prices , vector<int> & pages , int n , int x)
{
    // state : dp[i][amount] : states maximum number of pages one can buy from book [i....(n-1)] when maximum price one can pay is : amount 

    vector<vector<long long>> dp(n+1 , vector<long long>(x+1 , 0)) ; // initialisation handled by : 0

    for(int i = n - 1 ; i >= 0 ; i--)
    {
        for(int amt = 0 ; amt <= x ; amt++)
        {
            // If I am able to buy this current book , I have 2 choices 
            // 1. either buy this book 
            // 2. don't buy this bok 
            // I will go with the one which can give maximum number of pages 
            if(prices[i] <= amt)
            {
                dp[i][amt] = max(pages[i] + dp[i+1][amt-prices[i]] , dp[i+1][amt]) ;
            }else{
                // if I cannot buy this current book
                dp[i][amt] = dp[i+1][amt] ;
            }
        }
    }

    return dp[0][x] ;
}
 

// ith row dp is only dependent on (i+1)th row , so 2D dp can be optimised into two 1-D DP
// time : O(n*x)
// space : O(x)
long long fxnBottomUpSpaceOptimised(vector<int> & prices , vector<int> & pages , int n , int x)
{
    // state : dp[i][amount] : states maximum number of pages one can buy from book [i....(n-1)] when maximum price one can pay is : amount 

    vector<long long> dpPrev(x+1 , 0) ; // initialisation handled by : 0

    for(int i = n - 1 ; i >= 0 ; i--)
    {
        vector<long long> dpCurrent(x+1 , 0) ;
        for(int amt = 0 ; amt <= x ; amt++)
        {
            // If I am able to buy this current book , I have 2 choices 
            // 1. either buy this book 
            // 2. don't buy this bok 
            // I will go with the one which can give maximum number of pages 
            if(prices[i] <= amt)
            {
                dpCurrent[amt] = max(pages[i] + dpPrev[amt-prices[i]] , dpPrev[amt]) ;
            }else{
                // if I cannot buy this current book
                dpCurrent[amt] = dpPrev[amt] ;
            }
        }

        dpPrev = dpCurrent ; // dpCurrent will become dpPrev in next round
    }

    return dpPrev[x] ;
}
 

int main() 
{
    int n ; // number of books 
    int x ; // maximum total price 

    cin >> n >> x ;

    // what is the maximum number of pages one can buy ?

    vector<int> prices(n) ;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> prices[i] ;
    }

    vector<int> pages(n) ;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> pages[i] ;
    }


    // cout<<fxnBottomUp(prices , pages , n , x) ;
    cout<<fxnBottomUpSpaceOptimised(prices , pages , n , x) ;
 
    return 0 ;
}
