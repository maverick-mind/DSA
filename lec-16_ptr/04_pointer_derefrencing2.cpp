#include<iostream>
using namespace std ; 
 
 
int main() 
{
    int x = 65 ;// only x <= 127 will give true value if char * ptr is used 
    char * ptr = (char *)&x ;// char ptr generally saves address of character and that is 1 byte or 8 bits so max value it can store it 2^8-1 and that is 127 , so if we store integer greater than 127 it may show wierd values rather than actual value stored in integer 
    cout<< *ptr;// without typecasting ans is A (ascii value of 65)
    cout<< (int)*ptr;// typecasting of A in int is 65 
 
 
 
    return 0 ;
}