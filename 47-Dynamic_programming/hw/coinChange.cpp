#include<bits/stdc++.h>
using namespace std;


int fxnTopDown(int amount, vector<int> &coins, vector<int> &dp)
{
    // state : dp[amount] deonotes fewest number of coins required to make up to this amount

    // base case
    if (amount == 0)
        return dp[0] = 0;

    // lookups
    // -1 for unvisited amount , INT_MAX for unreachable amount
    if (dp[amount] != -1)
        return dp[amount];

    // recurrence relation

    int minCoinsNeeded = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {
        int remainingAmtForExchange = amount - coins[i];
        if (remainingAmtForExchange >= 0) // if remaining amount is +ve then only coins exchange is possible
        {
            minCoinsNeeded = min(minCoinsNeeded, fxnTopDown(remainingAmtForExchange, coins, dp));
        }
    }

    if (minCoinsNeeded != INT_MAX)
    {
        // memoization
        dp[amount] = 1 + minCoinsNeeded; // current Amount can be reached using 1 Coin from the coinChange , and minCoinsNeeded for remainingAmtForExchange
    }
    else
    {                         // if(minCoinsNeeded == INT_MAX)
        dp[amount] = INT_MAX; // unreachable amount : amount cannot be exchanged with available coins
    }

    return dp[amount];
}

int fxnBottomUp(int amount, vector<int> &coins)
{
    // filling of dp[] : -1 for unrechable amount
    vector<int> dp(amount + 1,);
    dp[0] = 0;
    // dp[i] will store minimum coins needed to make up 'i' amount

    for (int i = 1; i <= amount; i++)
    {
        int ccfi = INT_MAX; // count of coins change for 'i' amount
        for (int j = 0; j < coins.size(); j++)
        {
            if (i - coins[j] >= 0) // that coin is only useful for this 'i' amount
            {                      // if amount is bigger than this coin

                // if dp[ i - coins[j]] is reachable then only , dp[i] could be reachable through dp[ i - coins[j]]
                if (dp[i - coins[j]] != -1) // -1 for unrechable amount
                    ccfi = min(ccfi, dp[i - coins[j]]);
            }
        }
        if (ccfi != INT_MAX)
        {
            dp[i] = 1 + ccfi;
        }
    }
    return dp[amount];
}

int fxnBottomUpSimplified(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, -1); // -1 for unvisited , INT_MAX for unreachable
    int coinsNeeded = fxnTopDown(amount, coins, dp);

    if (coinsNeeded == INT_MAX)
        return -1;
    return coinsNeeded;

    // return fxnBottomUp(amount , coins);
}

int main()
{
    // vector<int>coins = {186,419,83,408};
    // int amount = 6249 ; // ans : 20

    vector<int> coins = {1,2,5};
    int amount = 11;  // ans : 3 , coins needed : {5,5,1}

    cout<<coinChange(coins , amount);

    return 0 ; 
}