#include<iostream>
#include<climits>
#include<string>
#include <typeinfo>
using namespace std ; 
 
 
int main() 
{
    string s = "abcbcbcd";
    string t = "cb";

    cout<<typeid(s.size()).name()<<endl;//size() function return type is size_t , that is why it's type is unsigned int or unsigned long ,  j stands for unsigned int , m stands for unsigned long 

    cout << s.find(t) << endl; // returns starting index of 1st occ. of t in s
    cout << s.rfind(t) << endl; // return starting index of last occ. of t in s
    
    string w = "xy";
    cout<<s.find(w) <<endl;// agar w as a substring string s mein nahi mila to hamee , to ye find() function size_t ki largest value return karta hai 

    cout<<string::npos<<endl;// returns as same as what find() function return if substring does not found

    cout<<(s.find(w) == -1)<<endl;// it will print 1 or true 

    // if a substring is not present inside a string , we can handle it like this
    if(s.find(w) == string :: npos) // OR if(s.find(w) == -1)
    {
        cout<<w<<" is not present in "<<s<<endl;
    }
    else{
        cout<<s.find(w)<<" is the starting index of "<<w<<" in "<<s<<endl;
    }


    // some more datatypes
    // int32_t <-- make sure int is of 32 bits
    // int64_t <-- make sure int is of 64 bits
    // size_t <--  a variable of size_t type is used to store unsigned integers 
                // i.e. non-negative integers , i.e. >= 0
    // if 8 bytes(64 bits) is allocated to size_t ,
    // then size_t range would be (0 , 2^64 - 1)
    // and binary of 2^64 - 1 looks like 11111...111 (all ones)
    // also binary of 2^64 - 1 looks like 11111...111 (all ones)

    // what does the binary of -1 looks like 111111....1 ( all ones) --> signed bit is 1 and rest all other bits are also 1 
    // so on 64 bit compiler or a 32-bit compiler when we print 
    // cout<<(s.find(w) == -1 )<<endl; it will gve true as output 

        cout<<(s.find(w) == -1)<<endl;// it will print 1 or true 

    // cout<<sizeof(size_t)<<endl;// in my compiler it is showing 4 bytes 

    // cout<<ULLONG_MAX<<endl;// it is 2^64 - 1 

    return 0 ;
}


/*
Since "xy" doesn't exist in s, s.find(w) returns **string::npos**.

🧠 What is string::npos?
string::npos is a constant that represents "not found" in C++.
Its value is:  static const size_t npos = -1;

And since size_t is an unsigned integer, -1 becomes the maximum possible value of size_t, which is: 4294967295  // on a 32-bit system
                  18446744073709551615. // On a 64-bit system


🧩 Tip: If you want to handle it gracefully:
size_t pos = s.find(w);
if (pos == string::npos)
    cout << "Substring not found" << endl;
else
    cout << "Found at index " << pos << endl;

*/



/*

🔹 std::string::npos — What Is It?
std::string::npos is a constant in C++ that represents “not found” in string operations like .find() or .rfind().

It is defined as:

static const size_t npos = -1;
🔍 Key Properties:
Property                        	Value
Type	       --------------->     size_t (unsigned integer)
Value	       --------------->    -1 (which becomes max value of size_t)
32-bit system  ---------------> 	4294967295
64-bit system  ---------------> 	18446744073709551615
Meaning        ---------------> 	“No match found” in .find() etc.



🧠 Why use -1 for npos?
Because:

size_t is unsigned, so -1 wraps around to the maximum value.

This value will never be a valid index, so it's a safe indicator of “not found”.


⚠️ Common Mistake:
if (s.find("abc") == -1) // ❌ Don't do this
Why wrong? -1 is signed → implicitly converted to size_t → becomes 4294967295, so it might accidentally work but it's bad practice.

if (s.find("abc") == string::npos) // ✅


*/