#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

class ListNode
{

public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insertAtHead(ListNode *&head, int val)
{

    ListNode *n = new ListNode(val);
    n->next = head;
    head = n;
}

void printLinkedList(ListNode *head)
{

    if (head == NULL)
    {
        cout << "LL is empty before calling printLinkedList function" << endl;
    }
    while (head)
    { // head != NULL
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
ListNode * leftPrevNode(ListNode* head, int left)
{
    // int prev = NULL ;
    ListNode * curr = head ;
    int count = 1 ; // 1 based indexing giveen in question 
    while(count != left - 1 )
    {
        // prev = curr ;
        curr = curr -> next ;
        count++;
    }
    return curr ;
}

ListNode * rightCurrentNode(ListNode* head, int right)
{
    ListNode * curr = head ;
    // int ahead = curr -> next ;
    int count = 1 ;
    while(count != right )
    {
        curr = curr -> next ;
        count++;
        // ahead = ahead -> next ;
    }
    return curr ;
}


ListNode* reverseBetween(ListNode* head, int left, int right) {
    
    // lpn : Left previous node 
    ListNode * lpn = NULL;
    ListNode * lcn = NULL;

    // rcn : right current node 
    ListNode * rcn = rightCurrentNode(head , right);

    // we need lpn ,lcn , rcn , rnn
    ListNode * rnn = rcn -> next ;
    rcn -> next = NULL ;

    // check if head node also need to be reversed 
    if(left == 1)
    {
        lpn = NULL ;
        lcn = head ;
    }
    else{
        lpn = leftPrevNode(head , left);
        lcn = lpn -> next ;
        lpn -> next = NULL ;
    }

    // reverse from lcn to rcn 
    ListNode * prev = NULL ;
    ListNode * curr = lcn ;
    ListNode * ahead = curr -> next ;

    // now reverse 
    while(curr != NULL)
    {
        curr -> next = prev ;
        prev = curr ;
        curr = ahead ;
        if(ahead != NULL)
        {
            ahead = ahead -> next ;
        }
    }
    
    // check kya head waala node bhi reverse ho gya hai
    if(left == 1 )
    {
        head = rcn ; // head will change 
    }
    else{
        lpn -> next = rcn ;
    }
    lcn -> next = rnn ;
    return head ;
}


int main()
{

    ListNode *head = NULL; // initially, linkedList is empty

    
    
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    printLinkedList(head);
    int left = 1 , right = 4 ;

    head = reverseBetween(head , left , right );

    printLinkedList(head);

    return 0;
}