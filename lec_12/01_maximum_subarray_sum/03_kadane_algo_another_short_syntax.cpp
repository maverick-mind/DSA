#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[] , int n)
{
    int mssf = 0 ; // max sum so far
    int msasf = arr[0];// max sub-array so far

    for (int i = 0; i < n; i++)
    {  
         // max sum so far 3 tareeke se aa sakta hai
         // 1. pichhla sub-array max sum generate kar ke de --> msasf 
         // 2. pichhla sub-array mein current element add karne par max sum mile 
         //     --> msasf + arr[i]
         // 3. current element badaa ho pichhle sub array sum se --> arr[i]
 
        // msasf = max(msasf + arr[i] , arr[i]);
        // mssf = max(mssf , msasf); // pichhla sub array ka max value --> mssf ko current sub-array ke max value (one of msasf + arr[i] , arr[i]) se compare kar rhe hai
        
        mssf = max( mssf , (msasf = max(msasf + arr[i] , arr[i])));// wow syntax worked
    }

    return mssf ; 
}

int main()
{
    int arr[] = {2, 3, 4, -20, 4, 5, 7, -35};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << kadane(arr, n);

    return 0;
}