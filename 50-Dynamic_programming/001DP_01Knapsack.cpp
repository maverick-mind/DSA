#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

// at any point of time , we have an item in front of us , we have 2 choices 
// either to include that item in our bag , if bag capacity permits 
// or to exclude that item and move ahead to have future choice to pick 
// time : O(2^n) due to each i has 2 choices include or exclude 
// space : O(n) due to fxn call stack
int fxnRec(vi & weights , vi & prices , int i , int capacity , int occupiedWeight)
{
    // base case 
    if(occupiedWeight > capacity) return 0 ; // we cannot put this much weight in our knapsack
    if(i >= weights.size()) return 0 ;

    
    // recurrence relation 
    int amountInclude = 0 ; // profit created by including current weight 
    // choice : either to include current ith item or exclude current item 
    if(occupiedWeight + weights[i] <= capacity)
    {
        occupiedWeight += weights[i] ; 
        amountInclude = prices[i] ; 
      
        amountInclude += fxnRec(weights , prices , i + 1 , capacity , occupiedWeight) ;
        occupiedWeight -= weights[i] ; // backtracking 
    
    }
    
    // profit created by excluding current weight 
    int amountExclude = 0 ;
    amountExclude += fxnRec(weights , prices , i + 1 , capacity , occupiedWeight);
    

    return max(amountInclude , amountExclude);
}


/*
                    item i
                   /      \
             include     exclude
               /            \
          solve(...)     solve(...)

*/

// time : (N + 1)*(capacity + 1) for Dp table , O(N) for recursion call stack :  O(N*capacity)
// space : N due to fxn call stack + N*(capacity +1) ~ O(N*capacity)
int fxnTopDown(vi & weights , vi & prices , int i , int capacity , vector<vi> & dp)
{
    // state : dp[i][availCapacity of knapsack] : stores the maximum profit made from ith weight(either included or excluded) to the last weight ,  for the avaibale capacity of the knapsack
    // base case 
    if(capacity == 0) return dp[i][capacity] = 0 ; // if capacity of knapsack is : 0 , maximum profit would be : 0
    if(i >= weights.size()) return dp[i][capacity] = 0 ; // no more items left to put in the knapsack 



    // lookups
    if(dp[i][capacity] != -1) return dp[i][capacity];
    
    // recurrence relation 
    int amountInclude = 0 ; // profit created by including current weight 
    // choice : either to include current ith item or exclude current item 
    if((capacity - weights[i]) >= 0)
    {
        capacity -= weights[i] ; 
        amountInclude = prices[i] ; 
      
        amountInclude += fxnTopDown(weights , prices , i + 1 , capacity , dp) ;
        capacity += weights[i] ; // backtracking 
    
    }
    
    // profit created by excluding current weight 
    int amountExclude = 0 ;
    amountExclude += fxnTopDown(weights , prices , i + 1 , capacity , dp);
    

    // memoization
    dp[i][capacity] = max(amountInclude , amountExclude) ;

    return dp[i][capacity];
}

int fxnBottomUp(vi & weights , vi & prices , int & capacity)
{
    int N = weights.size() ;
    int W = capacity ;
    vector<vector<int>> dp(N+1 , vector<int>(W+1 , 0)) ; // initialised with 0 so that we don't have to handle base case in the for loop manually 

    for(int i = N-1 ; i >= 0 ; i--)
    {
        for(int w = 1 ; w <= W ; w++)
        {
            // if you cannot pick the ith item , when w + weight[i] exceeds knapsack capacity 
            if(weights[i] > w)
            {
                dp[i][w] = dp[i+1][w];
            }else if(weights[i] <= w)
            {
                dp[i][w] = max(prices[i] + dp[i+1][w-weights[i]] , dp[i+1][w]);
            }
        }
    }
    return dp[0][capacity];
}

