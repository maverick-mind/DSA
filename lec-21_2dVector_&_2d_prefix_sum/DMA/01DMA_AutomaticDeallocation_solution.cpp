#include<iostream>

using namespace std;

// int* f() {
// 	int x = 10;
// 	return &x;
// }

int* f() {// to solve DANGLING POINTER issue , heap mein memory allocate kar do , taaki function f() ka call stack empty bhi hoga tab bhi f() ke andar ke variables jinnki values heap mein hai unnki value ko access kar sakee  

        // new keyword ke help se heap mein memory allocate karte hai
       int *ptr  = new int ;// R.H.S. new int , heap ke andar ek int ke size ka memory allocate kar dega , aur uss memory ka address return karega , now uss int type ke data ke address ko ek int * type ke pointer mein store kar sakte hai 

       *ptr = 10 ; // ab uss heap address jiss ko ptr point kar rha hai , uss mein 10 daal do 

       return ptr ; // heap meory ko manually deallocate karna hota hai , khud se free nahi hota , thus agar return ptr; karenge to koi dangling pointer ka issue nahi ayega even if function f() ka call stack empty bhi ho jaaye 

}


int main() {

	int* xptr = f();
	cout << *xptr << endl;

	return 0;
}

