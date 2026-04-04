#include<bits/stdc++.h>
using namespace std;
 
void fxn( vector<int> & stairs , int n , int k , int &ans , int count )
{
    // base case 
    if(count == n )
    {
        for( auto it : stairs)
        {
            cout<<it<<" ";
        }cout<<endl;
        ans++;
        return ;
    }
    if(count > n) return ;

    // recurrence relation
    for (int i = 1; i <= k; i++)
    {
        // n = n - i ;
        count += i ;
        stairs.push_back(i);
        fxn(stairs , n , k , ans , count ) ; 

        // backtracking 
        // n += i ;
        count -= i ;
        stairs.pop_back();
    }
}
 
int main() 
{
    int ans = 0 ;
    int n = 4 ; 
    int k = 3 ;
    vector<int> stairs ;
    fxn(stairs , n , k , ans , 0 );
    cout<<endl<<ans ;

    return 0 ;
}