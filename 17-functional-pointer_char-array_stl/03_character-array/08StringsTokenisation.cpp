#include<iostream>
#include<cstring>
using namespace std ; 
 
 
int main() 
{
    char str[] = "abc$.345.def.$ankit$raj..hi$ghi";
    char dlim[] = ".$"; //  $ ya . mein se kuchh bhi mill jaaye , kisi bhi order emin mill jaaye , kitni baar bhi mill jaaye , hu split kar denge 
    char * ptr = strtok(str , dlim);
    while(ptr != NULL)
    {
        cout<<ptr<<endl;
        ptr = strtok(NULL , dlim);
    }
    
 
 
 
    return 0 ;
}