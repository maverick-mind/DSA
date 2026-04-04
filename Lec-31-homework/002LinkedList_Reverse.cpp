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
// search index of a given element iteratively 
void reverseIterative(nodeList * &head )
{
    // cases
    // 1. LL has less than or equal to 1 node 
    if( head == NULL or head->next == NULL) return ;

    // LL has more than or equal to 2 nodes 
    else{
        nodeList * prev = NULL ;
        nodeList * current = head ;
        nodeList * ahead = head -> next ;

        while(current->next != NULL) // or while(ahead != NULL)
        {
            current -> next = prev ;
            prev = current ;
            current = ahead ;
            ahead = ahead -> next ;
        }
        current->next = prev ;
        head = current ;
    }
}

void revRec_using_prev_current_ahead( nodeList * &head , nodeList * &prev , nodeList * &current , nodeList * &ahead )
{
    // trivial case 
    // if LL has 0 node or 1 node , no reverse is possible
    //if(head == NULL or head -> next == NULL) return ; // this line is causing trouble , as soon as 96th line executed for the firrst time , what happens is head ka next NULL ho gya , and 81th line true hoote hi return ho gya , so remove head->next == NULL from here 
    if(head == NULL) return ;
    
    // base case 
    // if LL has more than 1 nodes 
    if(ahead == NULL)
    {
        current->next = prev ;
        head = current ;
        return ;
    }

    // recurrence relation 
    // if(ahead != NULL)
    // {
        current -> next = prev ;
        prev = current ;
        current = ahead ;
        ahead = ahead -> next ;
        revRec_using_prev_current_ahead(head , prev , current , ahead );
    // }
}

// call a function to find tail node of of the ppart of LL that is reversed till now 
// tail of reversed sub Linked List returned by my friend it is redundant work or useless work as , tail is original head ka next i.e. head->next 
nodeList * torsllrbmf(nodeList* hfmf)
{
    while(hfmf -> next != NULL)
    {
        hfmf = hfmf -> next ;
    }
    return hfmf ;
}
nodeList * reversellRecursive(nodeList * head )
{
    
    // base case 
    if(head == NULL or head->next == NULL)
    {
        return head ;
    }

    // recurrence relation
    // friend hamesha , sub LL ka nayaa head return karega 
    // hfmf = head from my friend 
    nodeList *hfmf = reversellRecursive(head->next);

    // tail of reversed sub linked list given by my friend
    // nodeList * tail = torsllrbmf(hfmf); // no need as tail = head->next;
    nodeList * tail = head->next ;
    tail->next = head ; // abhi tak jo reversed LL hai usske end mein head node ko add kar do ; or shortcut : head->next->next = head 
    head->next = NULL; // head ke next mein NULL daal do , kyonki pahle head apne right node ko point kar rha thaa , now it is pointless ki head apne right node ko point karee , reversed LL mein , aur ye uss case ko bhi handle kar lega ki initial non-reversed LL ka jo original head thaa usska-> next bhi NULL ko point karega reversed order mein 

    return hfmf ; // abhi tak jitna sub-LL reversed hua hai usska head return kar do har baar 

}
int main() 
{
    nodeList * head = NULL ;
    insertAtHead(head , 50);
    insertAtHead(head , 40);
    insertAtHead(head , 30);
    insertAtHead(head , 20);
    insertAtHead(head , 10);

    printLinkedList(head);

    reverseIterative(head);
    cout<<"after reversing LL iteratively : ";
    printLinkedList(head);

    nodeList * prev = NULL ;
    nodeList * current = head ;
    nodeList * ahead = NULL;
    (head != NULL) ? ahead = head->next : ahead = NULL;
    revRec_using_prev_current_ahead(head , prev , current , ahead);
    cout<<"after reversing LL by fxn revRec_using_prev_current_ahead : ";

    printLinkedList(head);

    head = reversellRecursive(head );
    cout<<"after reversing LL recursively : ";

    printLinkedList(head);

    return 0 ;
}