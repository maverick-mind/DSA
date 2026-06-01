#include<bits/stdc++.h>
using namespace std ; 

// Time ; O(n)
vector<int> TargetSumPairs(vector<int>& nums, int target) {
        // sort the array first to use below while loop in O(n)
        // don't sort if original index of the pair is asked 
        sort(nums.begin() , nums.end());
        int i = 0 ;
        int j = nums.size() - 1 ;

        vector<int> ans ;

        while(i < j)
        {
            if(nums[i] > target) break ;// agar ith waala target se badaa ho gya sorted array mein to jth waala bhi target se badaa hoga , so no need to check after nums[i] > target 

            if(nums[i] + nums[j] == target) 
            {
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                i++ ;
                j--;
            }
            else if(nums[i] + nums[j] < target)
            {
                i++ ;
            }
            else{ // nums[i] + nums[j] > target
                j--;
            }
        }
        return ans ;
}
 
 
int main() 
{
    vector<int> nums = {3,2,4};
    int target = 6 ;

    vector<int> ans = TargetSumPairs(nums , target);

    for (int i = 0; i < ans.size(); i++)
    {
       cout<<ans[i]<<" ";       
    }
    
    return 0 ;
}