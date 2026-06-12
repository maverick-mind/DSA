#include<iostream>
using namespace std ; 
 
 
int main() 
{
    // allocate memory for 1D array in the heap memory 

    int * ptr = new int[5]; // int type ka 5 continous memory allocate ho jaayega heap mein , and as heap mein jo 5 continous memory hai wo int type ke hai , thus jo heap return karega 1st byte ka address wo int * pointer mein store hoga 

    *ptr = 10;
    *(ptr+1) = 20; // same as ptr[1] = 20;
    *(ptr + 2 ) = 30;
    *(ptr + 3 ) = 40;

    ptr[4] = 50;

    cout<<*ptr<<endl;
    cout<<*(ptr + 1 )<<endl;
    cout<<*(ptr + 2 )<<endl;

    cout<<ptr[3]<<endl;

    cout<<*(ptr + 4 )<<endl;

    // deallocate memory for 1D array

    delete [] ptr ; // 

    return 0 ;
}