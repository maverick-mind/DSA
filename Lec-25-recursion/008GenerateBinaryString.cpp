// decimal to binary , (generate the binary)

#include<bits/stdc++.h>
using namespace std;
 
int f(int n)
{
    // base case 
    if(n == 0 )
    {
        return 0 ;
    }

    // reccurence relation

    // ek kaam mai karunga , baaki sub problem friend karega
    // number ko divide karo 2 se , remainder rakh lo , aur quotient de do friend ko 
    int ans = f(n/2);

     int B = n % 2 ;

     return ans*10 + B;// jo pahle se remainder aa rhe hai unn mein 10 se multiply kar ke current remainder add kar denge , and once the fxn stack is empty , we can return this value , sabse niche wahi return kiya karo jo final answer bann ke return ho jab fxn call stack empty ho jaaye 

}
 
int main() 
{
    cout<<f(42);
 
 
 
    return 0 ;
}