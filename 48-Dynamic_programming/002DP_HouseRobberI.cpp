#include<bits/stdc++.h>
using namespace std;


int fxnRec(vector<int> & nums , int i , int n)
{

    // base case 
    if(i >= n) return 0 ; // no-point of robbing house , that does not exist in the street
    

    // recurrence relation 
    // theif has choice , either he can choose current ith house and then he would only be able to (i+2)th house 
    // OR he can ignore this house and rob (i+1)th house 

    int wealthCreatedByRobbingCurrentHouse = 0 ; 
    int wealthCreatedByNOTRobbingCurrentHouse = 0 ;

    // if robbing current ith house , then moving to (i+2)th house 
    wealthCreatedByRobbingCurrentHouse = nums[i] + fxnRec(nums , i + 2 , n) ; 

    // if skipping current ith house to rob (i+1)th house
    wealthCreatedByNOTRobbingCurrentHouse = fxnRec(nums , i + 1 , n) ; 

    return max(wealthCreatedByRobbingCurrentHouse , wealthCreatedByNOTRobbingCurrentHouse);
}

int fxnTopDown(vector<int> & nums , int i , int n , vector<int> & dp)
{
    // state : // dp[i] will store maximum money that can be earned starting from house i till n-1
    // OR dp[i] = answer for the subarray [i ... n-1]

    // base case 
    if(i >= n) return 0 ; // no-point of robbing house , that does not exist in the street
    

    // lookups
    if(dp[i] != -1)
    {
        return dp[i];
    }

    // recurrence relation 
    // theif has choice , either he can choose current ith house and then he would only be able to (i+2)th house 
    // OR he can ignore this house and rob (i+1)th house 

    int wealthCreatedByRobbingCurrentHouse = 0 ; 
    int wealthCreatedByNOTRobbingCurrentHouse = 0 ;

    // if robbing current ith house , then moving to (i+2)th house 
    wealthCreatedByRobbingCurrentHouse = nums[i] + fxnTopDown(nums , i + 2 , n , dp) ; 

    // if skipping current ith house to rob (i+1)th house
    wealthCreatedByNOTRobbingCurrentHouse = fxnTopDown(nums , i + 1 , n , dp) ; 

    // memoization before return 
    return dp[i] = max(wealthCreatedByRobbingCurrentHouse , wealthCreatedByNOTRobbingCurrentHouse);
}
 
// time : O(n)
// space : O(n)
int fxnBottomUp(vector<int> & nums)
{
    // in this question : state in topDown and bottomUp are different , just direction is different
    //  state feels different from topDown but it's actually the same problem, just traversal direction flipped. TopDown goes i → n, bottomUp goes 0 → i
    // state :  // dp[i] = maximum money that can be robbed starting from house 0 and ending at house i
    int n = nums.size() ;
    if(n == 1) return nums[0];
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0] , nums[1]);

    for(int i = 2 ; i < n; i++)
    {
        dp[i] = max(dp[i-1] , (nums[i] + dp[i-2]));
    }

    return dp[n-1];

}

// O(1) space instead of O(n). Same logic, no dp array needed
// at a time we need only 2 things : dp[i-1] and dp[i-2]
int fxnBottomUpSpaceOptimised(vector<int> & nums)
{   
    int n = nums.size() ;
    if(n == 1) return nums[0];
    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);

for(int i = 2; i < n; i++) {
    int curr = max(prev1, nums[i] + prev2);
    prev2 = prev1;
    prev1 = curr;
}

return prev1;
}
 
int main() 
{
    vector<int> nums = {2,7,9,3,1}; // nums[i] denotes amount of money in each house ; ans : 12
    // vector<int> nums = {1,2,3,1}; // ans : 4
    int n = nums.size();

    cout<<fxnRec(nums , 0 , n)<<endl; // 0 is the starting house 

    vector<int> dp(n , -1) ;// state : // dp[i] will store maximum money that can be earned starting from house i till n-1
    // OR dp[i] = answer for the subarray [i ... n-1]
 
    cout<<fxnTopDown(nums , 0 , n , dp)<<endl;
    cout<<fxnBottomUp(nums)<<endl;
 
    return 0 ;
}