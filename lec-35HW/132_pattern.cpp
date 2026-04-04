#include <bits/stdc++.h>
using namespace std;

bool find132pattern(vector<int> &nums)
{
    if (nums.size() < 3) return false;

  

    // for i , do the work as prefix sum thing , but for prefix min
    vector<int> prefix_min;
    prefix_min.push_back(INT_MAX);

    for (int i = 1; i < nums.size(); i++)
    {
        int temp = min(prefix_min[i - 1], nums[i-1]);
        prefix_min.push_back(temp) ;
    }

    
    // now for k , we want nums[k] < nums[j] and nums[i] < nums[k], so find the nearest greater element to the right of j but the element should be greater than ith element , not jth element , for this start moving from right to left , and maintining the stack , and current element inside the loop would refer to j

    stack<int> stk; // it will store nearest greater element in the right of j
    int n = nums.size() ;
    cout<<n<<" ";
    for (int j = n - 1; j > 0; j--)
    {
       
        // 2 cases 
        // 1. nums[j] <= prefix_min[j];
        // 2. nums[j] > prefix_min[j];

        

        // 1. nums[j] > prefix_min[j];
        if(nums[j] <= prefix_min[j])
        {
            continue ; // do nothing 
        }
        
        // 2. nums[j] <= prefix_min[j]; // either push or popped here 
        else{
            // cases : stack.top() > nums[j] or stack.top() < nums[j]
            while (!stk.empty() && stk.top() <= prefix_min[j]) stk.pop();
            if (!stk.empty() && stk.top() < nums[j]) return true;

            // if (!stk.empty() && stk.top() >= nums[j]) stk.push(nums[j]);
            // if(stk.empty()) stk.push(nums[j]);

            stk.push(nums[j]);
        }
        
    }

    return false;
}

// don't think I covered all the cases , but it still passed all the testcases on Leetcode
// bool find132pattern(vector<int> &nums)
// {

//     // for i , do the work as prefix sum thing , but for prefix min
//     vector<int> prefix_min;
//        prefix_min.push_back(INT_MAX);


//     for (int i = 1; i < nums.size(); i++)
//     {
//         int temp = min(prefix_min[i - 1], nums[i-1]);
//         prefix_min.push_back(temp) ;
//     }

//     // now for k , we want nums[k] < nums[j] , so find the nearest greater element to the right of j , for this start moving from right to left , and maintining the stack , and current element inside the loop would refer to j

//     stack<int> stk; // it will store nearest greater element in the right of j
//     for (int j = nums.size() - 1; j > 0; j--)
//     {
//         // 2 cases , either stack is empty , or stack is not empty
//         // 1. stack is empty
//         if (stk.empty())
//         {
//             stk.push(nums[j]);
//         }

//         // 2. stack is not empty
//         else if (!stk.empty())
//         {
//             // again 2 cases , element on top of stack is smaller than nums[j] , or element on top of the stack is greater than nums[j]

//             // 2.1 element on top of the stack is greater than nums[j]
//             if (nums[j] <= stk.top()) // just push nums[j] on top
//             {
//                 stk.push(nums[j]);
//             }
//             // 2.2 element on top of the stack is smaller than nums[j]
//             else if (nums[j] > stk.top())
//             {
//                 // now check if prefix_min[j] < stk.top()
//                 // it means , is prefix_min[j] < nums[k]
//                 if (prefix_min[j] < stk.top())
//                 {
//                     // we get our answer , as true , yes there exist 132 pattern in the array nums
//                     return true;
//                 }
//                 // if not
//                 else
//                 {
//                     while (!stk.empty() and stk.top() < nums[j])
//                     {
//                         if (prefix_min[j] < stk.top())
//                         {
//                             // we get our answer , as true , yes there exist 132 pattern in the array nums
//                             return true;
//                         }
//                         stk.pop();
//                     }
//                     stk.push(nums[j]);
//                 }
//             }
//         }
//     }

//     return false;
// }

