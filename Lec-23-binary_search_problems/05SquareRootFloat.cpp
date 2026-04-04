// float mein dikkat ye hai ki infinite numbers honge start aur end ke bich mein
// so , start aur end hamesha close aate jaayenge , ek dusre ko approach karenge but overtake nahi kar paayenge
// and leetcode ya codeforces ye liberty dete hai ki hamaraa answer +-10^(-6) range mein fluctuate kar sakta hai original answer ke , they will accept answer which is correct upto 10^(-6)
// let's say original ans is x , and our ans is y , so they will accept y as long as 
// x - 10^(-6) <= y < x + 10^(-6)
// but to be more precise , take 10^(-7)

#include<bits/stdc++.h>
using namespace std;
 
 
int main() 
{
    int n ; 
    cin >> n ;

    double start = 0 ;
    double end = n ;
    double ans = -1 ;
    double moe = 1e-6 ; // margin or error which is allowed
    
    while(end - start >= 1e-7)// to get more precise answer  
    {                         // 1e-7 for 1e-6
        double mid = start + (end - start)/2 ;


        if(mid * mid <= n)
        {
            ans = mid ;
            start = mid + 1e-7 ;
        }
        else
        {
            end = mid - 1e-7 ;
        }
    }

    cout<<ans<<endl;

    cout<<setprecision(3)<<fixed<<ans<<endl;// ek hota hai scientific notaion , ek hota hai fixed point notation , so for fixed point notaion , use "fixed" keyword 
 
 
 
    return 0 ;
}