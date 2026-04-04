// Given N coins, such that each coin has two sides H (heads) & T (tails), design a recursive algorithm to generate all the possible outcomes that we can get upon tossing the N coins simultaneously such that an outcome  should not  contain consecutive heads.

#include <bits/stdc++.h>
using namespace std;

void fxn(string str , int i , int n )
{
    // base case 
    if(i == n)
    {
        cout<<str<<endl;
        return ;
    }

    // recurrence relation
    if(str.empty() or str.back() != 'H' )
    {
        str.push_back('H');
        fxn( str , i + 1 , n );
        str.pop_back();
    }
    str.push_back('T');
    fxn( str , i + 1 , n );
    // str.pop_back(); no need 



}

int main()
{
    int n = 3 ;
    string str = "";
    fxn(str , 0 , n);


    return 0;
}
