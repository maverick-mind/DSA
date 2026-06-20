#include<bits/stdc++.h>
using namespace std;
 
bool fxnRec(string & s , string & p , int m , int n , int i , int j)
{
    // base case 
    // if pointer on string s reaches m , then in string p , from i to n there should only be '*' otherwise return false
    if(i == m)
    {
        while(j != n)
        {
            if(p[j] != '*') return false ;
            j++;
        }
        return true ; 
    }
    // if pointer on string p reaches n , then return false , both string cannot be matched 
    if(j == n) return false ; // we will only reach on this line when i != m 


    // recurrence relation 
     
    // case 1. both character matched 
    if(s[i] == p[j])
        return fxnRec(s , p , m , n , i+1 , j+1);

    // return (s[i] == p[j]) and fxnRec(s , p , m , n , i+1 , j+1);

    // case 2. if characters does not matched 
    // case 2.1 if p[j] == '?' 
    if(p[j] == '?') // equivalent to both characters matched 
        return fxnRec(s , p , m , n , i+1 , j+1);


    // case 1 and 2.1 combined 
    // return (s[i] == p[j] or p[j] == '?') and fxnRec(s , p , m , n , i+1 , j+1) ; // not a right way , it does not allow execution to pass to below if statement 
    
    if(p[j] == '*')
    {
        return fxnRec(s , p , m , n , i , j +1 )/*if zero characters from s is equivalent to '*' at j , thus i remains at i + 0 and j moves 1 step ahead */
        or fxnRec(s , p , m , n , i+1  , j)/*if one by one (i+1) many continous characters from s is equivalent to '*' at j */ 
        or fxnRec(s , p , m , n , i+1 , j + 1); // if single character from s is equivalent to '*' , thus i + 1 and j + 1 
    }

    return false ; // when string characters mismatch like : s[i] : 'a' and p[j] : 'c' , then return false 
}
 
// time : O(m*n + n^2) ~ (m+1)*(n+1) unique subproblems , and base case is not constant work , in worst case the while loop runs n times for each dp[m][0] dp[m][1] .... dp[m][n] each time we hit the base case , due to base case additional n^2
// sace : O(m*n) ~ dp[][] of ((m + 1) x (n + 1)) + O(m+n) function call stack 
bool fxnTopDown(string & s , string & p , int m , int n , int i , int j ,  vector<vector<int>> & dp)
{
    // state : dp[i][j] stores boolean value for string matching for suffix starts at i in string s and suffix starts at jth index for sting p 


    // lookups : in this question , lookups should be before base case , because base case is not constant work 
    if(dp[i][j] != -1) return dp[i][j] ; 


    // base case 
    // if pointer on string s reaches m , then in string p , from i to n there should only be '*' otherwise return false
    if(i == m)
    {
        int curr = j ; // for this specific i and current j , we are trying to find solution 
        while(j != n) // if any non '*' character is from [j...n] , return false 
        {
            if(p[j] != '*') return dp[m][curr] = false ;
            j++;
        }
        return dp[m][curr] = true ; 
    }
    // if pointer on string p reaches n , then return false , both string cannot be matched 
    if(j == n) return dp[i][j] = false ; // we will only reach on this line when i != m 


    // recurrence relation 
     
    // case 1. both character matched 
    if(s[i] == p[j])
        return dp[i][j] = fxnTopDown(s , p , m , n , i+1 , j+1 , dp);

    // return (s[i] == p[j]) and fxnTopDown(s , p , m , n , i+1 , j+1, dp);

    // case 2. if characters does not matched 
    // case 2.1 if p[j] == '?' 
    if(p[j] == '?') // equivalent to both characters matched 
        return dp[i][j] = fxnTopDown(s , p , m , n , i+1 , j+1 , dp);


    // case 1 and 2.1 combined 
    // return (s[i] == p[j] or p[j] == '?') and fxnTopDown(s , p , m , n , i+1 , j+1 , dp) ; // not a right way , it does not allow execution to pass to below if statement 
    
    if(p[j] == '*')
    {
        return dp[i][j] = fxnTopDown(s , p , m , n , i , j +1 , dp)/*if zero characters from s is equivalent to '*' at j , thus i remains at i + 0 and j moves 1 step ahead */
        or fxnTopDown(s , p , m , n , i+1  , j , dp);/*if one by one (i+1) many continous characters from s is equivalent to '*' at j */ 
       // or fxnTopDown(s , p , m , n , i+1 , j + 1 , dp); // if single character from s is equivalent to '*' , thus i + 1 and j + 1 , this is redundant , can be handled by first two , (i , j + 1) then (i + 1 , j) will reach same as (i + 1 , j + 1)
    }

    // memoization 
    return dp[i][j] = false ; // when s[i] != p[j] and p[j] is not a wild card , neither from '?' or '*'
}

// in 2d dp , dp[i][j] depends upon [i,j+1] , [i+1 , j+1] , [i+1 , j]
// so clearly we can optimise the space using one single dp and 1 variable 
int fxnBottomUpSpaceOptimised(string & s , string & p , int m , int n)
{
    // in bottom up always start moving away from base case , thus here bottom to up and right to left 
    vector<int>dp(n + 1); // initially dp vector denote the base case i == m , i.e. we have reached the end of string s , but not reached the end of string p

    dp[n] = true ; // i == m and j == n : it shoule be true 

    // if only '*' is in the end of string p from [j...n-1] then only fill true , otherwise false 
    for(int j = n - 1 ; j >= 0 ; j--) // initialization of [m]th row 
    {
        dp[j] = (p[j] == '*') and dp[j+1] ; // jth char mein '*' ho , aur j+1 to n mein bhi '*' ho
    } // now mth row is filled inside dp[]

    // scenes on dp[i] : from [0 to i] we have (i+1)th row , from [i+1 to n] we have ith row 
    for(int i = m - 1 ; i >= 0 ; i--)
    {   
        bool diag_iPlusOne_jPlusOne = dp[n] ;
        
        dp[n] = false ; // if string s has something (i != m) but string p ends (nth column) , string cannot be matched , thus false 
        for(int j = n - 1 ; j >= 0 ; j--)
        {   bool diag_iPlusOne_j = dp[j] ; 
            if(s[i] == p[j] or p[j] == '?')
            {
                dp[j] = diag_iPlusOne_jPlusOne;
            }else if(p[j] == '*')
            {
                dp[j] = dp[j] or dp[j+1] ; 
            }else{
                dp[j] = false ;
            }
            diag_iPlusOne_jPlusOne = diag_iPlusOne_j ; 
        }
    }
    return dp[0] ; // equivalent to 2d dp of dp[0][0] which stores if string s suffix from [0....m] and string p suffix from [0....n] matches or not 
}

int main() 
{
    string s = "aab" ;
    string p = "*aab" ;

    int m = s.size() ;
    int n = p.size() ;
    
    // if(fxnRec(s , p , m , n , 0 , 0))
    // {
    //     cout<<"string P matches entire string S"<<endl;
    // }else{
    //     cout<<"string P does not matches string S"<<endl;
    // }

    vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));
    if(fxnTopDown(s , p , m , n , 0 , 0 , dp))
    {
        cout<<"string P matches entire string S"<<endl;
    }else{
        cout<<"string P does not matches string S"<<endl;
    }

     if(fxnBottomUpSpaceOptimised(s , p , m , n))
    {
        cout<<"string P matches entire string S"<<endl;
    }else{
        cout<<"string P does not matches string S"<<endl;
    }
 
    return 0 ;
}