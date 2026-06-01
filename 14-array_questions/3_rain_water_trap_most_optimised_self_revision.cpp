#include<bits/stdc++.h>
using namespace std;
 
int trap(vector<int> &height)
{
    int left = 0 ; 
    int right = height.size()-1 ;
    int lsm = 0 ; // left se max 
    int rsm = 0 ; // right se max
    int wtsf = 0 ; // water trapped so far
    
    while( left <= right )
    {
        lsm = max(lsm , height[left]);
        rsm = max(rsm , height[right]);
        if(height[left] <= height[right]) // iss case mein left(ith) index mein 
        {                 //kitna paani sotre hoga , ye lsm pe depend karega
            wtsf += lsm - height[left] ;
            left++;
        }
        else if(height[left] > height[right])// iss case mein right(jth) index 
        {                // mein kitna paani sotre hoga , ye rsm pe depend karega
            wtsf += rsm - height[right] ;
            right--;
        }
    }
    return wtsf ;
} 


int main() 
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height) << endl;
    return 0 ;
}