#include<iostream>
#include<algorithm>
using namespace std ; 
 
 
int main() 
{
	int arr[] = {10, 10, 20, 30, 30, 30, 40, 40, 50};
	int n = sizeof(arr) / sizeof(int);
    
    // arr[] should be sorted to use the following functions

    int key = 50 ;

    // 1. search for key in sorted sequence in O(logn) using binary search(), if key present -> return true , else return false (will give bool output)
    binary_search(arr , arr+n, key) ? cout<<key<<" exists"<<endl : cout<<key<<" is absent";

    key = 35 ;
    binary_search(arr , arr+n, key) ? cout<<key<<" exists" : cout<<key<<" is absent"<<endl;

    // 2. finding lower bound for a key in a sorted sequence in O(logn) using lower_bound() ,
    // lower_bound() will return address of first element which is greater than or equal to the key 
    int brr[] = {7,10,10,15,15,15,15,21,26,30,30,30,55 , 70};
    int m  = sizeof(brr)/sizeof(brr[0]);
    key = 14 ;// 14 ke baraabar ye iss se just greater element ka address dega lower_bound()
    cout<<lower_bound(brr , brr + m , key) - brr <<endl; 
    // first element >= key 
    key = 10 ;
    cout<<lower_bound(brr , brr + m , key) - brr <<endl;



    // 3. finding upper bound for a key in a sorted sequence in O(logn) using upper_bound()
    //upper_bound() will return the address of element just greater than the key ( not equal to that key , but only greater than the key )
    key = 25;
    cout<<upper_bound(brr , brr + m , key)-brr<<endl;
    // upper_bound returns an iterator pointing to the first element that is > (strictly greater than) the given value.

    // 4. counting the occurance of a key in a sorted sequence in O(logn) --> upper_bound() - lower_bound()
    key = 15 ;
    cout<<upper_bound(brr , brr + m , key) - lower_bound(brr , brr + m , key)<<endl;
 
 
    return 0 ;
}