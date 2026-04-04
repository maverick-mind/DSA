#include<bits/stdc++.h>
using namespace std;
 
int fxn( vector<int> & stairs , int n , int k , int count )
{
    // base case 
    if(count == n )
    {
        for( auto it : stairs)
        {
            cout<<it<<" ";
        }cout<<endl;
        // ans++;
        return 1; // 1 path exist if you reach on nth stair
    }
    if(count > n) return 0; // no path exist if you does not reach on top

    // recurrence relation
    int ans = 0 ;
    for (int i = 1; i <= k; i++)
    {
        // n = n - i ;
        count += i ;
        stairs.push_back(i);
        ans += fxn(stairs , n , k , count ) ; 

        // backtracking 
        // n += i ;
        count -= i ;
        stairs.pop_back();
    }

    return ans ; 
}
 
int main() 
{
 
    int n = 4 ; 
    int k = 3 ;
    vector<int> stairs ;
    int ans = fxn(stairs , n , k , 0 );
    cout<<endl<<ans ;

    return 0 ;
}