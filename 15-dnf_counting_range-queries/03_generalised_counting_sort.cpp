// array element in the range [l , r] , assume l <= r
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l = 2;
    int r = 5;
    vector<int> arr = {4, 3, 2, 2, 4, 3, 5, 4, 5, 2};
    vector<int> freq((r - l + 1), 0);

    // fill the frequency array
    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]-l]++;
    }
    // now sort the initial array
    int count = 0 ;
    for (int i = 0; i < (r - l + 1); i++)//i + l is element value that exists in arr
    {
        for (int j = 1; j <= freq[i]; j++)// j is no. of time i exists in arr
        {
            arr[count++] = (i + l);
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}