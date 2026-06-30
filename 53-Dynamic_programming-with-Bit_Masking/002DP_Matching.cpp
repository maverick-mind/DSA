#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>

// in dp with bitmask , we generally avoid bottomUp , because most of our states are invalid , so to avoid iterating those invalid states , we avoid bottomUp approach , where as in topDown , the recursive solution will make sure , we would never go to invalid states  


// 1e9 means the value 10^9 = 1,000,000,000, which fits inside an int
// but, in C++, the literal syntax 1e9 is defined to be a floating-point literal, so its type is double by default. also , Any literal written in scientific notation (using e or E) is a floating-point literal by default in cpp 

const int MOD = 1000000000 + 7 ; 
// time : O(n * n!) : if every woman is copatible with every man , 1st man has n choices , 2nd man has (n-1) choices , 3rd man has (n-2) choices and so on....
// space O(n) : due to function call stack
int fxnRec(vector<vector<int>> & compatible , int i , int n , int & bitmask)
{
    // base case 
    if(i == n) return 1 ; // one valid matching is formed OR all n men get a woman for them OR successfully matched all n men


    // recurrence relation 

    int ans = 0 ;

    // choices available from [1...n] women 


     // is jth women compatible with ith man : we can check compatibility from compatible[][]
     // is she single or taken till we reach ith man : for this , we need bitmasking 

    for (int j = 0; j < n; j++) // is jth women compatible with ith man
    {                           // and till now is she single or taken 
        if(compatible[i][j] == 1)
        {
            // check the jth bit of the bitmask : if it is 0 , she is available to make a bond 
                                                // if it is 1 , she is already taken 
            int isAvail = bitmask & (1 << j) ; 
            if(isAvail == 0) // she is available to make a bond with the ith man 
            {
                // make the bond by fliping the jth bit 
                bitmask = bitmask ^ (1 << j) ; // bond formed 
                ans += fxnRec(compatible , i + 1 , n , bitmask);
                // ans %= (1e9 + 7) ; // 1e9 is double , ans is int , so error int/double
                ans %= MOD ;
                bitmask ^= (1 << j) ; // backtracking ,break the bond with this woman ,  to explore other women available to make bond 
            }
        }
    }

    return ans ;
}

// for n ~ 25 , 2^n solution is accepted 

// time : O(2^n * n) :(2^n unique subproblems) * (n (work done inside loop per unique subproblems)) : not n*(2^n) * n because i and bitmask are not 2 independent parameter , for i = 0 , there are zero number of setbits(1) in the bitmask
// for i = 1 , there is one number of setbits in the bitmask
// for i == n , there is n set bits in the bitmask
// so we can do parameter optimization because i and bitmask are not 2 indepened parameter , so you can optimise your space from dp[n][bitmask] : 2D dp to dp[bitmask] : 1D dp
// space : O(n*(2^n)) or O(n*(1<<n)) : number of dp states 
int fxnTopDown(vector<vector<int>> & compatible , int i , int & n , int & bitmask , vvi & dp)
{
    // state : dp[i][bitmask] stores the number of valid ways to match
    // men from i to n-1 using the currently available women
    // (whose bits are 0 in bitmask).

    // base case : when no more men left for pairing , i.e. : i == n . OR when no more woman left for pairing , i.e. bitmask == 2^n - 1
    if(i == n)// one valid matching is formed OR all n men get a woman for them 
    { // OR successfully matched all n men
        // we can also use : if(bitmask == (1 << n) - 1) // when all the women are paired with all the man , uniquely , it will happen when all the bits of bitmask is set to : 1
         return dp[i][bitmask] = 1 ; // it means we have build a valid permutation 
    } 


    // lookups 
    if(dp[i][bitmask] != -1) return dp[i][bitmask] ;


    // recurrence relation 
    int ans = 0 ;

    // choices available from [1...n] women 


     // is jth women compatible with ith man : we can check compatibility from compatible[][]
     // is she single or taken till we reach ith man : for this , we need bitmasking 

    for (int j = 0; j < n; j++) // is jth women compatible with ith man
    {                           // and till now is she single or taken 
        if(compatible[i][j] == 1)
        {
            // check the jth bit of the bitmask : if it is 0 , she is available to make a bond 
                                                // if it is 1 , she is already taken 
            int isAvail = bitmask & (1 << j) ; 
            if(isAvail == 0) // she is available to make a bond with the ith man 
            {
                // make the bond by fliping the jth bit 
                bitmask = bitmask ^ (1 << j) ; // bond formed 

                ans = (ans % MOD + fxnTopDown(compatible , i + 1 , n , bitmask , dp)% MOD)% MOD;
                // (a+b)% c = (a%c + b%c)%c

                // ans += fxnTopDown(compatible , i + 1 , n , bitmask , dp);
                // ans %= (1e9 + 7) ; // 1e9 is double , ans is int , so error int/double
                // ans %= MOD ;

                bitmask ^= (1 << j) ; // backtracking ,break the bond with this woman ,  to explore other women available to make bond 
            }
        }
    }
    return dp[i][bitmask] = ans ; // memoization before returning 
}


// time : O(2^n * n)
// space : O(n)

// i and number of setbits in bitmask are same , so they are not independent variable , so we can solve this problem using 1D DP only 

// space optimised solution 
int fxnTopDownparameterOptimised(vector<vector<int>> & compatible, int & n, int & bitmask, vector<int> & dp)
{
    if(bitmask == (1 << n) - 1) // all women taken => valid matching formed
        return dp[bitmask] = 1;

    if(dp[bitmask] != -1) return dp[bitmask];

    int i = __builtin_popcount(bitmask); // current man index, derived not stored
    int ans = 0;

    for(int j = 0; j < n; j++)
    {
        if(compatible[i][j] == 1)
        {
            int isAvail = bitmask & (1 << j);
            if(isAvail == 0)
            {
                bitmask ^= (1 << j);
                ans = (ans % MOD + fxnTopDownparameterOptimised(compatible, n, bitmask, dp)% MOD) % MOD;
                bitmask ^= (1 << j);
            }
        }
    }
    return dp[bitmask] = ans;
}
 
 
int main() 
{
    int n ; // n-Men and n-women
    cin>> n ;
    vector<vector<int>> compatible(n , vector<int>(n)) ; 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>compatible[i][j] ;
        }
    }

    // make men as domain and women as range 
    // one man will pick from total available choices from 'n' women
    int bitmask = 0 ;
    // cout<<fxnRec(compatible , 0 , n , bitmask)<<endl ; 

    // vvi dp(n+1 , vector<int>(1 << n , -1)) ; 
    // i can go from [0...n] , bitmask can go from [all zero.....all ones] i.e. 2^n possible bitmask 
    // total unique subproblems : [n+1]*[2^n]
    // cout<<fxnTopDown(compatible , 0 , n , bitmask , dp) ;

    vector<int> dP(1 << n , -1) ;
    cout<< fxnTopDownparameterOptimised(compatible , n , bitmask , dP) ;

    return 0 ;
}