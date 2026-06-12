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


// kam se kam "mid" value of dollars par k houses chori karna hai 
// and wo saare 'k' houses consecutive nahi hona chahiye
bool predicate_fxn(vector<int>& nums, int k , int mid)
{
    int countRobbedHouses = 0 ;
    int maxRobbedSoFar = 0 ;
    int minOfAllHisCapabilities ;
    for (int i = 0; i < nums.size(); i++)
    {  int countRobbedHouses = 0 ;
        for (int j = i+2; j < nums.size(); j++)
        {
            countRobbedHouses++;
            
            
        }
    }
}



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