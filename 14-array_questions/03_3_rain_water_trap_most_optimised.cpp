#include <iostream>
#include <vector>
using namespace std;

// time : O(n)
// space : O(1)

int trap(vector<int> &height)
{
    int i = 0;
    int j = height.size() - 1;

    // initially
    int left_se_max = height[0]; // max of all the height[0....i]
    int right_se_max = height[height.size() - 1];// max of all the height[j....n-1]
    int total_water_trap = 0;

    while (i <= j)
    {   
        // update left_se_max and right_se_max before entering if-else statements
        left_se_max = max(left_se_max , height[i]);
        right_se_max = max(right_se_max , height[j]);

        if(left_se_max < right_se_max)
        {
            total_water_trap += left_se_max - height[i];
            i++;
        }
        else{ // if(left_se_max >= right_se_max)
            total_water_trap += right_se_max - height[j];
            j--;
        }
    }
    return total_water_trap;
}

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height) << endl;
    return 0;
}