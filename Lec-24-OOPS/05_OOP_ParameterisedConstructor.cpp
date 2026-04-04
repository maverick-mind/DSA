#include<bits/stdc++.h>
using namespace std;
 
class customer{

    public :
        string name ;
        int age ;
        char gender ;
        double credits;

        customer(){// agar khud ka constructor likh diya , to default in-built constructor nahi milega , so when we create a parameterized constructor , to default constructor bhi likhna padega , if we want to call like obj() , bina default constructor khud se likhe agar obj() karoge to error dega , issliye it is important ki agar hamee class mein parameterized constructor rakhna hai , aur kal ko uss class ka ek object create karna hai jo default constuctor ko use karta hai to hamee default constructor bhi banaana padega 
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
};
 
int main() 
{
    customer c1("rohan" , 20 , 'M' , 500) ;

    // c1.name = "rohan";
    // c1.age = 20;
    // c1.gender = 'M';
    // c1.credits = 500;

    c1.print();

    customer c2 ;// agar class mein parameterized constructor hai , to default bhi khud se likhna padta hai , else agar default khud se nahi likhenge to error dega 
    
 
 
 
    return 0 ;
}