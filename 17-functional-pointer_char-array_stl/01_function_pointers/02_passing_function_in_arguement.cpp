#include<bits/stdc++.h>
using namespace std ; 

bool ascending (int a , int b)
{
    return a > b ;// return true if a > b , otherwise return false 
}

bool descending (int a , int b)
{
    return a < b;// return true when b > a otherwise return false 
}

// function ka naam hi funciton ka address hota hai , thus iss address ko ek function type ke pointer mein store karaa sakte hai , for ex. bool (*f_ptr)(int , int) = ascending ;

// if ascending is passed in arguement , 
// then bool (*f_ptr)(int , int) = ascending
// if descending is passed in arguement ,
// then bool (*f_ptr)(int , int) = descending
void bubbleSort(int * arr , int n , bool (*f_ptr)(int , int))
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if(f_ptr(arr[j] , arr[j+1]))
            {
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}
 
 
int main() 
{
    int arr[] = {1,0,3,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    // both calls are same as ascending ya &ascending mein koi fark nahi hai , kyoki function ka naam hi function ka address hota hai    
    bubbleSort(arr , n , ascending);// bubbleSort(arr , n , &ascending);
    // passing ascending function in arguement

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    bubbleSort(arr , n , descending);//bubbleSort(arr , n , &descending);
    // passing descending function in arguement
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
 
    return 0 ;
}