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

        ~customer(){ // object creation and destruction is on stack , jo object sabse pahle create hoga , uss ka destructor sabse last mein chalega 
            cout<<"\nwe are inside destructor customer class destructing the memory allocated for "<<name;
        }
};
 
int main() 
{
    customer c1("AAAAAAAA" , 20 , 'M' , 500) ;
    c1.print();

    cout<<endl; 
    customer c2("BBBBBBBB" , 20 , 'M' , 500) ;
    c2.print();

 
 
    return 0 ;
}