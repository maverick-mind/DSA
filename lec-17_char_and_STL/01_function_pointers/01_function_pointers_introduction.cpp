// jo functions hote hai in cpp unke bhi addresses hote hai aur unn addresses ko hum save kar sakte hai aur jahaa par hum save karenge (or jis variable mein hum save karenge ) that is called a function-pointer 
// for variable , if we have to access it's address we do &name_of_variable
// for ex. int x = 35 ; address of x --> &x
// in the same way address of function --> &Function_Name
// but agar hum address print karaaye kisi function ka to wo hamesha true ya 1 print karta hai , address pta karne ke liye we can do TYPECASTING
// you can do typecasting in any type (void*),(bool*), (int*), (float*), (double*), (char*) <-- char mein thoda pangaa hoga , 


// for normal variable , address of operator jaruri hota hai address print karne ke liye , for ex. &x ya &y
// but function ke case mein address of operator lagaana optional hota hai , hum iss ke bina bhi likh sakte hai , (void*)greet

#include<bits/stdc++.h>
using namespace std ; 
 
void greet()
{
    cout<<"namaste"<<endl;
}

int add (int a , int b)
{
    return a+b;
}
bool ascending(int a , int b)
{
    return a > b ; // return true if a > b , otherwise return false 
}
 
int main() 
{
    cout<<&greet<<endl;// ye boolean true ya 1  print karta hai 
    // so to print address , do typecasting
    cout<<greet<<endl;// addresss 1 degaa 
    cout<<(void*)&greet<<" "<<(void*)greet<<endl;// bina & (address of operator) ke address print ho sakta hai 
    cout<<(int*)&greet<<endl;
    cout<<(char*)&greet<<endl;
    cout<<(double*)&greet<<endl;
    cout<<(bool*)&greet<<endl;
    
    cout<<endl<<(void*)&add<<" "<<(void*)&add<<endl;
    cout<<endl<<(void*)&ascending<<" "<<(void*)&ascending <<endl;

    // ab iss function ke address ko kis type ke pointer variable mein store karenge 

    void (*greet_ptr) () = &greet; // greet_ptr is a pointer to a function that takes no arguement and has void return type 

     int (*add_ptr) (int , int )  = &add; // add_ptr is a pointer to a function which takes 2 integers in arguement and has int return type

     bool (*asc_ptr) (int , int) = &ascending ; // asc_ptr is a pointer to a function which have 2 integer in arguement abd the function is of bool return type

     cout<<"greet_ptr pointer : ";
     cout<<greet_ptr<<endl;// addrees of function bina typecasting ke 1 print karta hai 
     cout<<(void*)greet_ptr<<endl;// typecasting of address of function

     cout<<"add_ptr pointer : "<<(void*)add_ptr<<" "<<(void*)add<<endl;
    cout<<"asc_ptr pointer : "<<(void*)asc_ptr<<" "<<(void*)&ascending<<endl;


    // function call using it's pointer , using derefrence operator is optional in pointers while calling function
    
    // (*greet_ptr) () is as same as greet ()
     (*greet_ptr) ();// agar derefrence operator use kar rhe hai , then keep *greet_ptr inside bracket kyonk bracket ki precence jyaada hai * se so agar (*greet_ptr) na kare to greet_ptr() pahle chalega fir * chalega aur wo wrong ho jaayega
     greet_ptr();
     greet();
     // function ka naam is address of the function (same ki array ka naam array ke 0th location ka address hota hai), so derefrecing that address to call that function will also work , in the next line 
     (*greet)();

     //(*add_ptr) (3,5) is as same as add(3,5)
     cout<<(*add_ptr) (3,5)<<"  "<<add_ptr(3,5)<<"  "<< add(3,5)<<endl;
     cout<<(*add)(3,5)<<endl;

     //(*asc_ptr) (2,4) is equivalent to ascending(2,4)
     cout<<(*asc_ptr) (2,4) <<"  "<<(asc_ptr)(2,4)<<"  "<<ascending(2,4) <<endl;
     cout<<(*ascending)(2,4)<<endl;
    
    return 0 ;
}