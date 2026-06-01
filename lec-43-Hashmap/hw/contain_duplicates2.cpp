class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , int> mp ; // <val , most rightward index of val till now>

        // hash map + latest occurrence tracking solution, agar i - mp[nums[i]] > k hai then 
        // for that value nume[i] , usska right most index ko update kar do ,
        // so that next time i - mp[nums[i]] ki smallest value mile 
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++)
        {
            if(mp.find(nums[i]) == mp.end()) // that element appearing for the first time
            {
                mp[nums[i]] = i ;
            }else {
                if(i - mp[nums[i]] <= k) return true ;
                else{
                    mp[nums[i]] = i ; 
                }
            }
        }

        return false ;
    }
};