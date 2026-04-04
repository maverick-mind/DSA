#include <bits/stdc++.h>
using namespace std;
#define  ll long long
ll count_inversion( ll array[] , ll start , ll mid , ll end)
{
    ll i = start ; 
    ll j = mid + 1 ;
    ll ans = 0 ;
   
    vector<ll> temp;
    while(i <= mid and j <= end)
    {
        if(array[i] <= array[j])
        {
            temp.push_back(array[i++]);
        }
        else if(array[i] > array[j])
        {
            //If arr[left] > arr[right], then all remaining elements in left half (from left to mid) will form inversions with arr[right].
            //That’s because both halves are already sorted → so every later element in the left half will also be > arr[right].

            temp.push_back(array[j++]);
            ans += (mid + 1 - i) ;
        }
    }

    while(i <= mid)
    {
        temp.push_back(array[i++]);
    }
    while( j <= end )
    {
        temp.push_back(array[j++]);
    }

    // now copy temp in array
    ll k = 0 ;
    for(ll i = start ; i <= end ; i++)
    {
        array[i] = temp[k++];
    }

    return ans ;

}

ll fxn( ll array[] , ll start , ll end)
{
    // base case 
    if(start >= end)
    {
        return 0 ; 
    }

    ll mid = start + (end - start)/2 ;

    // recurrence relation 
    // left side aur right side ka ans friend dega , 
    ll ans = 0 ; 
    ans = fxn(array ,start , mid ) + fxn(array , mid + 1 , end);
    ans += count_inversion(array , start , mid , end) ; 

    return ans ;

}


int main()
{
    ll t;
    cin >> t;
    char ch;
    //cin.get(ch); // to handle followed space after t ;
    while (t--)
    {
        ll n;
        cin >> n;
        ll array[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> array[i];
        }
        cout << fxn(array, 0, n-1) << endl;

        //cin.get(ch); // space should be there in every n+1th line
    }
    return 0;
}