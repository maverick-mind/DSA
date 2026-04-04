#include<bits/stdc++.h>
using namespace std;

// one more method : divide array in 2 parts , 
                  // check if the left sub-array is sorted or not
                  // check if the right sub-array is sorted or not
                  // also check last element of left-subarray is smaller than the first element of right-subarray , basically compare array[mid] and array[mid+1] 


bool fxn(int array[] , int n )
{
    // base case 
    if(n == 1 or n == 0 )
    {
        return true ; // if 1 element is in the array , then the array is sorted
    }

    // recurrence relation
    if((array[n-1] >= array[n-2]) and fxn(array , n-1))
    {
        return true ;
    }

    else{
        return false ;
    }
}
 
 
int main() 
{
    int array[] = {20,30,40,50,45,60,70};
    
    int n = sizeof(array)/sizeof(n);

    fxn(array , n) ? cout<<"array[] is sorted " : cout <<"array[] is not sorted" ; 
 
 
 
    return 0 ;
}