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

ListNode *deleteDuplicates(ListNode *head)
{

    if (head == NULL or head->next == NULL)
        return head;

    ListNode *prev = NULL;
    ListNode *current = head;
    ListNode *ahead = current->next;

    // int i = 1 ;
    while (ahead != NULL)
    {
        int i = 1;// frequency of current element 
        // if the repeated element is as same as head
        if (current == head)
        {
            while (ahead != NULL and current->val == ahead->val)
            {
                i++;
                ahead = ahead->next;
            }
            if( i > 1 ) // current( ya head) element repeated hai
            {
                current = ahead ; 
                head = current ;
            }
            else if(i == 1) // ahead is just next to current 
            {               // and both are different 
                prev = current ;
                current = ahead ;

            }
        }
        else if(current != head)
        {
            while (ahead != NULL and current->val == ahead->val)
            {
                i++;
                ahead = ahead->next;
            }
            if( i > 1 ) // current element repeated hai
            {
                prev -> next = ahead ;
                current = ahead ;
            }
            else if(i == 1)
            {
                prev -> next = current ;
                prev = current ;
                current = ahead ;
            }

        }

        if(ahead != NULL)
        {
            ahead = ahead -> next ;
        }
    }
    // prev -> next = NULL ;
    // last node may be repeated , may not be repeated 
    
    // if last node is not repeated 
    // if( current != NULL) // matlab last node repeated nahi hai
    // {                 // usske baad NULL hoga pahle se 
    //     current -> next = NULL ;
    // }

    // ho sakta hai saare elements hi repeated ho 
    if(current == NULL and prev != NULL) // last node repeated hoga 
    {               // then only , jab ahead NULL pe pahucha hoga then 
                    // current bhi NULL pe pahuch gya hoga 
        prev -> next = NULL ;
    }

    return head ;
}

int main()
{

    ListNode *head = NULL; // initially, linkedList is empty

    // insertAtHead(head, 7);
    // insertAtHead(head, 7);
    // insertAtHead(head, 7);
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 6);
    // insertAtHead(head, 5);
    // insertAtHead(head, 5);
    // insertAtHead(head, 4);
    // insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 1);
    insertAtHead(head, 1);
    insertAtHead(head, 1);

    printLinkedList(head);

    head = deleteDuplicates(head);

    printLinkedList(head);

    return 0;
}