// at any time we need only two 1D DP , because at any time when we are filling ith row , we need just (i+1)th row , so we need dpForCurrentRow[] , dpForBelowRow[]
// when both dpUp[] and dpBelow[] is filled completely , now we have to move one row up , so we dont' need this current dpBelow[] ;
// so , copy dpUp[] in dpBelow[] and empty dpUp[] and thus we can keep doing this for every row from bottom to up while filling dp 
int fxnBottomUpSpaceOptimised(vi & weights , vi & prices , int & capacity)
{
    int N = weights.size();
    int W = capacity ;

    vector<int> dpUp(W + 1);
    dpUp[0] = 0 ; // when weight == 0 ; maximum profit would be zero 
    vector<int> dpBelow(W+1 , 0); // initialised with 0 because , in 2-D dp , when i == N , bottomMost row was initialised with 0

    for(int i = N-1 ; i >= 0 ; i--)
    {
        for(int w = 1 ; w <= W ; w++)
        {
            if(weights[i] <= w) // if two choices of inclusion and exclusion are posible 
            {
                dpUp[w] = max(prices[i] + dpBelow[w-weights[i]] , dpBelow[w]);
            }
            else if(weights[i] > w)
            {
                dpUp[w] = dpBelow[w] ; 
            }
        }
        // now dpUp[] will become dpBelow[] for above row 
        dpBelow = dpUp ; 
        // you can clear dpUp now , but we are assigning in dpUp , so it would not affect , even if we don't clear , so just leave it 
    }
    return dpUp[capacity] ; // or dpBelow[capacity] as dpUp is the result of last iteration and dpBelow is ht ecopy of dpUp , won't be any difference 
}

// time : O(NW)
// space : O(W)
int fxnBottomUpSpaceOptimisedSingle1DVector(vi & weights , vi & prices , int & capacity)
{
    int N = weights.size();
    int W = capacity ;

   
    vector<int> dp(W+1 , 0); // initialised with 0 because , when starting out we will fill (N-1)th row , to fill this , we need we need Nth row , and Nth row is base case , where all elements are 0 

    for(int i = N-1 ; i >= 0 ; i--)
    {
        for(int w = W ; w >= 1 ; w--) // every element depends on w or some w-weights[i] ,
        {   //  so by the time we need (w-weights[i]) , (w-weights[i]) must not be modified ,
            // so start filling from right to left , not left to right 
            if(weights[i] <= w) // if two choices of inclusion and exclusion are posible 
            {
                dp[w] = max(prices[i] + dp[w-weights[i]] , dp[w]);
            }
            // else if(weights[i] > w)
            // {
            //     dp[w] = dp[w] ; 
            // }
        }
    }
    return dp[capacity] ; 
}

// time : O(NW)
// space : O(W)
int fxnBottomUpSpaceOptimisedSingle1DVectorAnd0thRowOptimisation(vi & weights , vi & prices , int & capacity)
{
    int N = weights.size();
    int W = capacity ;

   
    vector<int> dp(W+1 , 0); // initialised with 0 because , when starting out we will fill (N-1)th row , to fill this , we need we need Nth row , and Nth row is base case , where all elements are 0 

    // we are filling bottom to top and right to left and in the end we are returning dp[capacity]
    // for 0th row , once dp[capacity] is filled , no need to fill any other cell in the left , as no point to calculate maximum profit we can make for smaller capacity of knapsack
    for(int i = N-1 ; i >= 1 ; i--) 
    {
        for(int w = W ; w >= 1 ; w--) // every element depends on w or some w-weights[i] ,
        {   //  so by the time we need (w-weights[i]) , (w-weights[i]) must not be modified ,
            // so start filling from right to left , not left to right 
            if(weights[i] <= w) // if two choices of inclusion and exclusion are posible 
            {
                dp[w] = max(prices[i] + dp[w-weights[i]] , dp[w]);
            }
            // else if(weights[i] > w)
            // {
            //     dp[w] = dp[w] ; 
            // }
        }
    }
    
    if(weights[0] <= capacity)
    {
        // equivalent to 2d dp of dp[0][capacity]
        dp[capacity] = max(prices[0] + dp[capacity-weights[0]] , dp[capacity]); // instead of doing 0th row work , alag se nikaal lo dp[capacity]
    }
    
    return dp[capacity] ; 
}

int main()
{
    vector<int> weights = {1, 2, 3, 2, 2};
    int n = weights.size();
    vector<int> prices = {8, 4, 1, 5, 3};

    int capacity = 4 ; // maximum weight capacity is 4kg
    int occupiedWeight = 0 ;

    cout<<fxnRec(weights , prices , 0 , capacity , occupiedWeight)<<endl;

    vector<vector<int>> dp(n+1 , vector<int>(capacity + 1 , -1)) ; 
    cout<<fxnTopDown(weights , prices , 0 , capacity , dp)<<endl;
    cout<<fxnBottomUp(weights , prices , capacity)<<endl;
    cout<<fxnBottomUpSpaceOptimised(weights , prices , capacity)<<endl;
    cout<<fxnBottomUpSpaceOptimisedSingle1DVector(weights , prices , capacity)<<endl;
    cout<<fxnBottomUpSpaceOptimisedSingle1DVectorAnd0thRowOptimisation(weights , prices , capacity)<<endl;

    return 0;
}