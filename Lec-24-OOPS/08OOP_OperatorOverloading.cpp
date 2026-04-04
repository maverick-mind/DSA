#include<bits/stdc++.h>
using namespace std;
 
class customer{

    public :
        string name ;
        int age ;
        char gender ;
        double credits;

        customer(){
            cout<<"we are inside default constructor\n";
        }

        // parameterized constructor 
        customer(string s , int a , char g , double c)
        { 
            name = s; 
            age = a ;
            gender = g;
            credits = c ;
             cout<<"we are inside parameterized constructor\n";
        }

        void print()
        {
            cout<<"name "<<name<<endl;
            cout<<"age "<<age<<endl;
            cout<<"gender "<<gender<<endl;
            cout<<"credits "<<credits<<endl;
        }

        // in line 48  c1 is calling this operator> and c2 is passed in arguement                  
        // operator symbol se pahle waale object ne call kiya operator> ko , operator symbol ke baad waala object jaayega arguement mein 
        bool operator> (const customer & c)
        {
            // age refers to object before operator symbol , c.age refers to object after operator symbol
            // return 32 > 74
            return age > c.age;
            //  c1.age   c2.age  in line 48
        }

        int operator + (const customer & c)
        {
            return age + c.age ;
        }

        // in line 55
        // int operator - (customer & c)
        // {
        //     return age - c.age;
        // }

        // functor
        void operator()(customer c)
        {
            cout<<"inside functor"<<endl;
        }
};


// we can overload operators as non-member functions
int operator-(customer c1 , customer c2)
{
    return c1.age - c2.age ;
}
 
int main() 
{
    customer c1("Ramanujan" , 32 , 'M' , 500) ;
    customer c2("Aryabhatta" , 74 , 'M' , 0) ;

    //internally this is happening :    c1.operator>(c2);
      c1.operator > ( c2)  ? cout<<c1.name<<" is older than "<<c2.name :
              cout<<c2.name<<" is older than "<<c1.name;
     cout<<endl;
    // OR
    c1 > c2 ? cout<<c1.name<<" is older than "<<c2.name :
              cout<<c2.name<<" is older than "<<c1.name;

    // c1.operator+(c2);
    cout<<endl<<"sum of age of both the customers :"<< (c1 + c2) <<endl;


    // we can also overload operators as non-member function 
    // agar customer class mein compiler ko "operator-" nahi milta 
    // then it tries to find function operator-(c1,c2)"by passing c1 , c2 as arguement" , compiler will try to find operator-() in global scope jo 2 customers ko as a arguement le rha ho 

    // the compiler search operator
    // c1.operator-(c2)  // operator- (c1,c2)
    cout<<"difference in age : "<< c1 - c2 <<endl;

    // c1.operator() (c2)
    c1(c2); // calling functor
    // since our customer class overloads operator(),
    // object of customer class is now callable (object ko call kar sakte hai)
    // and is known as function object or functor  

    
 
    return 0 ;
}