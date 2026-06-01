#include<iostream>
#include<algorithm>
using namespace std ; 
 
// cmp is a fn that returns a boolean

// cmp will compare two elements of the inp array say a and b
// and it will return true if a is to be placed before b in the
// sorted array otherwise it will return false

bool cmp(char a, char b) {
	// if (a > b) {
	// 	// we want a to be placed before b since we are sorting in dec. order
	// 	return true;
	// }
	// return false;
	return a > b;
} 


int main() 
{
    string s = "xaybc";

    sort(s.begin() , s.end()); // by default sorting is done in increasing order 
    cout<<s<<endl;



    string t = "abxyz";

    // to sort in decreasing order 
    // way 1
    sort(t.begin() , t.end() , greater<char>());
    cout<<t<<endl;

    // way 2
    sort(t.rbegin() , t.rend());
    cout<<t<<endl;
    
    // way 3 
    sort(t.begin() , t.end() , cmp);
    cout<<t<<endl;
  
    return 0 ;
}