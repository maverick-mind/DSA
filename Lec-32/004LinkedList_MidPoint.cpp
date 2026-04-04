#include<bits/stdc++.h>
using namespace std;
 

class nodeList{

public :
// attributes of nodeList 
    int val ;
    nodeList * next ;

// parameterized constructor 
    nodeList(int val)
    {
        this-> val = val ;
        this-> next = NULL;
    }
};
 
void insertAtHead( nodeList * &head , int val )
{
    // create a memory on heap 
    nodeList * n = new nodeList(val);

    // insert at head 
    if(head == NULL)
    {
        head = n ;
        return ;
    }
    else if(head != NULL)
    {
        n->next = head ;
        head = n ;
    }
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
        head = head ->next ;
    }
    cout<<"NULL"<<endl;
}
nodeList * findMidPoint(nodeList * head )
{
    if(head == NULL) return head ; // agar zero node hai , to return head 
    nodeList * slow = head ;
    nodeList * fast = head->next ;

    while(fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next ;
        slow = slow->next ;
    }

    return slow ;
}
int main() 
{
    nodeList * head = NULL ;
    // insertAtHead(head , 50);
    insertAtHead(head , 50);
    insertAtHead(head , 40);
    insertAtHead(head , 30);
    insertAtHead(head , 20);
    insertAtHead(head , 10);

    printLinkedList(head);
    nodeList * midPoint = findMidPoint(head);

    (midPoint != NULL ) ? cout<<"middle node is : " <<midPoint->val<<endl : cout<<"midPoint is NULL"<<endl; 
    
    return 0 ;
}