#include<iostream>

using namespace std;

class ListNode {
public:

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

	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

// time : O(m+n)
// space: O(1)
// [HW] try to implement this algorithm recursively

ListNode* mergeSortedLinkedList(ListNode* head1, ListNode* head2) {

	ListNode* dummy = new ListNode(0);
	ListNode* temp = dummy;

	while (head1 != NULL and head2 != NULL) {
		if (head1->val < head2->val) {
			temp->next = head1;
			temp = temp->next;
			head1 = head1->next;
		} else {
			temp->next = head2;
			temp = temp->next;
			head2 = head2->next;
		}
	}

	if (head1 != NULL) {
		temp->next = head1;
	}

	if (head2 != NULL) {
		temp->next = head2;
	}

	return dummy->next;

}
ListNode * findMidPoint(ListNode * head )
{
    if(head == NULL) return head ; // agar zero node hai , to return head 
    ListNode * slow = head ;
    ListNode * fast = head->next ;

    while(fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next ;
        slow = slow->next ;
    }

    return slow ;
}

ListNode * mergeSortLL (ListNode * head )
{
    // base case 
    // if either 1 or 0 node is there , then there is no need for sorting 
    if(head == NULL or head -> next == NULL)
    {
        return head ;
    }

    // recurrence relation 
    // in merge sort , find the midpoint first 
    ListNode * midNode = findMidPoint(head) ;
    ListNode * headAfterMid = midNode -> next ;
    midNode ->next = NULL ;
    // head = mergeSortLL(head);
    head = mergeSortLL(head ) ; 
    headAfterMid = mergeSortLL(headAfterMid );

    ListNode * newHead = mergeSortedLinkedList(head , headAfterMid);

    return newHead ; 
}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 32);
	insertAtHead(head, 2);
	insertAtHead(head, 15);
	insertAtHead(head, 30);
	insertAtHead(head, 5);
	insertAtHead(head, 30);
	insertAtHead(head, 10);

	printLinkedList(head );
    ListNode * tail = head ;
    while(tail->next != NULL)
    {
        tail = tail->next ;
    }

    head = mergeSortLL(head);

	printLinkedList(head );

	return 0;
}