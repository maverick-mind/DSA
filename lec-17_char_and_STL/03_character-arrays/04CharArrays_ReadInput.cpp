#include<iostream>
using namespace std ; 
// '\n' is the default delimiting character 
 
// constraints : n = 100 ( user will give 100 character in input), so make char str[101] of size 100 + 1 

int main() 
{
    char str[101];// based on constraints 

//    cin>>str ;
    // cin ignores leading whitespaces
    // cin stops as 1st non-leading whitespaces 

// to read white spaces --> cin.getline()
    // syntax of cin.getline()
    // cin.getline(string_name , delimiter_size , optional_stopping_character)
    // delimitter_size --> represents ki hum kitna byte of data read karna chahte hai includeing (NULL '\0')
    // optional_stopping_character or delimiting character  --> ye character encounter hoote hi ruk jaana hai 
    
    //cin.getline(str , 101 , '\n');// '\n' is the default delimiting character 
    //ex hello world@ // this 101 represents ki hum kitna byte of data read karna chahte hai includeing (NULL '\0')

    cin.getline(str, 9 , '@');// ex : hello world@
    // 9-1 byte for user input , 1 byte for '\n'



    cout<<str<<endl;




 
 
 
    return 0 ;
}



/*
🔹 cin.getline() vs cin.get()
Feature	             cin >>	    cin.get()      	cin.getline()
Skips whitespace	 ✅ Yes 	   ❌ No	           ❌ No
Reads by character	 ❌ No	    ✅ Yes	       ✅ Yes (as line)
Handles delimiters	 ❌ No	    ✅ Yes          ✅ One delimiter 
                                (you check)        	(default \n)

Reads spaces	     ❌ No	   ✅ Yes	       ✅ Yes
*/