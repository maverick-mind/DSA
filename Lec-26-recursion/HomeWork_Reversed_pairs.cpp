#include<bits/stdc++.h>
using namespace std;
 

long long count(vector<long long>& nums , long long start , long long mid , long long end)
{
    long long i = start ;
    long long j = mid + 1 ;

    // 1. first count the ans 
    long long ans = 0 ;

    while(i <= mid and j <= end)
    {
        if((long long)nums[i] > 2ll*nums[j]) // to avoid int overflow 
        {
            ans += (mid + 1 - i ) ;
            j++ ;
        }
        else if ( (long long)nums[i] <= 2ll*nums[j])
        {
            i++ ; 
        }
    }

    // 2. now in a new temp array , sort the original array and copy it 
    i = start ;
    j = mid + 1 ;
    vector<long long> temp ;
    while( i <= mid and j <= end)
    {
        if(nums[i] <= nums[j])
        {
            temp.push_back(nums[i++]) ;
        }
        else if (nums[i] > nums[j])
        {
            temp.push_back(nums[j++]);
        }
    }
    while(i <= mid)
    {
         temp.push_back(nums[i++]) ;
    }
    while( j <= end)
    {
        temp.push_back(nums[j++]);
    }

    // 3. now copy temp in original array , nums 
    i = start ;
    long long k = 0 ;
    while(i <= end)
    {
        nums[i++] = temp[k++];
    }

    return ans ;

}

long long fxn(vector<long long>& nums , long long start , long long end)
{
    // base case 
    if( start >= end)
    {
        return 0 ; 
    }

    // recurrence relation 
    long long ans = 0 ;
    long long mid = start + (end - start)/2 ;
    // left aur right side ka ans friend dega , current ka ans hum khud se nikaalenge count fxn ko call kar ke 
    ans = fxn(nums , start , mid) + fxn( nums , mid + 1 , end) ;
    ans += count(nums , start , mid , end) ; 

    return ans ;
}


long long reversePairs(vector<long long>& nums) {
    return fxn(nums , 0 , nums.size()-1);
}

int main() 
{
    // vector<long long> nums = {5,10,20,30,40,1,3,8} ; // ans : 12
    vector<long long> nums = {2,4,3,5,1} ; // ans : 3

    
    cout<<reversePairs(nums) ; 

    return 0 ;
}