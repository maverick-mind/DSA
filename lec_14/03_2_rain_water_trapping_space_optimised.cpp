#include<iostream>
#include<vector>
using namespace std ; 

// T.C :3nx const ~ O(n)
// space complexity n due to right_height[] so ~ O(n)

// we are going from left to right in the loop where we are calculating water_trap as final answer , so agar hum left to right jaa rhe hai , to left to right jaate time ek variable mein store kar sakte hai 0th index se ab tak ith index ka max height , yaani we don't need left_height[] array , so pahle 2n space lagg rha thaa , ab sirf n space lagega
int trap(vector<int>& height) {

    // precompute left_height[] array
    //vector<int> left_height(height.size());
    // left_height[0] = height[0];
    // for (int i = 1; i < height.size(); i++)
    // {
    //    left_height[i] = max(left_height[i-1] , height[i]);     
    // }

     // precompute right_height[] array
    vector<int> right_height(height.size());
    right_height[height.size() - 1 ] = height[height.size() - 1];
    for (int i = height.size()-2; i >= 0; i--)
    {
       right_height[i]  = max(right_height[i+1] , height[i]);
    }
   
    int water_trap = 0 ;
    int left = height[0] ; // initialize it with height[0]
    for (int  i = 0; i < height.size(); i++)
    {
      left = max(left , height[i]);
      //no need to calculate left_height[] array , just maintain a variable to track maximum height from 0th index till now at ith index    
      water_trap += min(left , right_height[i]) - height[i] ;        
    }
    return water_trap;
}
 
int main() 
{
    vector <int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height)<<endl;
    return 0 ;
}