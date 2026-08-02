#include<bits/stdc++.h>
using namespace std;
 
class customer{

public : 
    string name ;
    int age ;
    double credits ; 

    customer(string name , int age , double credits)
    {
        this->name = name ;
        this->age = age ;
        this->credits = credits ;
    }

};

// The comparator for heap can be a "function pointer" or a "function object"
// so , if we go with the option : "function object" : create a class : "ageComparator"

//inside that "ageComparator" class , we will overload function call operator i.e. --> ()
// i.e. operator() , 
// by overloading function call operator inside the class ageComparator , 
// we can say that , the object of the class ageComparator will be a "FUNCTION OBJECT" , because it will be "CALLABLE"

// Functor (Function Object) : an object that behaves like a function because of function call operator () overloading 
// comparator of min-heap returns whether a has lower priority than b. This often feels reversed compared to sort ,
// for min heap , we want smaller number priority to be more than larger number 
class ageComparator{

public : 
    // return true if you want a to be ordered before b 
    // otherwise return false  
    bool operator()(customer a , customer b) // we want the object of ageComparator class
    { // to be a function object , for that we need to overload the function call operator 

        // when a.age is greater than b.age , a should go below b 
        return a.age > b.age ; // in min-heap , we want priority of smaller age to be higher than priority of larger age 

        // Should a come after b (i.e., does it have lower priority)?
        // for min-heap : 
        // Return true → "a should go below b."
        // Return false → "a can stay above b."
    }

};
 
int main() 
{
    // build a min-heap based on customer's age 

    // priority_queue<int , vector<int> , greater<int>> m ; 

    // as all elements in the heap is customer , so the datatype of heap would be : customer
    // as all elements in the heap is customer , so the internal representation of the heap would be either of vector/deque of customer 

    priority_queue<customer , deque<customer> , ageComparator > hp ; // just pass the type of the comparator class i.e. ageComparator class , making object of this class , calling that object and comparing customers will be handled by priority_queue internally 

    hp.push(customer("rohan" , 20 , 500)) ;
    hp.push(customer("stuti" , 19 , 400)) ;
    hp.push(customer("ajay" , 21 , 1000)) ;
    hp.push(customer("aarish" , 22 , 50)) ;
    hp.push(customer("megha" , 18 , 700)) ;

    cout<<hp.size()<<endl;

    while(!hp.empty())
    {
        customer c = hp.top() ;
        cout<<c.name<<" "<<c.age<<" "<<c.credits<<endl;
        hp.pop() ;
    }

    cout<<endl;

    cout<<hp.size()<<endl; // size : 0 


    return 0 ;
}