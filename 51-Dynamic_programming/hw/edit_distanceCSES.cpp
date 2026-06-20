// // levenshtein distance , other name for edit distance
// https://cses.fi/problemset/task/1639/
// space constraints on cses thus optimised bottom up solution :
                // so optimse space to avoid Memory Limit exceeds 

#include<bits/stdc++.h>
using namespace std;


// time :  O(m + n)
// space : O(n) : single 1d vector 
// state : dp[i][j] stores minimum edit distance required when comparison is done between characters at index [i...m] in word1 to [j...n] in word2
int fxnBottomUpSpaceOptimised(string & word1 , string & word2 , int m , int n)
{
    // for 2d dp
    // dp[i][j] depends upon : [i, j+1]th cell immediate RIGHT neighbour ,
                            // [i+1 ,j]th cell immediate BOTTOM neighbour ,
                            // [i+1 , j+1]th cell DIAGONAL BOTTOM-RIGHT 

    // so if we want to use single 1D dp 
    // scenes at dp[i] : cannot be filled from left to right , as at [i][j]th cell , [i][j+1]th cell must be filled 
    // scenes at dp[i] : fill from right to left , but when [i]th cell is filled , we need to store previous value in [i]th cell because that could be the diagonal value for [i-1]th cell , and that must be preserved 

    // at [i]th cell [0.....i] would be value of current row , [i+1....m] would be value of just Below row 

    vector<int> dp(n+1) ; // last row of 2d dp when no characters left in word1 , then initialisation would depend with number of unmatched characters in word2 , that would simply be dp[m][j] = n - j ; for 2d dp 

    for(int j = 0 ; j <= n ; j++) // mth row initialisation in 2d dp 
    {
        dp[j] = n - j ; // number of insertions needed when i reachd m and j does not reached n 
    }

    for(int i = m - 1 ; i >= 0 ; i--) // bottom to top 
    {
        int unUpdated_below_iPlus1_below_jPlus1_cell = dp[n] ; 
        dp[n] =  (m-i) ; // nth column initialisation in 2d dp // number of deletions needed when j reaches n and i does not reaches m 
        for(int j = n - 1 ; j >= 0 ; j--) // right to left 
        {
            int unUpdated_below_i_below_j_cell = dp[j] ; // it should be preserved for the calculations of [j-1]th cell 
            dp[j] = min({ 1 + dp[j+1] /*insertion*/ ,
                         1 + dp[j] /*deletion*/ ,
                         (int)(word1[i] != word2[j]) /*substitution and char matched both handled*/ + unUpdated_below_iPlus1_below_jPlus1_cell /* diagonal below-right */ }) ;

            unUpdated_below_iPlus1_below_jPlus1_cell = unUpdated_below_i_below_j_cell ;
        }
    }

    return dp[0];
}
 
int main() 
{
    string s1; 
    string s2;

    getline(cin, s1);
    getline(cin, s2);
    
    int m = s1.size() ;
    int n = s2.size() ;

    cout<<fxnBottomUpSpaceOptimised(s1 , s2 , m , n)<<endl;


    return 0 ;
}