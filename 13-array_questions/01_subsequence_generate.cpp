// what we will do is , corresonding to every element in an array , we will maintain a bit value (0 or 1) 
// if the bit value is 0 --> it means , hum uss element ko consider nahi kar rhe hai subsequence mein 
// if the bit value is 1 --> it means , hum uss element ko consider kar rhe hai subsequence mein 

#include<iostream>
using namespace std ; 

void generate_subsequence(int arr[] , int n)
{
    // 1st step is 0 se le kar 2^n -1 tak jitne number banenge unnko generate karna hai , n is size of array or number of elements in that array
    // to generate 2^n - 1 , we can use (1 << n)
    for (int  num = 0; num < (1<<n); num++)
    {
        // now , iss num ke n bit ki binary par iterate karna hai , 0th bit ke corresonding 0th element of array ,  1st bit ke corresonding 1st element of array ,  2nd bit ke corresonding 2nd element of array , agar Kth bit 1 hua to include kar lo uss corresponding Kth element ko subsequence mein , agar Kth bit 0 hua to exclude kar do corresponding Kth element ko subsequence se
        cout<<num<<" : ";
        for (int  k = 0; k < n; k++)
        {// in this for loop , k < n , we can't write k <= n kyonki agar k , n ke baraabar hua aur tab hamne arr[k] yaani arr[n] ko access karne ki koshish kari to garbage value mill jaayegi 

            // num ke kth bit ka bitwise AND le rhe hai 1 ke saath 
            if(((num >> k)&1 ) == 1) // it means , kth bit setbit(1 hai) hai , tabhi ye condition chalega 
            { 
                cout<<arr[k]<<" ";// kth bit of num is set so include arr[k] in the subsequence 
                // if array has more than 32 elements , it will not work has int datatype can't has more than 32 bits 

            }
        }  cout<<endl;      
    }  
}

int main() 
{
 int arr[] = {10,20,30};
 int n = sizeof(arr)/sizeof(int);

 generate_subsequence(arr ,n);
 
    return 0 ;
}

/* summary 
agar array n size ka hai , to uss ke 2^n subsequences hoonge , unn subsequence ko generate karne ke liye , hum 0 se le kar 2^n -1 numbers par iterate karenge ,fir iss ke andar loop mein ,  unn har ek number ke bits par iterate karenge , agar uss number ki kth bit 1 hoti hai to subsequence mein arr[k] ko include kar lo , agar kth bit 0 hoti hai , to arr[k] ko subsequence mein include mat karo 
*/