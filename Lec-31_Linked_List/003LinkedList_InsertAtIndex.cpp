#include<iostream>

using namespace std;

class ListNode {

public :

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}

void printLinkedList(ListNode* head) { // here head ptr must be passed by value since we don't want changes done to head ptr to be reflected in the caller fn

    if(head == NULL)
    {
        cout<<"LL is empty before calling printLinkedList function"<<endl;
    }

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

ListNode* getTail(ListNode* head) { // here head ptr must be passed by value since we don't want changes done to head ptr to be reflected in the caller fn
	while (head->next != NULL) {
		head = head->next;
	}
	return head;
}

// time : O(n) where n is the length of the linkedList

void insertAtTail(ListNode*& head, int val) {

	if (head == NULL) {
		// insertion at tail is equivalent to insertion at head
		insertAtHead(head, val);
		return;
	}

	ListNode* n = new ListNode(val); // const
	ListNode* tail = getTail(head); // linear
	tail->next = n; // const
}


// time : O(n)
// 0 based indexing ke basis pe insert at any index kar rhe hai 
void insertAtIndex( ListNode * &head , int val , int index)
{
    ListNode * n = new ListNode(val);

    ListNode *ptr = head ;
    // 2 possible cases , either head is NULL or head is not NULL
    // case 1. if head is NULL or i == 0 
    if(head == NULL or index == 0)
    {
        insertAtHead(head , val);
        return ;
    }

    // case 2. If head is not NULL
    else if(head != NULL)
    {
        // 2 cases 
        // either the index givn is within the size of linked list 
        // or the index given exceeds the length of linked list , in this case --> insert at tail
        int i = 0 ;
        while(i < index - 1 and ptr->next != NULL)
        {
            ptr = ptr->next ;
            i++;
        }
        if(ptr->next == NULL)
        {
            insertAtTail(head , val);
            return ;
        }
        else if(i == index - 1 )
        {
            n -> next = ptr->next ;
            ptr->next = n ;
            return ;
        }
    }
}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	// insertAtHead(head, 50);
	// insertAtHead(head, 40);
	// insertAtHead(head, 30);
	// insertAtHead(head, 20);
	// insertAtHead(head, 10);

	// printLinkedList(head); // 10 20 30 40 50

	insertAtTail(head, 10);
	insertAtTail(head, 20);
	insertAtTail(head, 30);
	insertAtTail(head, 40);
	insertAtTail(head, 50);
	insertAtTail(head, 60);

	printLinkedList(head); // 10 20 30 40 50 60

    insertAtIndex(head , 25 , 0); // 0 based indexing 

    printLinkedList(head); // 10 20 25 30 40 50 60


	return 0;
}