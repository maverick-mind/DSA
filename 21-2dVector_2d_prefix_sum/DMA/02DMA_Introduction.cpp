#include<iostream>
using namespace std ; 
 
 
int main() 
{
      int * ptr = new int ; // creating int type memory in heap , aur usska address ptr ko de rhe hai
      *ptr = 39 ; // ptr jiss ko point kar rha hai wahaa par 39 daal diya
      cout<<*ptr<<endl;

      delete ptr ; // to avoid memory leak , c++ mein "GARBAGE COLLECTION" nahi hoti so we have to free up the heap memory manually 
      
      ptr = new int ;
      *ptr = 44 ;
      cout<<*ptr<<endl;

        char *chptr = new char ;
        *chptr = 'A';
        cout<<*chptr<<endl;

        double *dptr= new double;
        *dptr = 3.14 ;
        cout<<*dptr<<endl;
 
 
    return 0 ;
}