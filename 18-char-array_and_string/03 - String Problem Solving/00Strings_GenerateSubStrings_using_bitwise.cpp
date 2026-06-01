#include<bits/stdc++.h>
using namespace std ; 
 
 
int main() 
{
    string s = "abc";
    
    // first find length of s 
    int n = s.size();
    // in binary format , start with 0 and go till n-1 (each digit of binary will tell wether to include that character into substring or not , 1-->include ,    0 --> exclude it ),in binary 2^0 to 2^n-1 will generate all possible substring 
    
    for (int i = 0; i < (1 << n); i++)
    {
        for (int k = 0; k < n; k++)
        {
            if((i >> k )& 1)
            {
                cout<<s[k]<<" ";
            }
        }
        cout<<endl;
    }
 
 
    return 0 ;
}