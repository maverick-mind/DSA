#include<bits/stdc++.h>
using namespace std;

// time : O(3^((m+1) + (n+1))) //  (m+1) + (n+1) because ek baar insert kar rhe hai aur ek baar delete kar rhe hai 
// space O(m+n) : fxn call stack 
int fxnRec(string & word1 , string & word2 , int m , int n , int i , int j)
{
    // base case 
    if(i == m and j == n) // no characters left in word1 and word2
            return 0 ; 
    
    if(i == m and j != n) // no characters left in word1 , but some characters left in word2
            return n - j ; // in this case we need to insert n - j  char in the end of word1

    if(i != m and j == n) // some characters left in word1 and no characters left in word2
            return m - i ; // in this case , we need to delete m - i characters from the end of word1

    // recurrence relation
    int insertOperationCount  = 1000 ;
    int deleteOperationCount  = 1000 ;
    int replaceOperationCount  = 1000 ;
    int totalOperationCount  = 1000 ;
    int noOperation  = 1000 ;
    if(word1[i] == word2[j]) // both characters matched , no need for operation 
        return fxnRec(word1 , word2 , m , n , i + 1 , j + 1);

    if(word1[i] != word2[j])
    {
        // 3 possibility :
        // 1. insert a character 
        insertOperationCount = 1 + fxnRec(word1 , word2 , m , n , i , j + 1);

        // 2. delete a character 
        deleteOperationCount = 1 + fxnRec(word1 , word2 , m , n , i + 1 , j);

        // 3. replace a character 
        replaceOperationCount = 1 + fxnRec(word1 , word2 , m , n , i + 1 , j + 1);

    }
        return min({insertOperationCount , deleteOperationCount , replaceOperationCount});

}

// time : O(m+n) due to (m+1) + (n+1) unique problems 
// space :O(m+n) due to 2d dp vector
int fxnTopDown(string & word1 , string & word2 , int m , int n , int i , int j , vector<vector<int>> & dp)
{
    // state dp[i][j] store minimum operation required from ith character of word1 to end character of word1 to match it with jth character of word2 to end character of word2

    // state : dp[i][j] : minimum number of operations needed to convert
                        // word1[i ... end]  →  word2[j ... end]


    // base case 
    if(i == m and j == n) // no characters left in word1 and word2
            return dp[i][j] = 0 ; 
    
    if(i == m and j != n) // no characters left in word1 , but some characters left in word 2
            return dp[i][j] = n - j ; // in this case we need to insert n - j  char in the end of word1

    if(i != m and j == n) // some characters left in word1 and no characters left in word2
            return dp[i][j] = m - i ; // in this case , we need to delete m - i characters from the end of word1

    // lookups 
    if(dp[i][j] != -1) return dp[i][j];

    // recurrence relation

    if(word1[i] == word2[j]) // both characters matched , no need for operation 
        return dp[i][j] = fxnTopDown(word1 , word2 , m , n , i + 1 , j + 1 , dp);


    
    int insertOperationCount  = 1000 ; // due to problem constraints 1000 is a safe choice 
    int deleteOperationCount  = 1000 ;
    int replaceOperationCount  = 1000 ;

    if(word1[i] != word2[j])
    {
        // 3 possibility :
        // 1. insert a character 
        insertOperationCount = 1 + fxnTopDown(word1 , word2 , m , n , i , j + 1 , dp);

        // 2. delete a character 
        deleteOperationCount = 1 + fxnTopDown(word1 , word2 , m , n , i + 1 , j , dp);

        // 3. replace a character 
        replaceOperationCount = 1 + fxnTopDown(word1 , word2 , m , n , i + 1 , j + 1 , dp);

    }

    // memoization 
        return dp[i][j] = min({insertOperationCount , deleteOperationCount , replaceOperationCount});
}

// int minDistance(string word1, string word2) {
    
// }
 


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
    string s1 = "food" ; 
    string s2 = "money" ; // ans : 4
    
    int m = s1.size() ;
    int n = s2.size() ;

    cout<<fxnRec(s1 , s2 , m , n , 0 , 0)<<endl;

    vector<vector<int>> dp(m + 1 , vector<int>(n + 1 , -1)) ; 
    cout<<fxnTopDown(s1 , s2 , m , n , 0 , 0 , dp)<<endl;
    cout<<fxnBottomUpSpaceOptimised(s1 , s2 , m , n)<<endl;


    return 0 ;
}