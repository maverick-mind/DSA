#include<bits/stdc++.h>
using namespace std;
 
bool predicate_fxn( int n , int mid )
{
    if(mid*mid <= n)
    {
        return true ;
    }

    return false ;
}

int squareRoot(int n)
{
    int start = 0 ;
    int end = n ;
    int ans = -1 ;
    
    while(start <= end)
    {
        int mid = start + (end - start)/2 ;


        if(predicate_fxn(n , mid))
        {
            ans = mid ;
            start = mid + 1 ;
        }
        else
        {
            end = mid - 1 ;
        }
    }
    return ans ;
}
 
int main() 
{
    int n ; 
    cin >> n ;

    cout<<squareRoot(n);
 
 
 
    return 0 ;
}