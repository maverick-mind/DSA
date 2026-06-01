#include<bits/stdc++.h>
using namespace std ; 
// question : sum of 3 elements equal to 0 
// Time : sorting + finding 3sum --> nlog(n) + n^2 ~ O(n^2)
vector< vector<int> > threeSum(vector<int> & nums)
{
    vector< vector<int> > ans ;
    int n = nums.size();
    sort(nums.begin() , nums.end());

    // iterate over all the possible values of first element
    for (int i = 0; i <= n-3; i++)
    {
        if(nums[i] > 0) break ; // agar sorted array mein pahla element hi 0 se badaa hai , then no triplet ahead is possible with sum = 0


        // can you fix num[i] as the firts element , check first 
        if(i > 0 and nums[i] == nums[i-1]) continue;

        // fix nums[i] as the 1st element of the triplet 
        // now , search for the pair nums[j] , nums[k] int [i+1....n-1]
        // such that nums[j] + nums[k] == -nums[i]


        int t = -nums[i];
        int j = i + 1 ;
        int k = n - 1 ;

        while(j < k)
        {
            int pair_sum = nums[j] + nums[k];
            if( pair_sum == t)
            {                              
              ans.push_back({nums[i] , nums[j] , nums[k]});
                j++ ;
                k--;
                 // to remove duplicate triplet in sorted array 
                 while(j < k and nums[j] == nums[j-1]) j++;
                 while(j < k and nums[k] == nums[k+1]) k--;
            }

            else if( pair_sum > t){ 
                // jab (nums[j] + nums[k]) badaa hoga t se then k-- , as jth aur kth element ka sum bhi badaa hai t se aur kth element badaa hai jth se , sorted vector mein 
                k--;
            }
            else{ // pair_sum < t 
                // isska matlab jth aur kth element ka sum t se chhota hai , so hum j++ karenge taaki hum t ke kareeb pahuchee , as sum chhhota hai jth aur kth element ka , aur jth element chhota hai kth element se sorted array mein 
                j++ ;
            }
            
        }
    }
        return ans ;
}

int main() 
{
    vector<int> nums = {-1 , 0 , 1 , 2 , -1 , -4} ;

    vector< vector<int> > ans = threeSum(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
        
    }
    return 0 ;
}