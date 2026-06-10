class Solution {
public:
// ans1 = solve house robber 1 by ignoring the last house in the street 
// ans2 = solve house robber 1 by ignoring the starting 0th house in the street
// two seperate dp vector needed , because dp vector is passed by refrence 
// final answer would be : max(ans1 , ans2)
    int fxnTopDown(vector<int>& nums, int i, int n, vector<int>& dp) {
        // state : // dp[i] will store maximum money that can be earned starting
        // from house i till n-1 OR dp[i] = answer for the subarray [i ... n-1]

        // base case
        if (i >= n)
            return 0; // no-point of robbing house , that does not exist in the
                      // street

        // lookups
        if (dp[i] != -1) {
            return dp[i];
        }

        // recurrence relation
        // theif has choice , either he can choose current ith house and then he
        // would only be able to (i+2)th house OR he can ignore this house and
        // rob (i+1)th house

        int wealthCreatedByRobbingCurrentHouse = 0;
        int wealthCreatedByNOTRobbingCurrentHouse = 0;

        // if robbing current ith house , then moving to (i+2)th house
        wealthCreatedByRobbingCurrentHouse =
            nums[i] + fxnTopDown(nums, i + 2, n, dp);

        // if skipping current ith house to rob (i+1)th house
        wealthCreatedByNOTRobbingCurrentHouse = fxnTopDown(nums, i + 1, n, dp);

        // memoization before return
        return dp[i] = max(wealthCreatedByRobbingCurrentHouse,
                           wealthCreatedByNOTRobbingCurrentHouse);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 ) return nums[0];
        vector<int> dp1(n - 1 , -1);
        int ans1 = fxnTopDown(nums , 0 , n - 1 , dp1) ; // ignore the last house
        vector<int> dp2(n , -1);
        int ans2 = fxnTopDown(nums , 1 , n , dp2) ; // ignore the starting house

        return max(ans1 , ans2);
    }
};