#include<bits/stdc++.h>
using namespace std;
 
class nodeList{

    public : 
        int val ; 
        nodeList * next ;

        nodeList(int val)
        {
            this->val = val ;
            this->next = NULL ;
        }
} ;


nodeList * insertAtHead(nodeList * head , int val) // here we are passing head ptr 
{                                                      // by value not by refrence 
    //1. create a new node for the val
    nodeList * n  = new nodeList(val);

    //2. connect the new (n) nodeList in front of the remaining Linked List 
    n->next = head ;

    //3. now head should point new (n) nodeList
    head = n ; // return this head to main fxn coz it is passed by value and we want changes made here to be reflected in caller fxn(i.e. int main() here )
}

// here we are passing head ptr by value since we don't want changes done to head inside the fxn to be reflected in the caller fxn(i.e. int main() here)
void printLinkedList(nodeList * head) // head pointer is not passed by refrence , 
{                           // issliye directly head se traverse kar sakte hai 
                            // koi nayaa pointer banaane ki zarurat nahi hai
    if(head == NULL)
    {
        cout<<"LL is empty before calling printLinkedList function"<<endl;
    }

    while(head != NULL)
    {
        cout<<head->val<<"-->";
        head = head->next ;
    }
    cout<<"NULL"<<endl;
}


int main() 
{
    nodeList * head = NULL ; // initially jab linked list create nahi hui hai then
                             // head is pointing to NULL
    head = insertAtHead(head , 50);
    head = insertAtHead(head , 40);
    head = insertAtHead(head , 30);
    head = insertAtHead(head , 20);
    head = insertAtHead(head , 10); 

    printLinkedList(head); // 10 20 30 40 50

    return 0 ;
}