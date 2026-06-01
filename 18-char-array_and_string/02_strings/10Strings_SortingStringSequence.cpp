#include<iostream>
#include<string>
#include<algorithm>
using namespace std ; 

// return true if you want a to be ordered before b 
// otherwise return false 
bool cmp (string a , string b)// ek time pe 2 strings ke bich mein compare hoga , 
{                             // thus 2 parameters 
    // if (a.size() < b.size()) {
    // we want a to be placed before b since we are sorting length-wise in inc. order
	// 	return true;
	// }
	// return false;
    
    return a.size() <= b.size();
}
 
 
int main() 
{
    string arr[] = { "abcd" , "wxy" , "z" , "ef"};// arr[] is by default sorted in lexicographically inc. order
    int n = 4 ;
    
    sort(arr , arr + n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

    sort( arr , arr + n , greater<string>());// here arr[] is sorted in lexicographically dec. order 
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

    // if I want to sort array as per length wise in increasing order 
    // z --> ef --> wxy --> abcd
    sort(arr , arr+n , cmp);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
 
    return 0 ;
}