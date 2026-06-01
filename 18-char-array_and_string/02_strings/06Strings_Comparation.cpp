#include<iostream>
using namespace std ; 
 
 

int main() 
{
    string s1 = "afc";
    string s2 = "abczzzz";
     
    // string comparision manually bhi ho sakta hai , as relational operator works with string object 
    if(s1 > s2)
    {
        cout<< s1 <<" > (more than) "<<s2<<endl;
    }
    else if(s1 < s2)
    {
        cout<< s1 <<" < (less than) "<<s2<<endl;
    }

    else{
        cout<<s1<<"== ( is equal to ) "<<s2<<endl;
    }

    // in-built string comparison
    int ans = s1.compare(s2);
    if(ans > 0)
    {
        cout<< s1 <<" > (more than) "<<s2<<endl;
    }
    else if(ans < 0)
    {
        cout<< s1 <<" < (less than) "<<s2<<endl;
    }

    else{ // ans == 0
        cout<<s1<<"== ( is equal to ) "<<s2<<endl;
    }

    cout<<s1.compare(s2)<<endl; // generally +1 --> (s1 > s2) ; -1 --> (s1 < s2) ; 0 --> (s1 == s2)
    // it can possibly return the difference between ascii values b - d = -2, first character jahaa par dono string mein difference aa jaaye , ye unn characters ka difference deta hai 
    
    return 0 ;
}  