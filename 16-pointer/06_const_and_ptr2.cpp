#include<iostream>
using namespace std ; 
 
 
int main() 
{
    int x = 10;
    int * ptr1 = &x ;
    cout<<x<<" "<<*ptr1<<endl;
    (*ptr1)++; // ++ ki precedence jyaada hai * se issliye bracket mein likha (*ptr1);
    cout<<x<<" "<<*ptr1<<endl;

    const int * ptr2 = &x ;
    cout<<x<<" "<<*ptr1<<" "<<*ptr2<<endl;
    //(*ptr2)++; //error as ptr2 is a pointer of const-int type , so it is read only can't be used to modify x  , so ptr2 ke through x modified nahi ho sakta , but it can still be modified throough ptr1
    (*ptr1)++;
    cout<<x<<" "<<*ptr1<<" "<<*ptr2<<endl;

    int * const ptr3 = & x ;//  ptr3 is a const-pointer of int type , it means the address at which the pointer ptr3 is pointing is fixed (i.e. &x) , kal ke ye ptr3 kisi &y ya fir &z ko point karega to error aa jaayega , but it is a int type not const-int type so x can be modified through ptr3 , now through-out it's lifecycle , ptr3 hamesha ek hi location ko point karega
    (*ptr3)++;
    cout<<x<<" "<<*ptr1<<" "<<*ptr2<<" "<<*ptr3<<endl;

    int y = 20;
    ptr1 = &y;
    cout<<*ptr1<<endl;
    ptr2 = &y ;
    cout<<*ptr2<<endl;
   // ptr3 = &y ; //  ERROR as ptr3 const pointer hai int type ka , to throughout it's lifetime ye sirf x ke address ko hi point karega

   //const-pointer to const-int 
    const int *const ptr4 = & x ; // ptr4 is a const-pointer of const-int type , const pointer mmeans ye hamesha ke liye ab x ke address ko hi point karega , const int matlab ptr4 ke through x ke address par padii hui value ko modify nahi kar sakte 

    //error same as ptr2 in line 13 and 15
    //(*ptr4)++; // error , value change nahi kar sakte x ka ptr4 ke through as it is const-int type 

    // error same as ptr3 in line 28
   // ptr4 = &y ; // error , ye const-pointer hai ptr4 , so ye kisi aur address par point nahi kar sakta 

    return 0 ;
}