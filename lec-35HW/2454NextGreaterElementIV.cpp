#include<bits/stdc++.h>
using namespace std;
 
 class cmp {
    public:
        bool operator()(const pair<int,int>& a,
                        const pair<int,int>& b) const {
            return a.first > b.first;   // min-heap based on first
        }
};

vector<int> secondGreaterElement(vector<int>& nums) {
        
    // make 1 stack s1 and 1 queue pq2 , s1 will contain elements jinnka ek bhi greater element to the right nahi mila hai 
    // as soon as s1.top() se badaa element mile , push it to pq2 , but before pushing to pq2 , check in pq2 , ki current element kitne pq2 ke top element se badaa hai , jitno se badaa hai unn sab ke liye current element ans banega , and then start shifting elements from s1 to pq2 , and at last push current element to s1 , kyonki curent element ke liye abhi dhundna baaki hai secondGreaterElement
    // s1 would be monotonous increasing (bottom largest , top smallest )
    // kyonki s1 se pq2 mein element ko shift kar rhe hai , thus pq2 would be monotonous increasing(top pe larget , aur back pe smalllest)

    stack<pair<int,int>> s1; // waiting for first greater element

    // we need priority queue to solve this , normal queue is not enough
    // queue<pair<int,int>> pq2; 
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq2 ; // waiting for second greater element
    vector<int> ans(nums.size() , -1); // assign every value with -1 , so that when we reach element n-1 in loop we have our ans array built , if we don't initialise , we need to do extra work as , after moving from 0 to n -1 in for loop , below for loop , if some elements are left in s1 and pq2 , for those elements assign -1 at respective index in ans vector 


    for (int i = 0; i < nums.size(); i++)
    {
        // check if nums[i] > pq2.top.first , it means check if nums[i] could be next greater element for any element or not 
        while(!pq2.empty() and nums[i] > pq2.top().first)
        {
            // nums[i] is ans for that pq2.top()
            ans[pq2.top().second] = nums[i] ;
            pq2.pop() ;
        }
        
        // now check for s1 , agar nums[i] badaa hai s1.top().first se matlab s1.top().first ke liye ek badaa value mil gya hai , now move it to queue pq2 , and pop it from s1
        while(!s1.empty() and nums[i] > s1.top().first)
        {
            pq2.push(s1.top());
            s1.pop();
        }
        
        if(s1.empty() or nums[i] <= s1.top().first )
        {
            s1.push({nums[i] , i});
        }
    }
    return ans ;
}
 
int main() 
{
    // vector<int> nums = {2,4,0,9,6}; // 9,6,6,-1,-1
    // vector<int> nums = {3,3};
    vector<int> nums = {11,13,15,12,0,15,12,11,9}; // [15,15,-1,-1,12,-1,-1,-1,-1]

    vector<int> ans = secondGreaterElement(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
 
 
    return 0 ;
}