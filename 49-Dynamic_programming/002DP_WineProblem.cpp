#include <bits/stdc++.h>
using namespace std;

int fxnTopDown(vector<int> & prices , int start , int end , vector<vector<int>> & dp)
{   
    // state : for dp[start][end] we can get maximum value either by selling start and go in [start+1 , end] or we can get maximum value by selling end and go in [start , end - 1]
    // year will be managed as year is not an independent variable 
    // for same [start,end] : year is always going to be same because of : Year = prices.size() - (end - start)
    // and we can reach a same [start,end] through different combinations of selling , so dp[start][end] is a repeating sub-problem 

    // base case 
    if(start > end) return 0 ; // no wine bottle left to sell 

    // lookups
    if(dp[start][end] != -1) return dp[start][end];

    // recurrence relation

    // in ith year , we can sell either starting bottle of wine or ending bottle of wine 
    int currentYear = prices.size() - (end - start);
    int startingBottleSoldInIthYear = prices[start] *currentYear + fxnTopDown(prices , start + 1 , end , dp);

    int endingBottleSoldInIthYear = prices[end] *currentYear + fxnTopDown(prices , start , end - 1 , dp);

    dp[start][end] = max(startingBottleSoldInIthYear , endingBottleSoldInIthYear);

    return dp[start][end];
}

int main()
{
    vector<int> prices = {2, 3, 5, 1, 4}; // output : 50

    int n = prices.size();
    vector<vector<int>> dp(n , vector<int>(n , -1));

    cout<<fxnTopDown(prices , 0 , n - 1 , dp)<<endl<<endl;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }


    return 0;
}