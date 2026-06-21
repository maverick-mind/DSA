#include<bits/stdc++.h>
using namespace std;
 
// focus on the 1st cut only , rest recursion will handle 
// the first cut(partitioning , can be done at any index from 0 to k - 1)
// in general : the first cut can be on index j such that 0 <= j <= k - 1 
// after cut , the subarray formed is : [0....j] , and all the values in the subarray [0....j] would be replaced by the value which is MAX in the subarray , 
// and then the sum of the subarray would be : maxElement * size of subarray 
// after doing this for first cut , for the remaining array , we want to find the maximum sum we can get (this is a subproblem , handled by recursion) by doing partition such that , maximum size of the subarray is k 

// in general : fxn(i) : find the maximum sum , we can get on partitioning suffix that starts at i and goes till n - 1 (arr[i....n-1]) such that size of each subarray that is going to be created upon partitioning is : <= k, and maxValue of subarray replaces all the other of the subarray 
// to solve this , just decide where to make the next cut 

// next cut(j) choices : i <= j <= i + k - 1 
// and for this subarray sum would be (j-i+1)*(max(arr[i....j]))

// fxn(i) : (j-i+1) * maxValue(arr[i....j]) + fxn(j+1)
int fxnRec(vector<int> & arr , int n ,  int k , int i )
{
    // base case 
    if(i == n)
    {
        return 0 ; // no further subarray possible 
    }

    // recurrence relation 
    int ans = 0 ;
    int maxSubArrayElement = 0 ; 

   // each subarray could be of possible length [1....k]
   for(int currSubarraylength = 1 ; currSubarraylength <= k ; currSubarraylength++)
   {
      if(currSubarraylength == 1) maxSubArrayElement = 0 ;

      if(i + (currSubarraylength - 1) < n)
      {
        maxSubArrayElement = max(maxSubArrayElement , arr[i + (currSubarraylength - 1)]) ;

        ans = max(ans ,
            maxSubArrayElement * currSubarraylength + (fxnRec(arr , n , k , i + currSubarraylength)));
      }
      
   }
   return ans ; 
}

// jab bhi suffix/prefix partition karna ho with a window constraint, dp[i] = best over all cut points
// window max carry karo, cut decide karna, aur sahi next index pe jaana would do the work 

// time : O(n*k) : for each n element , the for look runs at max for k times 
// space : O(n) : n due to function call stack : worst case depth n ho sakti hai (jab k=1, har call sirf i+1 pe jaati hai) , n+1 due to size of dp  
int fxnTopDown(vector<int> & arr , int n ,  int k , int i , vector<int> & dp)
{
    // state : dp[i] stores maximum sum we can get by partitioning suffix that starts at i and goes till n-1 arr[i....n-1] such that size of each subarray that is going to be created upon partitioning is <= k and maxValue of subarray replaces all the other elements of the subarray 
    // to solve this , just decide where to make the next cut 
    // 

    // base case 
    if(i == n ) return dp[n] = 0 ; // no further subarray possible 

    // lookups 
    if(dp[i] != -1) return dp[i] ;

    // recurrence relation 
    // we need max element in the subarray , and a variable to compare maximum sum possible among all the different subarray possible 
    int maxSubArrayElement = INT_MIN;
    int currentSubarrayMaxSumAndSuffixSubarraySumIfCutAtJ ; // no need of initialisation 
    int maximumSum = 0 ; 

    // to partition , we have to make cut : for index i , we can make cut(j) in the following indexes [i...to...(i + k-1)] , so we have k choices to make cut 
    for(int j = 0 ; j < k ; j++) // j + 1 is the length of the subarray , 
    {                       // i+j is the last index of the current subarray , i + j + 1 is the first indec of the next subarray 
        // cut can be made only if i+j(cut) is within the range of array , i.e. < n
        if(i + j < n)
        {
            maxSubArrayElement = max(maxSubArrayElement , arr[i+j]);
            // subarray length is j + 1 
            currentSubarrayMaxSumAndSuffixSubarraySumIfCutAtJ = maxSubArrayElement * (j+1) + fxnTopDown(arr , n , k ,  i + j + 1 , dp); // if cut at j index after i (i.e. i + j) , new subarray begins from i + j + 1
            // and the size of current subarray is : 
            // (i+j : last index of this subarray) - (i : first index of this subarray) + 1 

            maximumSum = max(maximumSum , currentSubarrayMaxSumAndSuffixSubarraySumIfCutAtJ);
        }
    }

    return dp[i] = maximumSum ; // memoization before return 
}

// time : O(n*k)
// space : O(n) due to dp[]
int fxnBottomUp(vector<int> & arr , int n ,  int k)
{
    // state : dp[i] stores maximum sum possible in the suffix from ith index and goes till (n-1)th index if maximum subarray length possible is : k

    vector<int> dp(n + 1);
    dp[n] = 0 ; // stores maxium sum possible for sufix to start at nth index and goes till n-1

    for(int i = n-1 ; i >= 0 ; i--)
    {
        int maximumSubarrayElement = 0 ; 
        // int maxSoFar = 0 ; // used to maintain the max sum possible from index i for all possible cuts in topDown , here we can do the work with dp[i]

        int maxSoFar = 0 ; 

        for(int j = i ; j < i + k and j < n ; j++)
        {
            maximumSubarrayElement = max(maximumSubarrayElement , arr[j]) ;
            maxSoFar = max(maxSoFar ,maximumSubarrayElement*(j-i+1) + dp[j+1] );
        }
        dp[i] = maxSoFar ;
    }
    return dp[0];
}


int main() 
{
    vector<int> arr = {1,15,7,9,2,5,10} ; 
    int k = 3 ; 

    cout<<fxnRec(arr , arr.size() , k , 0 )<<endl;

    vector<int> dp(arr.size() + 1 , -1);
    cout<<fxnTopDown(arr , arr.size() , k , 0 , dp )<<endl;

    cout<<fxnBottomUp(arr , arr.size() , k)<<endl;

 
    return 0 ;
}