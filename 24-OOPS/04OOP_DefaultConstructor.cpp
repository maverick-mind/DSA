#include<bits/stdc++.h>
using namespace std;
 
class customer{

    public :
        string name ;
        int age ;
        char gender ;
        double credits;

        customer(){// constructor has no return type , and it is of same name as class , and default constructor is zero arguements constructor
            cout<<"we are inside default constructor\n";
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
    customer c1 ;

    c1.name = "rohan";
    c1.age = 20;
    c1.gender = 'M';
    c1.credits = 500;

    c1.print();
    
 
 
 
    return 0 ;
}