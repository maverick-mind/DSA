// every triplets can be stored in a vector of size 3 , because we can have  multiple triplets , so to store these triplets , we can store these in a vector jiska har harr elements khud mein 1 vector ho , so we need vector of vector
// vector< vector<int> >

// 3sum --> nums[i] + nums[j] + nums[k] == target(here target is 0)
// also , no pair could have duplicate elements , {-1, 0 , 1} and {0 , -1 , 1} both are same as all the 3 numbers exist in each other , also order of element is not necessary to maintain , so you can sort elements if needed 

#include<iostream> 
#include<vector>
using namespace std ; 
// question : sum of 3 elements equal to 0 
vector< vector<int> > three_sum(vector<int> & nums)
{
    vector< vector<int> > ans ;
    int n = nums.size();

    for (int i = 0; i <= n - 3; i++)
    {   for (int j = i+1; j <= n-2; j++)
        {   for (int k = j+1; k <= n-1; k++)
            { if(nums[i] + nums[j] + nums[k] == 0)
                { ans.push_back({nums[i] , nums[j] , nums[k]}) ; }
            }         
        }
    }
        return ans ;
}
 
int main() 
{
    vector<int> nums = {-1 , 0 , 1 , 2 , -1 , -4} ;

    vector< vector<int> > ans = three_sum(nums);

    return 0 ;
}