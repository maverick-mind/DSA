class Solution {
public:

// same as o-matching on at-coder : but here nums1[i] can be compatible with all the elements of nums2 from [0...n] , you can paired only those element of nums2 which are not yet paired with any element of nums1 

    int fxnTopDown(vector<int>& nums1, vector<int>& nums2 , int i , int & n , int bitmask , vector<vector<int>> & dp)
    {
        // state : dp[i][bitmask] represents the minimum XOR sum of two arrays from [i...n]

        // base case 
        if(i == n) // 
        {
            return dp[n][bitmask] = 0 ; // if there is no element left in both nums1 and nums2 , then minimum difference would be : 0
        }
        
        // lookups 
        if(dp[i][bitmask] != -1)
        {
            return dp[i][bitmask] ;
        }


        // recurrence relation 

        int ans = INT_MAX ;

        // from i to n , which element we can pair from nums2 to XOR with nums1[i]

        for(int j = 0 ; j < n ; j++)
        {
            if((bitmask & (1 << j)) == 0)
            {
                ans = min(ans , (nums1[i] ^ nums2[j]) + fxnTopDown(nums1 , nums2 , i + 1 , n , bitmask ^ (1 << j) , dp)) ;
            }
        }

        return dp[i][bitmask] = ans ;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        
        // rearrangement of nums2 means we can pair different nums2[i] with nums1[i]

        int bitmask = 0 ;
        int n = nums1.size() ;

        vector<vector<int>> dp(n+1 , vector<int>(1 << n , -1)) ;

        return fxnTopDown(nums1 , nums2 , 0 , n , bitmask , dp) ;

    }
};