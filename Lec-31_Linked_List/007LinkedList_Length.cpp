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

void insertAtHead(nodeList * &headRef , int val) 
{                         
    nodeList * n  = new nodeList(val);

    n->next = headRef ;

    headRef = n ; 
}


void printLinkedList(nodeList * head) 
{                       
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

// time : O(n)
// space : O(1)
int computeLengthIterative(nodeList * head )
{
    int i = 0 ; 
    while(head != NULL)
    {
        head = head -> next ;
        i++;
    }

    return i ;
}

// time : O(n)
// space : O(n) due to stack
int computeLengthRecursive(nodeList * head )
{
    // base case 
    if(head == NULL)
    {
        return 0 ; // think it as if head points to NULL then the length of LL is 0
    }

    // recursive case 
    return 1 + computeLengthRecursive(head->next);
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
    cout<<"length of LL by iterative computation : "<<computeLengthIterative(head)<<endl;
    cout<<"length of LL by recursive computation : "<<computeLengthIterative(head)<<endl<<endl;

    insertAtHead(head , 0);

    printLinkedList(head); // 0 10 20 30 40 50
    cout<<"length of LL by iterative computation : "<<computeLengthIterative(head)<<endl;
    cout<<"length of LL by recursive computation : "<<computeLengthIterative(head)<<endl<<endl;

    
    
    return 0 ;
}