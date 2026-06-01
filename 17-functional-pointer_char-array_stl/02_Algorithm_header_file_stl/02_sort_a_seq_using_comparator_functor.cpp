#include<iostream>
#include<algorithm>
using namespace std ; 

// rule in documentation for comparator funciton
// return true if you want a to be ordered before b , otherwise return false 
bool cmp_fxn (int a , int b)
{   // agar hum decreasing order mein sort karna chah rhe hai , then we want ki jab a badaa ho b se to a ka order pahle aaye , aur jab a chhota ho b se to b ka order pahle aaye
    if(a > b){// we want a to be before b since we are sorting in decreasing order 
        return true ;
    } 
    else return false ;

    // OR
    // return a > b ;
}
 
int main() 
{
    int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10 , 17};
	int n = sizeof(arr) / sizeof(int);

    // sorting a sequence in the decreasing order 

    // 1. using a custom comparator , coparator is a function jo hum khud se define karenge , and the comparator funciton will tell the sort ki comparison between 2 elements kaise hame karna hai 

    // sort(arr , arr+n , &cmp_fxn); OR
    sort(arr , arr+n , cmp_fxn);// cpp ke document ke according jab bhi hum sort mein koi comparator pass karte hai tab wo comparator function  hamesha bool return type ka hoga , and kisi bhi time par we will compare 2 values so the comparator function will take 2 parameters as input 


    // 2. using greater<dataType>() function object / functor 
    //sort(arr , arr + n , greater<int>());
      
       
       for (int i = 0; i < n; i++)
       {
           cout<<arr[i] <<" " ;
       }cout<<endl;
 
    return 0 ;
}