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
    double moe = 1e-16 ; // margin or error which is allowed
    
    // the program will run into "precision issue" , and will stuck in infinite loop for 10^-16 precision
    // so , overall universe mein jitne bhi floating point numbers hai unn sabke liye unique binary nahi hai , there will be case jahaa multiple floating point numbers(jo bahut jyaada close ho ek dusre se) ke liye same binary ho 
    // so loop run karte hue , ek time aisaa aayega jab start aur end itne close aa jaayenge , jab start aur end ki bich mein jitne bhi floating points number hai , unn sab ki value start aur end se hi match kar rhi hai , and because of that closeness , start aur end ko update hone ke baad bhi kuchh change aa nhi rha hai , so loop condition kabhi fale ho hi nahi rhi hai , and thus we are stuck in infinite loop
    // so to fix this issue , calculate kitne iteration tak loop chalaana hai , and uss iteration par condition lagaao 
    while(end - start >= 1e-17)
    {                         
        double mid = start + (end - start)/2 ;
        cout<<setprecision(3)<<fixed<<start<<" "<<mid<<" "<<end<<endl;

        if(mid * mid <= n)
        {
            ans = mid ;
            start = mid + 1e-17 ;
        }
        else
        {
            end = mid - 1e-17 ;
        }
    }

    cout<<ans<<endl;

    cout<<setprecision(3)<<fixed<<ans<<endl;// ek hota hai scientific notaion , ek hota hai fixed point notation , so for fixed point notaion , use "fixed" keyword 
 
 
 
    return 0 ;
}