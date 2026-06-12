#include<bits/stdc++.h>
using namespace std;
 
class customer{

    public :
    string name ;
    int age ;
    char gender ;
    double credits ;
};
 
int main() 
{
    customer c1; // c1 is a variable of customer type
    c1.name = "rohan";
    c1.age = 20;
    c1.gender = 'M';
    c1.credits = 500;
    cout<<c1.name<<endl;
    cout<<c1.age<<endl;
    cout<<c1.gender<<endl;
    cout<<c1.credits<<endl;
    
 
 
 
    return 0 ;
}