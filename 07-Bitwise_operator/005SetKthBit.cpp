#include<bits/stdc++.h>
using namespace std;
 
 
int main() 
{
    int n = 42 ;
    int k = 4 ; // output : 58 for n : 42 and k : 4

    // choose a mask , whoose bitwise or would do the work 
    // so mask would be : make kth bit 1 and rest other bits as 0 

    int mask = 1 << k ;

    cout<< (n | mask)<<endl;


    // int kk = k ;

    // int mask = 1;

    // int temp = 0 ; // to temporarily store all the right bits from kth bit 

    // while(k--) // remove all the right bits from the kth bit 
    // {
    //     // extract the lsb 
    //     int lsb = (n & mask) ; 
    //     n = n >> 1 ; // right shift n by single bit

        
    //     temp = temp << 1 ; // left shift temp by single bit
    //     temp = temp | lsb ; // insert lsb in the end of temp 
    // }

    // // now , here , the lsb is the kth bit 

    // // set the kth bit 
    // n = n | mask ;

    // // now , start putting temp by doing left shift of n 

    // while(kk--)
    // {
    //     // extract the lsb of temp ;
    //     int lsb = (temp & mask) ; 

    //     temp = temp >> 1 ; // right shift temp by single bit 

    //     // left shift n by single bit 
    //     n = n << 1 ;

    //     n = n | lsb ; // insert lsb in the end of n 
    // }
 
    // cout<<n<<endl;
 
 
    return 0 ;
}