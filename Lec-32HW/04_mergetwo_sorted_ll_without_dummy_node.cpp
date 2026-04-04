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
ListNode * mergeTwoSortedLL(ListNode * head1 , ListNode * head2 )
{
	// we need one-one each temporary variable for ll1 and ll2 and one more variable for current node of re-arranged LL
	ListNode * current_Tail = NULL ; 
	ListNode *newHead = NULL;

	// jab tak dono LL pe iterate karte karte NULL(tail ka next) nahi reach kar jaate
	while(head1 != NULL and head2 != NULL)
	{
		// case 1. agar current_Tail NULL ho 
		if(current_Tail == NULL)
		{
			if(head1 ->val <= head2 -> val) // head1 pahle aayega iss case mein
			{
				current_Tail = head1;
				newHead = head1;
				head1 = head1->next ;
			}
			else{
				current_Tail = head2;
				newHead = head2;
				head2 = head2->next ;
			}
		}

		// case 2. agar current_Tail NULL nahi ho 
		else{ 
			if(head1 ->val <= head2 -> val) // head1 pahle aayega iss case mein
			{
				current_Tail->next = head1;
				current_Tail = current_Tail -> next ;
				head1 = head1->next ;
			}
			else{
				current_Tail->next = head2;
				current_Tail = current_Tail -> next ;
				head2 = head2->next ;
			}
		}

	}

	// while loop ke baad , agar head1 != NULL hai , yaani head2 NULL ho chucka hoga tabhi ye if condition chalega 
	// head2 NULL 2 case mein hoga 
	// 1. head2 shuru se hi NULL ho ,iss case mein newHead bhi abhi tak NULL hoga aur current_Tail bhi abhi tak NULL hoga , dono ko update karna padega 
	// 2.  ya fir iterate karte karte NULL par pahuch gya ho , then bass current_Tail ke next mein add kar do head1 ka link 
	if(head1 != NULL)
	{
		if(current_Tail == NULL)
		{
			current_Tail = head1 ;
			newHead = head1 ;
		}
		else{
			current_Tail ->next = head1 ;
		    current_Tail = current_Tail -> next ;
		}
		
	}
	// while loop ke baad , agar head2 != NULL hai , yaani head1 NULL ho chucka hoga tabhi ye if condition chalega 
	// head1 NULL 2 case mein hoga 
	// 1. head1 shuru se hi NULL ho ,iss case mein newHead bhi abhi tak NULL hoga aur current_Tail bhi abhi tak NULL hoga , dono ko update karna padega 
	// 2.  ya fir iterate karte karte NULL par pahuch gya ho , then bass current_Tail ke next mein add kar do head1 ka link 
	else if(head2 != NULL)
	{
		if(current_Tail == NULL)
		{
			current_Tail = head2 ;
			newHead = head2 ;
		}
		else{
			current_Tail ->next = head2 ;
		    current_Tail = current_Tail -> next ;
		}
	}
	
	return newHead ;
}


int main() 
{
    ListNode * head1 = NULL ;
    insertAtHead(head1 , 90);
    insertAtHead(head1 , 80);
    insertAtHead(head1 , 70);
    insertAtHead(head1 , 50);
    insertAtHead(head1 , 30);
    insertAtHead(head1 , 10);

    printLinkedList(head1);

	ListNode * head2 = NULL ;
    insertAtHead(head2 , 65);
    insertAtHead(head2 , 60);
    insertAtHead(head2 , 40);
    insertAtHead(head2 , 20);

    printLinkedList(head2);

	ListNode * head =  mergeTwoSortedLL(head1 , head2 );

	printLinkedList(head);

    return 0 ;
}