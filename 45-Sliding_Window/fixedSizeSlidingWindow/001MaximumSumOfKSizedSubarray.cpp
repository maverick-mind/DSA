// fixed size sliding window
// variable size sliding window

// window means : SubArray

#include <bits/stdc++.h>
using namespace std;

int fxn(const vector<int> & nums , int k)
{
    int n = nums.size() ; 
    
    int currentWindowSum = 0 ; 

    // sum of first k-size subarray / k-size window 
    for(int i = 0 ; i < k ; i++) currentWindowSum += nums[i];
    int maxWindowSum = currentWindowSum ;

    // to get maximum sum among all subarray of k size , now move the window rightward , till you reach the last subarray , or the last element of the window reaches the last element of the vector 
    for(int startIdx = 1 ; startIdx <= n - k ; startIdx++) // if 'i' is the starting of the fixed size sliding window
    {
         currentWindowSum = currentWindowSum - nums[startIdx-1] + nums[startIdx+(k-1)];
        maxWindowSum = max(currentWindowSum , maxWindowSum) ; 
    }

    // for(int endIdx = k ; endIdx < n ; endIdx++)/ if 'i' is the ending of the fixed size sliding window
    // {
    //     currentWindowSum = currentWindowSum - nums[endIdx-k] + nums[endIdx];
    //     maxWindowSum = max(currentWindowSum , maxWindowSum) ; 
    // }

    return maxWindowSum ; 

}

int main()
{
    vector<int> nums = {1, 4, 2, 7, 6, 3, 5};
    int k = 4 ;

    cout<<fxn(nums , k);

    return 0;
}