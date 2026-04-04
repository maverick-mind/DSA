#include<bits/stdc++.h>
using namespace std;
 
vector<string> arr = {"zero" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine"};
 
string fxn(int n)
{
    // base case 
    if(n == 0)
    {
        return arr[0] ;
    }

    // recurrence relation
    string ans = fxn(n/10) + arr[n%10] + " ";
    return ans ;
}
 
int main() 
{
    int n = 1234 ;
    string ans = fxn(n);
    ans.erase(0 , 4);
    cout<<ans<<endl;
 
 
 
    return 0 ;
}