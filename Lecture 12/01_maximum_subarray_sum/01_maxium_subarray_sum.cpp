// prefix sum
// prefix (subarray that starts at 0 index , khatam kahi bhi ho sakta hai)
// suffixes (subarrays that end at the last index , shuru kahi bhi ho sakta hai )

#include<iostream>
#include<climits>
using namespace std ; 

// time : n + n^2 ~ O(n^2)
// space : O(n) due to prefix_sum array 
int maximumSubarrayPrefixSum(int arr[] , int n)
{
// first step is to calculate the prefix sum 
// prefixSum[i] = sum (arr[0] to arr[i-1])
// prefixSum[i] = prefixSum[i-1] + arr[i-1];

    int prefix_sum[n+1];
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        prefix_sum[i] = prefix_sum[i-1] + arr[i-1];
    }

  
    int max_soFar = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      
       int sum = 0 ; 

        for (int j = i; j < n; j++)
        {
            sum = prefix_sum[j+1] - prefix_sum[i];
            // sum of ith element to jth element is : prefix_sum[j+1] - prefix_sum[i]
            max_soFar = max(max_soFar , sum);
        }
        
    }
    
        return max_soFar;
}
 
 
int main() 
{
    int arr[] = { -2 , 1 , -3 , 4 , -1 , 2 , 1 , -5 , 4};

    int n = sizeof(arr)/sizeof(arr[0]);

   cout<< maximumSubarrayPrefixSum(arr , n)<<endl;
 
    return 0 ;
}