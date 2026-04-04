#include<iostream>
#include<algorithm>
using namespace std ; 
 
 
int main() 
{
    int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	int key = 30;

    //21. searching for the first occurance of a key in a sequence
    //    using find(starting_indx , end_indx , key)
    // if key is present , find() uss key ke  first occurance ka address waapas dega , agar key nahi mila find() ko to ye last element ke baad waala address la kar dega 
    
    auto it  = find(arr , arr + n , key) ; // ye address dega 
    // auto keyword --> depending upon ki kis type ka datatype aa rha hai variable it ke andar , compiler apne aap deduce kar lega ki it ka type hona kya chahiye , for ex , auto y = 3.14 ; yahaa compiler khud se samajh jaayega ki y is a float type ka variable 

    // to caclulate index 
    cout<< (it - arr)<<endl;
    cout<<&(arr[4]) - &(arr[0])<<endl;//why it gives 4 instead of giving 4*sizeof(arr[0]);??
    // Because pointer subtraction is done in UNITS of elements, not BYTES.


     it = find(arr , arr + n , 135);
     if( it == arr + n)
     {
        cout<<135<<" is not present"<<endl;
     }
     else{
        cout<<it - arr<<" is index of "<<135<<endl;
     }


    // 2.counting the occurance of a key in a sequence using count()
    auto occurance = count(arr, arr+ n , 30);
    cout <<"occurance of "<<30 <<" is "<<occurance <<endl;
    
    return 0 ;
}