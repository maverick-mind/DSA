// decimal to binary , (generate the binary)

#include<bits/stdc++.h>
using namespace std;
 
string f(int n)
{
    // base case 
    if(n == 0 )
    {
        // generate the binary string for 0 --> "" empty string or may be "0"
        return "0" ;
    }

    // reccurence relation

    // f(n) : generate the binary string for n 

    // 1. ask your friend to generate the binary string for n/2 
    string binarStringFromMyFriend = f(n/2);

     int B = n % 2 ;
    //  char ch = '0' + B ;
    //  binarStringFromMyFriend.push_back(ch);


     return binarStringFromMyFriend + to_string( n % 2 );// jo pahle se remainder aa rhe hai unn mein 10 se multiply kar ke current remainder add kar denge , and once the fxn stack is empty , we can return this value , sabse niche wahi return kiya karo jo final answer bann ke return ho jab fxn call stack empty ho jaaye 

}
 
int main() 
{
    cout<<f(42);
 
 
 
    return 0 ;
}