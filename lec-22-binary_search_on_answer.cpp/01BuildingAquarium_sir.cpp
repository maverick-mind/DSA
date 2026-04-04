// binary search on answer : search space = upper bound - lower bound
// time : log(search space ka time) * predicate function ka time 


//Binary search + predicate works best jab problem monotonic nature ka ho (like “minimum capacity,” “minimum days,” “smallest x such that condition holds”).
#include<bits/stdc++.h>
 using namespace std ; 
  
// can we do it without fixing upper bound initially , start = 1 se shuru kar agar water contain of acquarium < x hai to start *= 2 , agar bhi bhi kam hai then again start *= 2 



// binary searcch on answer --> ek baar answer nikaal lo fir again attempt karna answer find karne ke liye is called binary search on answer , it takes help of predicate function 
// start aur end , hum constraints ke min aur max value ke according nikaal sakte hai , aur agar test case specific bounds (start to end ) nikaalna possible hua then go for test case  specific 
bool f(int n , vector<int> a , int x , int m)
{
    // can I make a container of heieght 'm' such that my maximum water consumption is x ?
    long long sum = 0 ;
    for (int i = 0; i < n; i++)
    {
        sum += max(0 , m - a[i]);
    }
    return sum <= x ;
}
  
 int main() 
 {
     int t ;
     cin>>t ;


     while(t--)
     {

        int n , x ;
        cin>>n>>x ;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
          cin>>a[i];
        }       

        // 2e9 means 2 * 10^9 , 1e9 means 10^9
        
        int s = 1 ;//from the constraints given in the question , min height is 1
        int e = 2e9 ; // from the contraints , max water is 1e9 , so agar sabse kam width ka container ho to 1 hi column exist karega acquarium mein , aur usski height max ho as per constraints to hogi 1e9 , so agar iss column mein 1e9 water bharna hai so we need a height of 2* 1e9 , agar 1 se jyaada number of columns ho to ye max water 1e9 saare columns mein share ho jaayega aur max height 2*1e9 se kam ho jaayegi

        //cout<<INT_MAX<<" "<< fixed <<2e9<<endl; // 2e9 is smaller than INT_MAX 

        int ans ;

        while(s<=e)// O(log(e-s)*n)
        {
            int m =  s + (e-s)/2 ;

            if(f(n , a , x , m))
            {
                ans = m ;
                s = m + 1 ;
            }
            else{
                e = m - 1 ;
            }
        }
        cout<<ans<<endl;

     }
     return 0 ;
 }