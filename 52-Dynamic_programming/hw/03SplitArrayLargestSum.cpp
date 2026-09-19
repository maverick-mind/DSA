class Solution {
public:
// samilar to book allocation problem or painter's partition problem
// binary search bound : 
// lower bound : best case : n subarray hai aur n hi elements hai array mein , so minimum larget subarray sum would be *max_element(nums.begin() , nums.end()) ;

// upper bound : worst case : 1 subarray hai 
//               so minimum larget subarray sum would be
//               end = accumulate((nums.begin() , nums.end() , 0);

// by doing 'k' partition of nums.length sized array , so that each subarray sum is less than equal to 'mid' value

// OR we can rephrase it like 
// kya agar maximum subarray sum ki value "mid" ho , to kya less than or equal to k partitions possible hai ? 
bool predicate_fxn(vector<int>& nums, int k , int mid)
{
    int sum = 0 ; // sum of elements of subarray

    int numberOfSubarray = 1 ; // start with subarray count = 1 

    for (int i = 0; i < nums.size(); i++)
    {
        if(sum + nums[i] <= mid)
        {
            sum += nums[i] ;
        }
        else if(sum + nums[i] > mid)
        {
            sum = 0;
            numberOfSubarray++;
            sum += nums[i];
        }
    } 
    return numberOfSubarray <= k ; 

}

int splitArray(vector<int>& nums, int k) {
        
    int start = *max_element(nums.begin() , nums.end()) ;
    int end = accumulate(nums.begin() , nums.end() , 0);
    // start and end are range of subarray sum , and mid is potential answer of the subarray sum with largest value 

    int ans = -1 ;

    while(start <= end)
    {
        int mid = start + (end - start)/2 ;
    if(predicate_fxn(nums , k , mid))// mid is the possible sum of larget subarray
    {
        ans = mid ;// agar mid ek answer hai , to mid se kam answer bhi dhundna chahiye
        end = mid - 1 ;
    }
    else{// agar mid ek answer nahi hai , to mid se kam bhi answer nahi hoga
        start = mid + 1 ;
    }
    }
    return ans ;
}

};

// also try dp-based solution 