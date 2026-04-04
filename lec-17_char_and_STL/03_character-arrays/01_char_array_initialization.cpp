#include <iostream>
using namespace std;

int main()
{
    //initialization method 1 

    char str[] = {'a', 'b', 'c', 'd', 'e' , '\0'};// initialization
    // insert NULL at the end '\0', sequence of character is string , and string must be NULL terminated 

    // str is name of the array , so it is also pointer to the first element of the char-array , now because our first element is character , so we can say that str is actually like a character pointer , it stores address of a character , and because it stores address of a character , and we know that jab hum kisi character ka address print karte hai , to wo address print nahi hota , us address par jo value hai wo print hoti hai aur hum tab tak print karte hai jab tak hamko memory mein NULL nahi mill jaata , so in character array , we need to insert NULL at the end of the character array so that cout<<str; karne par abcde ke baad koi garbage value na aa jaaye
 
    cout<<str<<endl;// bina loop ke bhi kaam karega 

    // initialization method 2 --> when you initialize a character array with string literal , '\0' is added automatically 

    char str2[] = "Coding"; // jab aisee initialise karte hia double quotes ke andar then this is thing inside double quotes is called as string literal , aur iss mein '\0' lagaane ki need nahi hai , wo automatically handle ho jaata hai , '\0' is added automatically

    cout<<str2<<endl;

    for (int i = 0; str2[i] != '\0'; i++)
    {
        cout<<str2[i]<<endl;
    }

    return 0;
}