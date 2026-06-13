// In variable size sliding window , the substring should satisfy some property 
// expand the window , shrink the window 

#include<bits/stdc++.h>
using namespace std;
 
 
int main() 
{
    vector<int> nums = {2,3,2,4,0,2,0};
    int n = nums.size() ; 
    int k = 6 ;

    int largestWindow = 0 ; 

    int i = 0 ; 
    int j = 0 ;
    // window length : (j - i + 1)

    // // create the first window 
    // int sum = nums[j];
    // j++;
    
    int sum = 0 ;

    while(j < n)
    {
         // is current window sum equals to k 
        if(sum == k) {
            largestWindow = max(largestWindow , (j - i + 1));
        }


        if(sum <= k)// expand the window 
        {
            sum += nums[j];
            j++;
        }
        // else{ // sum > k : shrink the window
        //     sum -= nums[i] ;
        //     i++;
        // }
        // when sum exceeds k , property is voilated 
        while(sum > k) // voilation of property , shrink the window ,
        {              //  till property is not voilated
            sum -= nums[i] ; 
            i++;
        }

       
    }

    cout<<endl<<largestWindow<<endl;
 
 
    return 0 ;
}