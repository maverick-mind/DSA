#include<iostream>
#include<vector>
using namespace std ; 

// T.C : O(n)
// space complexity 2n due of left_height[] and right_height[] so ~ O(n)
int trap(vector<int>& height) {

    // precompute left_height[] array
    vector<int> left_height(height.size());
    left_height[0] = height[0];
    for (int i = 1; i < height.size(); i++)
    {
       left_height[i] = max(left_height[i-1] , height[i]);     
    }

     // precompute right_height[] array
    vector<int> right_height(height.size());
    right_height[height.size() - 1 ] = height[height.size() - 1];
    for (int i = height.size()-2; i >= 0; i--)
    {
       right_height[i]  = max(right_height[i+1] , height[i]);
    }
   
    int water_trap = 0 ;
    for (int  i = 0; i < height.size(); i++)
    {      
            water_trap += min(left_height[i] , right_height[i]) - height[i] ;       
    }
    return water_trap;
}
 
int main() 
{
    vector <int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout<<trap(height)<<endl;

    return 0 ;
    
}