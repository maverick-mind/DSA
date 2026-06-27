#include<bits/stdc++.h>
using namespace std;

// this solution is giving tle on codeforces 
// approach 1 : maximum balls tenzing can remove 
// aproach 2 : minimum balls tenzing can save , then ans would be total balls - min balls saved 


// to solve this : we have to take sequence of n decisions 
// each ball has by-default 1 option : not remove it 
// 2nd option : remove it only when the ith ball can be combined with some other ball j in the sequence 

// time : O(n^n) : each index has n choices : don't get removed , get removed by combining with (n-i-1) other elements in worst case 
// for removing that index element , we again have (n-i-1) options in worst case , so overal for n elements , if geting removed : ~ n^2 options 

// space : O(n) : due to function call stack , longest branch would be around when each index is don't remove , and call i + 1 index 
int fxnRec(vector<int> & a , int i , int & n)
{
    // base case 
    if(i == n) return 0 ; 


    // recurrence relation 
    // for ith index , either the cut would be at the index j such that i < j and a[i] == a[j] , 
    //                        otherwise no cut at all (is always an option)
    // for all the i we have both options , from both the options : check from where we can remove the maximum number of balls 

    // option 1 : default option : not to remove it 
    int notRemovingCurrentIthBall = fxnRec(a , i + 1 , n) ; 


    // option 2 : remove the current ith ball , if it combines with any jth ball in the future 
    int maximumBallsRemovedByRemovingIthBall = 0 ; 
    for(int j = i + 1 ; j < n ; j++)
    {
        if(a[i] == a[j]) // remove all balls in between , and check from j + 1 onwards ,
        {                // what is the maximum number of balls we can remove 

             // check j + 1 onwards maximum balls removed 
            maximumBallsRemovedByRemovingIthBall = max(maximumBallsRemovedByRemovingIthBall , (j-i+1) + fxnRec(a , j + 1 , n)) ; 
        }
    }

    // maximum balls removed from suffix ith ball would be either : if ith ball is removed combining with jth ball OR not removing ith ball at all 
    return max(maximumBallsRemovedByRemovingIthBall , notRemovingCurrentIthBall) ; 
}
 

// to solve this : we have to take sequence of n decisions 
// each ball has by-default 1 option : not remove it 
// 2nd option : remove it (only when it matches with some next ball in the sequence)

// time : O(n^2) : will give tle 
int fxnTopDown(vector<int> & a , int i , int & n , vector<int> & dp)
{
    // base case 
    if(i == n) return dp[i] = 0 ; 

    // lookups 
    if(dp[i] != -1) return dp[i] ; 


    // recurrence relation 
    // for ith index , either the cut would be at the index j such that i < j and a[i] == a[j] , 
    //                        otherwise no cut at all (is always an option)
    // for all the i we have both options , from both the options : check from where we can remove the maximum number of balls 

    // option 1 : default option : not to remove it 
    int notRemovingCurrentIthBall = fxnTopDown(a , i + 1 , n , dp) ; 


    // option 2 : remove the current ith ball , if it combines with any jth ball in the future 
    int maximumBallsRemovedByRemovingIthBall = 0 ; 

    for(int j = i + 1 ; j < n ; j++)
    {
        if(a[i] == a[j]) // remove all balls in between , and check from j + 1 onwards ,
        {                // what is the maximum number of balls we can remove 

             // check j + 1 onwards maximum balls removed 
            maximumBallsRemovedByRemovingIthBall = max(maximumBallsRemovedByRemovingIthBall , (j-i+1) + fxnTopDown(a , j + 1 , n , dp)) ; 
        }
    }

    // maximum balls removed from suffix ith ball would be either : if ith ball is removed combining with jth ball OR not removing ith ball at all 
    return dp[i] = max(maximumBallsRemovedByRemovingIthBall , notRemovingCurrentIthBall) ; 
}

// time : O(n^2) : will give tle 
// space : O(n)
int fxnBottomUp(vector<int> & a , int & n)
{
    vector<int> dp(n+1) ; 
    dp[n] = 0 ;

    for(int i = n-1 ; i >= 0 ; i--)
    {
        int maximumBallsRemovedByRemovingIthBall = 0 ; 
        for(int j = n - 1  ; j > i ; j--)
        {
            if(a[i] == a[j])
            {
                maximumBallsRemovedByRemovingIthBall = max(maximumBallsRemovedByRemovingIthBall , (j-i+1) + dp[j+1]) ; 
                break ; 
            }
        }

        dp[i] = max(maximumBallsRemovedByRemovingIthBall , dp[i+1]) ;// dp[i+1] stores the value when we don't remove the ith ball and try to find maximum number of balls we can remove from [i+1...n]
    }
    return dp[0] ; 

}
 
 
int main() 
{
    int t ; 
    cin>>t ;

    while(t--)
    {
        int n ; 
        cin>>n;
        vector<int> a(n) ;
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        // cout<<fxnRec(a , 0 , n)<<endl;

        vector<int> dp(n + 1 , -1);

        cout<<fxnTopDown(a , 0 , n , dp)<<endl;
        // cout<<fxnBottomUp(a ,n)<<endl;
    }
 
    return 0 ;
}