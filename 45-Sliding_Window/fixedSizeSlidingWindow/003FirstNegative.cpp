// maintain a "k-size deque" for tracking the negative number in the subarray sequentially

#include <bits/stdc++.h>
using namespace std;

// time : k*constant + (n-k)*constant  O(n)
// space : O(k)


int main()
{
    vector<int> nums = {-2, 0, -1, 2, -3, 1, 3};
    int n = 7 ;
    int k = 4 ;
    deque<int> dq ;

    int i = 0 ; 
    int j = 0 ;

    vector<int> ans ;
    while(j < k)
    {
        if(nums[j] < 0) // -ve
        {
            dq.push_back(nums[j]);
        }
        j++;
    }

    if(!dq.empty())
    {
        ans.push_back(dq.front());
    }else ans.push_back(0);

    while(j < n)
    {
        // remove the ith element from the window 
        if(nums[i] < 0) // nums[i] == dq.front()
        {
            dq.pop_front();
        }else ans.push_back(0);
        i++;

        // include the jth element in the window
        if(nums[j] < 0)
        {
            dq.push_back(nums[j]);
        }

        if(!dq.empty()) ans.push_back(dq.front());
        j++;
    }

    for(auto element : ans)
    {
        cout<<element<<" ";
    }

    return 0;
}