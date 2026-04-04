#include<bits/stdc++.h>
using namespace std;
 
class ListNode{

public :
// attributes of ListNode 
    int val ;
    ListNode * next ;

// parameterized constructor 
    ListNode(int val)
    {
        this-> val = val ;
        this-> next = NULL;
    }
};
 
void insertAtHead( ListNode * &head , int val )
{
    // create a memory on heap 
    ListNode * n = new ListNode(val);

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

void printLinkedList(ListNode * head)
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

ListNode * removeDuplicates( ListNode * head)
{
    // let's say hum apne final LL mein head ko rakhna chah rhe hai 
    // even if head ke value ki multiple occurance ho , hum head waale ko rakh lenge , baaki ko delete kar denge 
    // so let's start after head 
    if(head == NULL or head -> next == NULL) return head ;
    
    else
    {
        ListNode * current = head -> next ;
        ListNode * prev = head ;
        while(current != NULL)
        {
            if(current -> val == prev -> val)
            {
                prev -> next = current -> next ;
                delete current ;
                current = prev -> next ;
            }

            else {
                prev = current ;
                current = current -> next ;
            }
        }
    }

    return head ;
}
// 83 leetcode 
int main() 
{
    ListNode * head = NULL ;
    insertAtHead(head , 60);
    insertAtHead(head , 60);
    insertAtHead(head , 50);
    insertAtHead(head , 40);
    insertAtHead(head , 40);
    insertAtHead(head , 40);
    insertAtHead(head , 20);
    insertAtHead(head , 10);
    insertAtHead(head , 10);

    printLinkedList(head);

    head = removeDuplicates(head);
    printLinkedList(head);

    return 0 ;
}