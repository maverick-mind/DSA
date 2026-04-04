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


void printLinkedList(ListNode* head) {

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

int sizeofLL(ListNode * head) // to calculate effective number of rotation 
{               // i.e. (k rotation) % (length of LL)
    int length = 0 ;
    while(head != NULL)
    {
        head = head -> next ;
        length++;
    }
    return length ;
}

ListNode* reverseIterative(ListNode* head) {

	ListNode* prev = NULL;
	ListNode* cur = head;

	while (cur != NULL) {
		ListNode* temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}

	return prev;
}

ListNode* rotateRight(ListNode* head, int k) {
    
    if(head == NULL or head -> next == NULL)
    {
        return head ;
    }

    int n = sizeofLL(head ) ; 
    k = k % n ;

    // step 1. reverse the original LL
    ListNode * originalTail = reverseIterative(head);

    // if k is a large valued number , rotate k%n(length of LL) times to escape TLE
    
    while(k--)
    {
        head -> next = originalTail ; 
        originalTail = originalTail -> next ;
        head = head -> next ;
    }
    head -> next = NULL ;
    
    return reverseIterative(originalTail);
}

int main() {

	ListNode* head = NULL; // initially, linkedList is initially empty

	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);

	printLinkedList(head);

    head = rotateRight(head , 2) ;
	printLinkedList(head);

	return 0;
}