// galat socha maine , bahut galat 😂
#include<bits/stdc++.h>
using namespace std ; 
 
int optimalHeight(const vector<int> & acquarium , vector<int> prefixSumHeight , int n , int x)
{

    int start = 0 , end = n -1 ;

    int ans = 0 ; 

    while(start <= end)
    {
        int temp = 0 ;
        int mid = start + (end-start)/2;

        if(mid * acquarium[mid] - prefixSumHeight[mid] >  x )
        {
            end = mid - 1 ;
        }
        else if ((mid * acquarium[mid] - prefixSumHeight[mid] <= x) and mid != 0)
        {
            // store the temporary possible answer 
            temp = mid ; 
            if(temp > ans)
            {
                ans = temp ;
            }
            start = mid + 1 ;
        }
        else if (( acquarium[mid] - prefixSumHeight[mid] <= x) and mid == 0)
        {
            // store the temporary possible answer 
            temp = acquarium[mid] ; 
            if(temp > ans)
            {
                ans = temp ;
            }
            start = mid + 1 ;
        }
    }
    return ans ;
}
 
int main() 
{
    int t ;
    cin>>t;
    while(t--)
    {
        int n , x ;// n --> total columns , x --> maximum water available 
        cin>>n ;
        cin>>x;
        vector<int> acquarium(n,0);
        vector<int> prefixSumHeight(n+1,0) ; // at ith index it will store sum of heights of all corals till ith index , not (i-1)th index
        for (int i = 0; i < n; i++)
        {
            cin>>acquarium[i];
        }
        sort(acquarium.begin() , acquarium.end());
        for (int i = 1; i <= n; i++)
        {
             if(i == 0) prefixSumHeight[i] = acquarium[i] ; 
            else{
                prefixSumHeight[i] = prefixSumHeight[i-1] + acquarium[i-1];
            }
        }
        int h = optimalHeight(acquarium ,prefixSumHeight , n , x ) ; 
        cout<<h <<endl;
    }
 
    return 0 ;
}