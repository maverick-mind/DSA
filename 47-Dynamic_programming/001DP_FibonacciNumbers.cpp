
/*
Changing variables in normal recursive function = dimensions of dp . Dependent variable hai toh reduce karo, independent hain toh nahi
*/ 

// if we don't know , how many unique sub-problems can be there , then we can't use array as a map for dp
// we can use array as a map for dp questions , only when there is ONE-TO-ONE mapping between PARAMETERs(n) and INDICES OF ARRAY , number of parameter will decide the dimension of dp vector

// if parameter is string like something then we have to use map container INSTEAD of array
// to use dp vector : parameter 'n' has to be integer , and not to be a very big integer
// or if the n(parameter) is very large number , for ex. 10^9 , we can't create an array of this much size ; for ex , if asked 10^10th fibinacci number , for that we need to go to 10^10th index of array , if array is used , but creating arry of this size can't be possible

// also when n can be negative (can't index array with negative). Use map in that case too

// max array size for array of int type you can create on platform like leetcode or codeforces :
// ~10^7 or 1e7 (at max) above it , can exceed memory limit  

// recursive case is expensive if there are repeated same sub-Problems , that is why we use DP
/*
In top down approach , START from the original problem and move towards the base case 
define inside the recursive function 
// state: dp[i] means ...

// base case

// lookup (if answer to this sub-problem exist in dp[]) 

// recurrence relation

// insert in dp(memoization)

return
*/
// solve karne se pahle check dp (lookup) , return karne se pahle store (memoize)
/*
template for top-down approach 

// state: dp[i] means ...

// base case 

// lookups 

// recurrence relation 

 // memoize 

return 
*/


#include<bits/stdc++.h>
using namespace std;
 
// time : O(2^n) : assume the recursion call tree is a perfect binary tree , count nodes on each level , total nodes in tree : 2^n and for each call stack , we are doing constant work 
// thus : time complexity : O(2^n)
// space : O(n) : maximum functional call stack frames would be same as height of recursion tree
int count1 = 0 ; // to track how much times function f is called 
int f(int n)
{
    count1++;
    // base case 
    if( n == 0 or n == 1) return n ;

    // recurrence relation 
    return f(n-1) + f(n-2);
}
 

// top-down DP :  START from the original problem and move towards the base case 
// step 1 : find out number of UNIQUE sub-Problems , because saari unique sub-problems ka result hum array mein store karenge and , to array ka size define karna padega , and size of array will depend upon number of UNIQUE sub-problems 

// step 2 : initialise the dp array with value , which can never be the valid answer 

// step 3 : kisi bhi sub-Problem(question) ko solve karne se pahle check kar lo , kya wo question pahle solve kiya hai ya nahi : agar questions pahle solve kiya hai to RESULT ko REUSE kar lo , agar question ko solve nahi kiya then solve karna padega , and solve kar ke jab result ko return karenge , uss se pahle dp mein save kar lo , because same sub-Problem future mein bhi encounter kar sakte hai 


// step 1 : for fibonacci of n : 0 to n : we have (n + 1) unique subProblems : dp.size() = n + 1 
// dp[i] will store result of f(i)
// step 2 : initialise dp with -1  



// time : O(n)
// space : O(n) ~2n (n function call stack , n size dp array)
// to check how much we have optimisation we have done with the help of dp 
int count2 = 0 ; // to track how many times fxnTopDown is called 
int fxnTopDown(int n , vector<int>& dp)
{
    count2++;
    // state : dp[i] will store fxnTopDown(i , dp) value
    
    // base case
    if(n == 0 or n == 1)
    {
        if(dp[n] == -1) // lookups
        {
            dp[n] = n ; // memoize
        }       
        return dp[n];
    }

    // lookups : if the sub-Problem is allready solved 
    if(dp[n] != -1)
    {
        return dp[n];
    }

    // recurrence relation 
    dp[n] = fxnTopDown(n-1 , dp) + fxnTopDown(n-2 , dp); // recurrence relation + memoization 

    return dp[n];
}

// bottom-Up ; iterative 
// decide dp ko kis order mein fill kare : either (left to right) or (right to left) 
int fxnBottomUp(int n)
{
    vector<int> dp(n+1) ; // no need to initialise , as we don't need lookups here    
    dp[0] = 0 ;
    dp[1] = 1 ;
    for(int i = 0 ; i <= n ; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() 
{
    int n = 25; 


    vector<int>dp(n+1 , -1);// n + 1 size , initialize all elements with -1(will help in lookups)
    cout<<fxnTopDown(n , dp)<<endl;

    cout<<f(n)<<endl;

    cout<<"count1 :"<<count1<<endl<<"count2 :"<<count2<<endl;

 
    return 0 ;
}