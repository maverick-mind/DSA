#include<bits/stdc++.h>
using namespace std ; 
 
// hum cpp mein jaggered 2-d array banaa sakte hai , which means ki har row mein different number of elements 
// for ex.  10 15 20
//          30 35 40 45 50
//          60 70
 
int main() 
{

    int m , n  ;
    cin>>m>>n;

    // v is not a vector of integer , v ek vector hai jiss ka har element khud mein ek vector hai 

    // by-default it is filled with 0s , garbage nahi hota vector ke andar 
    vector<vector<int>>  v(m , vector<int>(n) );// v is a vector jo m size ka hai , ab iss ka har element is a vector of integer vector<int>(n) aur wo n size ka hai  , so we have vector v of size (m x n)

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>v[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
 
    // to find number of rows 
    cout<<v.size()<<" "<<m<<endl;

    // to find number of columns 
    cout<<v[0].size()<<" "<<n<<endl;
 
 
    return 0 ;
}