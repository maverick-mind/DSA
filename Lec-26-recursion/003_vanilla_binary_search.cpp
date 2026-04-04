// "Vanilla binary search" ka matlab hota hai basic / standard implementation of binary search — bina kisi modification ke, jaisa textbook algorithm hota hai.

#include <bits/stdc++.h>
using namespace std;

bool fxn(int array[] , int start , int end , int target)
{

    // base case 
    if(start > end) return false ;

    // recursive case 
    int mid = start + ( end - start )/2;
    bool ans = false ;

    if(target == array[mid]) return true ;

    else if ( target < array[mid])
    {
       ans =  fxn(array , start , mid-1 , target);
      // return fxn(array , start , mid-1 , target); 
    }
    else if(target > array[mid])
    {
        ans = fxn(array , mid + 1 , end , target);
        //return fxn(array , mid + 1 , end , target);
    }

    return ans ; 

}


int main()
{
    int arr[] = {10, 15 , 20, 30, 40, 50, 60, 70 , 80, 85 , 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 15 ;

   // fxn(arr , 0 , n-1 , target) ? cout<<target<<" is found" : cout<<target << " not found";

   cout << (fxn(arr, 0, n-1, target) ? to_string(target) + " is found"
                                  : to_string(target) + " not found");

    return 0;
}
