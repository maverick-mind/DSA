// creating our own vector , user se tab tak input lo jab tak -ve input na mill jaaye 
// initially , capacity --> c = 1 ;
//                 size --> s = 0 ;


#include<iostream>
using namespace std ; 

// return type is int * kyonki ek pointer jo int * type ka hai uss ko return kar rhe hai iss function ke through 
int *resize(int * A , int c )
{
    cout<<"resizing from "<<c*(sizeof(int))<<"bytes to "<<2*c*(sizeof(int))<<"bytes"<<endl;
     int *temp = new int[2*c];// creating a new memory in heap of 2 * c (double the original size )
            for (int i = 0; i < c; i++)
            {
                temp[i] = A[i]; // copying older array to new array
            }
           // now delete older array ;
           delete [] A;

        return temp;// returning the address of new memory created in heap of double size 

}
 
 
int main() 
{
    int * A = new int[1]; // initial capacity of array is 1 
    int c =  1; // to store the maximum capacity of the dynamic array
    int i = 0 ; // to store the size of the dynamic array 

    int x ; // to store the integer value read from the user 
    while(true)
    {
        cin>>x ;
        if(x < 0 )
        {
            break;
        }
        if(i == c) // resize ;
        {  
            // after resizing 

            // now shift to new address from what pointer A was pointing in the heap earlier  
            A = resize(A , c) ;
            c = 2*c ;
        }

        A[i] = x;
        i++;
    }
    
    // print the dynamic array 
    for (int j = 0; j < i; j++)
    {
        cout<<A[j]<<" ";
    }
 
    return 0 ;
}