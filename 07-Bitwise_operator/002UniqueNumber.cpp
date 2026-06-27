#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {3, 1, 4, 1, 2, 3, 4};

    int unique = 0 ; // doing xor with zero , gives same number 

    for (int i = 0; i < nums.size(); i++)
    {
        unique = unique ^ nums[i]; // a^a : 0 and a^0 : a 
    }
    cout << unique << endl;

    return 0;
}