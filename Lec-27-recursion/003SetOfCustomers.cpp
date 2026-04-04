#include<bits/stdc++.h>
using namespace std;
 
class customer{

    public :
    string name ;
    int age ;
        customer(string name , int age)
        {
            this->name = name ;
            this->age = age ; 
        }
};

class customerAgeCmp{

    public :
        // return true if you want a to be ordered before b , otherwise return false 
        bool operator()(customer a , customer b) const {

            return a.age < b.age ; // we want a to be ordered before b , since we are sorting the set<> in increasing order based on customers age 
        }


}; 
 
int main() 
{
    //set<customer> s ;// we don't exactly know how to order customer , so it will give error 

    set<customer , customerAgeCmp > s ; 


    s.insert(customer("ABC" , 10));// annonymous object , hamne customer class ka koi object nahi banaaya , directly insert kiya hai 
    s.insert(customer("DEF" , 22));
    s.insert(customer("GHI" , 33));
    s.insert(customer("JKL" , 44));

    for(customer c : s)
    {
        cout<<c.name<<" "<<c.age<<endl ;
    } cout<<endl;
    
    // make sure iterator passed to the erase() fxn is valid , if it is not valid , you get an error 
    s.erase(s.begin());// iterator se delete kar sakte hai , but if iterator does not exist then ye erroe de dega , like if s.begin() does not exist to ye error de dega 

     for(customer c : s)
    {
        cout<<c.name<<" "<<c.age<<endl ;
    } cout<<endl;

    //s.erase(s.begin() + 1 ); // this is not allowed in set , as set is internally tree , not array or continous memory 
    // to fix this 
    auto it = s.begin() ;
    it++;
    s.erase(it);

    for(customer c : s)
    {
        cout<<c.name<<" "<<c.age<<endl ;
    } cout<<endl;
 
 
    return 0 ;
}