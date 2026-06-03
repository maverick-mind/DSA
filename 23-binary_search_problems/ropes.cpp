// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B

#include<bits/stdc++.h>
using namespace std;

/*
Define the bounds :
start : least possible answer in floating value : rope is 1 and its length is 1 and we have to cut it in 100 peices then MaxLengthOfPeices is 0.01 , if k is 1000 , then MaxLengthOfPeices is 0.001
so consider start = 0 , as start could be any floating value nearer to zero

end : max posible answer in floating value : let's say number of ropes could be anything , let's say 100 , and k = 1 , and so , MaxLengthOfPeices is length of longest rope among all the ropes 

so , end = *max_element(ropes.begin() , ropes.end());
*/

bool predicate_fxn(const vector<int> & ropes , int n , int k ,double mid)
{
    // can we cut 'k' peices of length "mid" ropes from "n" ropes

    // mid is the length at which we are checking if 'k' number of peices of ropes are possible or not at this length
    int noppaml = 0 ; // number of peices possible at "mid" length

    for (int i = 0; i < n; i++)
    {
        // if(ropes[i] / mid >= 1 )// ropes[i] badaa hona chahiye "mid" 
        // {                   // "mid" length se , then only ropes[i] can
        //              // be divided into 1 or more peices or "mid" length
        //     noppaml += (ropes[i] / mid) ;
        // }
        noppaml += int(ropes[i] / mid);
    }
    return noppaml >= k ; // agar noppaml jyaada hoga k se then only 'k' peices of "mid" length are possible from n number of ropes 

}

double MaxLengthOfPeices(const vector<int> & ropes , int n , int k)
{
    double start = 0 ;
    double end =*max_element(ropes.begin() , ropes.end()) ;
    double ans = 0 ;
    double moe = 1e-7 ; // as per constraints of question , margin of error is 10^(-6) , but for more precision take  margin of error as 1e-7

    // To avoid "precision issue" , dont't apply while condition (end - start) >= 1e-6
    // instead pre-calculate how many times , the loop will run for the range [start , end] and precision 10-6, and apply for loop for that many number of iterations 

    double numberOfIteratoins = log2((end - start)*1e7);

    // numberOfIteratoins would be less than 100 or 200 , if you calculate log2((end - start)*1e7) based on constraints of given question
    // so if you don't want to think , or want to save some times , just run the loop for 100 times or 80 times 
    
    for (double i = 0; i <= numberOfIteratoins; i++)
    {
        double mid = start + (end - start)/2;

        if(predicate_fxn(ropes , n , k , mid))
        {
            ans = mid ;
            start = mid + moe;
        }
        else{
            end = mid - moe ;
        }
    }
    return ans ;
}
 
int main() 
{
    int n , k ;
    cin>>n>>k;

    vector<int> ropes(n);

    for (int i = 0; i < n; i++)
    {
        cin>>ropes[i];
    }
    double ans = MaxLengthOfPeices(ropes , n , k);
    cout<< setprecision(6) <<fixed <<ans<<endl;
 
    return 0 ;
}