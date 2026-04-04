#include<bits/stdc++.h>
using namespace std;
 
void fxn( vector<int> & stairs , int n , int k , int &ans )
{
    // base case 
    if(n == 0 )
    {
        for( auto it : stairs)
        {
            cout<<it<<" ";
        }cout<<endl;
        ans++;
        return ;
    }
    if(n < 0) return ;

    // recurrence relation
    for (int i = 1; i <= k; i++)
    {
        n = n - i ;
        stairs.push_back(i);
        fxn(stairs , n , k , ans ) ; 

        // backtracking 
        n += i ;
        stairs.pop_back();
    }
}
 
int main() 
{
    int ans = 0 ;
    int n = 4 ; 
    int k = 3 ;
    vector<int> stairs ;
    fxn(stairs , n , k , ans);
    cout<<endl<<ans ;

    return 0 ;
}