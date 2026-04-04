#include<bits/stdc++.h>
using namespace std;
 
vector<int> TargetSumPairs(vector<int>nums , int target)
{
    vector<int> ans ;
    sort(nums.begin() , nums.end());
    int i = 0  , j = nums.size()-1;
    while(i < j)
    {
        if( i != 0 and nums[i] == nums[i-1]) // to avoid multiple pairs of repeated element
        {
            i++;
            continue ;
        } 

        if(nums[i] >= target) break ;

        if(nums[i] + nums[j] == target) {
            ans.push_back(nums[i]) ; 
            ans.push_back(nums[j]) ; 
            i++;
            j--;
        } 
        else if(nums[i] + nums[j] < target)
        {
            i++;
        }
        else if(nums[i] + nums[j] > target)
        {
            j--;
        }
        
    }

    return ans ;
}
 
int main() 
{
     vector<int> nums = {2,2,2,3,4,5,5,5,5,6,7,8};
    int target = 10 ;

    vector<int> ans = TargetSumPairs(nums , target);

    for (int i = 0; i < ans.size(); i++)
    {
       cout<<ans[i]<<" ";       
    }
    return 0 ;
}