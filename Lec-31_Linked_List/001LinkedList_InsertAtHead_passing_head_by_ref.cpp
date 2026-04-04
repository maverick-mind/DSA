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

// here we are passing head ptr by refrence since we want changes done to head inside the fxn to be reflected in the caller(i.e. int main())
void insertAtHead(nodeList * &headRef , int val) // head pointer is to be passed by refrence 
{                           // then only jo update head mein yahaa hoga 
                            // wo update fxn ke baahar int main() mein reflect hoga 
    //1. create a new node for the val
    nodeList * n  = new nodeList(val);

    //2. connect the new (n) nodeList in front of the remaining Linked List 
    n->next = headRef ;

    //3. now head should point new (n) nodeList
    headRef = n ; // int main mein se head pass kiya aur har baar head ko update bhi kar rhe hai , so no need to return head , or make fxn of nodeList * type 
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
    insertAtHead(head , 50);
    insertAtHead(head , 40);
    insertAtHead(head , 30);
    insertAtHead(head , 20);
    insertAtHead(head , 10);

    if(head == NULL)
    {
        cout<<"linked list is empty"<<endl;
    }

    printLinkedList(head); // 10 20 30 40 50

    insertAtHead(head , 0);

    printLinkedList(head); // 0 10 20 30 40 50
    
    
    return 0 ;
}