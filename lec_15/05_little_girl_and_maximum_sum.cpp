#include<bits/stdc++.h>
using namespace std ; 
#define int long long
 
// int64_t main() // this will gurantee ki in 64 bits ka hai 
int32_t main() // this will gurantee ki int 32 bits ka hai , kyonki puraane system mein int 2bytes ke hote thee , nayee system mein int 4 bytes ke hoone lagee 
{
    int n  , q ;
    cin>>n>>q;
    vector<int> arr(n); 
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    vector<int> diff(n+1 , 0); // difference array has 1 size more than original array to handle prefix sum for last index 
    while (q--)
    {
        int l , r ;
        cin>>l>>r;
        l--;// since codeforce has 1 based indexing , not 0
        r--;// and we are using 0 based indexing 
        diff[l] += 1 ;
        diff[r+1] += -1;
    }
    // now calculate the prefix sum for difference arr(diff[]) and store it in diff[] itself
    for (int i = 1; i < n+1; i++)
    {
        diff[i] += diff[i-1];
    }

    // for maximum sum possible after rearrangement(as per question we can do rearrangement to obtain maximum sum from original array after aplying query ) , arr ke max value ka index sync karna chahiye diff array ke max value ke index ke saath 
    // so sort both diff array and original array
    sort(arr.begin() , arr.end());
    sort(diff.begin() , diff.end()-1);

    int max_sum = 0 ;
    for (int i = 0; i < n; i++)
    {
        max_sum += diff[i] * arr[i] ;
    }
    cout<<max_sum;
    return 0 ;
}