#include<bits/stdc++.h>
using namespace std;
 
void fxn(vector<int> & candidates , int target ,  vector<int> & ans , int cur )
{
    // base case 
    if(target == 0)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }cout<<endl;
        return ;
    }
    if(target < 0 ) return ;

    // recurrence relation 
    // Fix an order of exploration: Always move forward through the candidate list instead of going back. That way [2,2,3] can be generated, but [2,3,2] won’t, since you don’t “rewind” to smaller indices.

    // to avoid multiple permutaion , which will result same sum , 
    // fix the order of exploration , instead of starting from 0 in every recursion call , start from current 'i' , so that the exploration is only done in forward manner that means if we are now on i = 2 , then we will explore on from i = 2 to last index
    for (int i = cur; i < candidates.size() ; i++)
    {
        // include candidate[i] in your ans
        target -= candidates[i] ; 
        ans.push_back(candidates[i]);

        fxn(candidates , target , ans , i );

        // backtracking
        target += candidates[i] ; 
        ans.pop_back();
    }
}
int main() 
{
    vector<int> candidates = {2,3,5,7};
    int target = 7 ;
    vector<int> ans ;
    fxn(candidates , target , ans , 0);
 
    return 0 ;
}