#include<bits/stdc++.h>
using namespace std;
 

// the mask is a 32 bits integer and every bit of this integer stores an information that , the element corresponds to that bit position is used or not 

// bit : 1 --> element used 
// bit : 0 --> element not used 

// the bitmask method can only be used for array of size at maximum 64(long long) or 32(int)


void fxnRec(string & str , int i , int n , int bitmask , string ans )
{

    // base case 
    if(i == n) // or bitmask == (1 << n) - 1 ; basically bitmask == 2^n - 1
    {
        cout<<ans<<" , ";
        return ;
    }

    // recurrence relation 

    // for putting a character on ith position , we have to iterate over all the bits of mask , among all those bits , the position of bit where we have 0 corresponds to available choices we have for ith location 

    // iterate over all the bits of mask 
    int j = 0 ; 
   
    while(j < n)
    {
        // check if jth bit is 0 or 1
        int jthBit = (bitmask >> j) & 1 ;

        if(jthBit == 0) // available to be used 
        {
            ans.push_back(str[j]) ; 

            // after using , set the jth bit as 1 
            fxnRec(str , i + 1 , n , bitmask | (1 << j) , ans) ; 
            ans.pop_back() ;
        }
        // else if jthBit == 1 , just look for next bit 
        j++;
    }


}


int main() 
{
    string str = "abc" ; 
    int n = str.size() ;

    // to go to all the permutations of str , we need 4 bits 
    int bitmask = 0 ; // initiallsy to select the element for the 0th position , we have all the choices available , because all the bits are 0 at this time 

    fxnRec(str , 0 , n , bitmask , "") ; 
 
 
    return 0 ;
}