#include <bits/stdc++.h>
using namespace std;

int fxnRec(string &s1, int m, string &s2, int n, int i, int j)
{
    // base case
    if (i == m or j == n)
        return 0; // if no character left from either of string , it won't change answer

    // recurrence relation

    // if characters matched , i++ and j++
    // if characters does not matched , you have choice , do i++ , and then do j++

    if (s1[i] == s2[j])
    {
        return 1 + fxnRec(s1, m, s2, n, i + 1, j + 1);
    }

    // else 
    return max(fxnRec(s1, m, s2, n, i + 1, j) , fxnRec(s1, m, s2, n, i, j + 1)) ;
}

int fxnTopDown(string & s1 ,int m , string & s2 , int n , vector<vector<int>> & dp)
{
    // state : dp[m][n] stores count of longest common sequence from (m-1)th char in s1 and (n-1)th char in s2 to their starting char

    // base case 
    if(m == 0 or n == 0) return dp[m][n] = 0 ;

    // lookups 
    if(dp[m][n] != -1) return dp[m][n];

    // recurrence relation 
    if(s1[m-1] == s2[n-1])
    {
        return dp[m][n] = 1 + fxnTopDown(s1 , m-1 , s2 , n-1 , dp);
    }

    // else 
    return dp[m][n] = max(fxnTopDown(s1 , m-1 , s2 , n , dp) , fxnTopDown(s1 , m , s2 , n-1 , dp));

}

int fxnBottomUp(string & s1 ,int m , string & s2 , int n)
{
    // state : dp[i][j] : stores largest common subsequence from s1 : [0,i] and s2 : [0,j]
    vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));

    for(int i = 1 ; i <= m ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout<<dp[i][j]<<"  ";
        }cout<<endl;
    }cout<<endl;
    return dp[m][n];
}

int main()
{
    // longest common subsequence is an application to find similarity between 2 DNA sequences 
    string s1 = "ATGC";
    int m = s1.size();

    string s2 = "AGCT";
    int n = s2.size();

    cout << fxnRec(s1, m, s2, n , 0 , 0) << endl;

    vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));

    cout<<fxnTopDown(s1, m, s2, n , dp)<<endl;

    cout<<endl;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout<<dp[i][j]<<"  ";
        }cout<<endl;
    }
    cout<<endl;

    cout<<fxnBottomUp(s1, m, s2, n)<<endl;

    return 0;
}