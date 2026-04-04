#include<bits/stdc++.h>
using namespace std;
 
// array ke start to end index tak ka sum nikaalna hai
int fxn(int array[] , int start , int end)
{
    // base case 
    if(start == end)
    {
        return array[start];
    }
    // no need for this condition , as it is handled in above base case start == end
/*  if(start > end)
    {
        return 0 ;
    }
*/
    int mid = start + (end - start)/2 ;
    int ans = fxn(array , start , mid) + fxn(array , mid + 1 , end);

    return ans ;

}
 
int main() 
{
    int array[] = {1,2,3,4,5};
    int n = sizeof(array)/sizeof(int);
    cout<<fxn(array , 0 , n-1);
 
 
 
    return 0 ;
}