int main()
{
    // vector<int> nums = {3, 4, 6, 2, 1, 5}; // (3,6,5) , (4,6,5) are 132 pattern
    // vector<int> nums = {-1,3,2,0}; // true
    vector<int> nums = {250 , 100 , 500,200,300}; 

    if (find132pattern(nums))
    {
        cout << "132 pattern exists" << endl;
    }
    else
    {
        cout << "132 pattern does not exists" << endl;
    }

    return 0;
}

/*
bool find132pattern(vector<int> &nums)
{

    // for i , do the work as prefix sum thing , but for prefix min
    vector<int> prefix_min;
    prefix_min[0] = INT_MAX;

    for (int i = 1; i < nums.size(); i++)
    {
        prefix_min[i] = min(prefix_min[i - 1], nums[i-1]);
    }

    // now for k , we want nums[k] < nums[j] and nums[i] < nums[k], so find the nearest greater element to the right of j but the element should be greater than ith element , not jth element , for this start moving from right to left , and maintining the stack , and current element inside the loop would refer to j

    stack<int> stk; // it will store nearest greater element in the right of j
    for (int j = nums.size() - 1; j > 0; j--)
    {
       
        // 2 cases 
        // 1. nums[j] <= prefix_min[j];
        // 2. nums[j] > prefix_min[j];


        // 1. nums[j] > prefix_min[j];
        if(nums[j] <= prefix_min[j])
        {
            continue ; // do nothing 
        }

        // 2. nums[j] <= prefix_min[j]; // either push or popped here 
        else{
            // cases : stack.top() > nums[j] or stack.top() < nums[j]
            if(!stk.empty() and nums[j] > stk.top())
            {
                if(prefix_min[j] < stk.top()) return true ;

                else{
                    while(!stk.empty() and stk.top() <= prefix_min[j] )
                    {
                        if(nums[j] > stk.top() and stk.top() > prefix_min[j] )
                        {
                            return true ;
                        }
                        stk.pop();
                    }
                }
            }
            if(!stk.empty() and nums[j] < stk.top())
            {
                stk.push(nums[j]);
            }
            if(stk.empty())
            {
                stk.push(nums[j]);
            }
            
        }

    }

    return false;
}

















bool find132pattern(vector<int> &nums)
{

    // for i , do the work as prefix sum thing , but for prefix min
    vector<int> prefix_min;
       prefix_min.push_back(INT_MAX);


    for (int i = 1; i < nums.size(); i++)
    {
        int temp = min(prefix_min[i - 1], nums[i-1]);
        prefix_min.push_back(temp) ;
    }

    // now for k , we want nums[k] < nums[j] , so find the nearest greater element to the right of j , for this start moving from right to left , and maintining the stack , and current element inside the loop would refer to j

    stack<int> stk; // it will store nearest greater element in the right of j
    for (int j = nums.size() - 1; j > 0; j--)
    {
        // 2 cases , either stack is empty , or stack is not empty
        // 1. stack is empty
        if (stk.empty())
        {
            stk.push(nums[j]);
        }

        // 2. stack is not empty
        else if (!stk.empty())
        {
            // again 2 cases , element on top of stack is smaller than nums[j] , or element on top of the stack is greater than nums[j]

            // 2.1 element on top of the stack is greater than nums[j]
            if (nums[j] <= stk.top()) // just push nums[j] on top
            {
                stk.push(nums[j]);
            }
            // 2.2 element on top of the stack is smaller than nums[j]
            else if (nums[j] > stk.top())
            {
                // now check if prefix_min[j] < stk.top()
                // it means , is prefix_min[j] < nums[k]
                if (prefix_min[j] < stk.top())
                {
                    // we get our answer , as true , yes there exist 132 pattern in the array nums
                    return true;
                }
                // if not
                else
                {
                    while (!stk.empty() and stk.top() <= nums[j])
                    {
                        if (prefix_min[j] < stk.top())
                        {
                            // we get our answer , as true , yes there exist 132 pattern in the array nums
                            return true;
                        }
                        stk.pop();
                    }
                    stk.push(nums[j]);
                }
            }
        }
    }

    return false;
}
*/