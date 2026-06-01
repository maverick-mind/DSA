#include<iostream>
using namespace std ; 
 
int main() 
{
    string s1 = "abc";
    string s2 = "def";
     // to concatenate s2 inside s1
     s1.append(s2);

     cout<<s1<<endl;
     cout<<s2<<endl;

     string s3 = "uvw";
     string s4 = "xyz";

     //also used for concatenate string 
     s3 = s3 + s4;//use this over append(...) 

     cout<<s3<<endl;
     cout<<s4<<endl;

     string str = "codin";// we want to add "g" at the end of "codin"
     // way 1 --> str = str + "g"  // string mein string hi add hoga , character add nahi ho sakta that is why we have written "g" not 'g'

     // way 2 string.push_back('g'); push back ek baar mein ek hi character leta hai that is why we wrote 'g' and not "g"
     str.push_back('g');
     cout<<str<<endl;

     str.pop_back();
     cout<<str<<endl;

     string s = "abc";
     cout<<s[0]<<" "<<s.front()<<endl;
     cout<<s[s.size() - 1 ]<<" "<<s.back()<<endl;

     string t ; // by-default a string is empty 
     cout<<t.size()<<endl;

     if(t.size() == 0) cout<<"t is empty"<<endl;

     if(t == "") cout<<"t is empty"<<endl;

     // to check if a string is empty or not 
     if(t.empty()) cout<<"t is empty"<<endl;

     string w = "zoom";
     cout<<w.size()<<endl;

     w.clear();// to make the string empty 

     cout<<w.size()<<endl;


 
    return 0 ;
}