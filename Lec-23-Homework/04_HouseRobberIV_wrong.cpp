// https://leetcode.com/problems/house-robber-iv/description/

#include<bits/stdc++.h>
using namespace std;
 
/*
Define the bounds :
Lower Bound : agar 1 hi ghar ho , aur uss ghar mein 1 dollar padaa ho , then maximum he can rob would be 1 
so , start = 1 

Upper Bounds : he can rob maximum element in the array "nums"
               maximum element that exists in array "nums"
               so , end = *max_element(nums.begin() , nums.end());
*/

bool predicate_fxn(vector<int>& nums, int k , int mid)
{
    int ans = INT_MAX ; // final answer hoga minimum capability of the robber out of all the possible ways to steal at least k houses.
    // but change the statement
    // we are intresed in checking 
    // ki out of all combinations of houses he robbed , his capacity is the maximum amount of money in 1 of all those houses 
    // and we have to return minimum of all the maximums of his capabilities 
    // so we will check that , minimum of all those capabilities is more than "mid" value or not 
    
    // is ans >= mid amount of money , if yes return true , else false 
    // kya  ans (minimum of all of uss ke maximum capabilities) is greater than or equals to "mid" value or not , if he robs at least 'k' houses
    
    for (int i = 0; i < nums.size()-k; i++)// we cannot do , this , 2 loop here will cause TLE , what we can do is , calculate max value of nums array in to another array , like suffix sum , and then calculate maxRobberSoFar in O(1) time
    { int maxRobbedSoFar  ;
      for (int j = k; j < nums.size(); j++)
      {
        maxRobbedSoFar = max(nums[i] , nums[j]);  
      } ans = min(ans , maxRobbedSoFar) ; 
    }

    return ans >= mid ; // 
}

// bool predicate_fxn(vector<int>& nums, vector<int>& meakifi, int k , int mid)
// {
//     int ans = INT_MAX ; 
//     int maxRobbedSoFar  ;
//     for (int i = 0; i < nums.size() - 1; i++)
//     {
//         maxRobbedSoFar = max(nums[i] , meakifi[i+2]);
//         ans = min(ans , maxRobbedSoFar);
//     }
//     // return ans >= mid ;
//     return mid <= ans ; // agar "mid" chhota hai ans se , matlab minimum of all of his "max capabilities" i.e. ans is more than "mid" value
// }

int minCapability(vector<int>& nums, int k) {

    

    int start = 1 ;
    int end = *max_element(nums.begin() , nums.end());
    int ans ;

    // precalculate max element in suffix manner 
    vector<int> meakifi(nums.size(),0);// max element after k index from i 
    // meakifi[nums.size()-1] = nums[nums.size()-1];
    // for (int i = nums.size()-2; i >= 0 ; i--)
    // {
    //     meakifi[i] = min(meakifi[i+1] , nums[i]);
    // }
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout<<meakifi[i]<<" ";
    // }cout<<endl;

    while(start <= end)
    {
        int mid = start + (end - start)/2 ;
        
        if(predicate_fxn(nums  , k , mid))
        {                   // agar mid dollar wo chori
                            // kar paa rha hai , to mid se kam hi 
                            // kar paayega chori
            ans = mid ;
            start = mid + 1 ;
        }
        else
        {   
            end = mid - 1 ;
        }
    }
    return ans ;
}
 
int main() 
{   
    vector<int> nums = {2,3,5,9};// ith house has nums[i] dollars 
    int k = 2 ;//k represents the minimum number of houses the robber will steal from.

    cout<<minCapability(nums , k);
    
 
 
 
    return 0 ;
}