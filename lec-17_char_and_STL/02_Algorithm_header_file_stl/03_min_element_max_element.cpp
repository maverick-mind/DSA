#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ; 
 
 
int main() 
{
    int arr[] = {50, 40, 40, 30, 30, 30, 20, 3 , 10, 10 };
	int n = sizeof(arr) / sizeof(int);

    // 1. finding the minimum value in a sequence 
    //min_element(starting_address , ending_address);// [starting_address , ending_address) ;  this function will return address of the minimum element , so we have to derefrence it to get the value at that address 
    cout<<*min_element(arr , arr + n)<<endl;

    // 2. finding the maximum value in a sequence 
    cout<<*max_element(arr , arr + n)<<endl;



    vector <int> v = {10 , 35 , 7 , 1000 , 300 , 50};
    cout<<*min_element(v.begin() , v.end())<<endl;
    cout<<*max_element(v.begin() , v.end())<<endl;
    
 
 
 
    return 0 ;
}