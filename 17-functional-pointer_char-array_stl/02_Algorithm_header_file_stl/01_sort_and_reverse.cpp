#include<iostream>
#include<algorithm>
using namespace std ; 
 
 
int main() 
{
    int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10 , 17};
	int n = sizeof(arr) / sizeof(int);

    // 1. sort a sequence using built-in sort in O(nlogn) // introsort used
    sort(arr , arr+n); // [0 , n)     // by-default increasing sort 
    //  address before comma (,) is inclusive that is arr
    //  address after comma (,) is exclusive that is arr + n

    cout<<"after sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

    // 2. reverse a sequence using built-in reverse()
    cout<<"after reversing : ";
    reverse(arr , arr + n);
     for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

    // 3.reversing a sequence in-range using the built-in reverse()
    cout<<"after reversing a sequence in-range : ";
    reverse(arr+4 , arr + n );
     for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
 
 
 
    return 0 ;
}