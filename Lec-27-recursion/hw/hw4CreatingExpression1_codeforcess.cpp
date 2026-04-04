#include<bits/stdc++.h>
using namespace std;
 
bool fxn( long long A[] , int N , int X , int i , long long & ans )
{
    // base case 
    if(i == N)
    {
        // if(ans == X) return true ;

        // else{
        //      return false ;
        // }
        return (ans == X);
    }

    // recurrence relation
    // bool check = false  ; 
    // after each element , we have two choices 
    // 1. either +(plus) operation
    // 2. or -(minus) operation

    // 1. 
    // if(check == true) return true ;
    
     // Try addition first
        ans += A[i]; 
    
    // check = fxn( A , N , X , i + 1 , ans );
    //if(check == true) return true ;
    if(fxn( A , N , X , i + 1 , ans ))
    {
        return true ; //  IMMEDIATE RETURN - No further calculations!
    }
    // backtracking 
    ans -= A[i]; // backtrack only if first branch failed

    //2.  // Try subtraction only if addition branch failed
        ans -= A[i]; 
//    check =  fxn( A , N , X , i + 1 , ans );
//    if(check == true) return true ;
      if(fxn( A , N , X , i + 1 , ans ))
      {
        return true ; //  IMMEDIATE RETURN - No further calculations!
      }

      ans += A[i]; // // backtrack only if both branches failed

   // Both branches failed
   return false ; //  agar upar kahi bhi true nahi aaya , matlab true nahi hua hai then return false 
}
 

int main() 
{
    int N ;
    cin>>N ;
    int X ;
    cin>>X;
    long long A[N] ;
    
    for (int i = 0; i < N; i++)
    {
        cin>>A[i];
    }

    // symbol +(plus) ys -(minus) hamesha in between aayega , so 0th element ke pahle hamesha + hi rahega , so pahli baar fxn mein + pass karo do 
    long long ans = 0 ;
    if(fxn( A , N , X , 0 , ans  ))
    {
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0 ;
}