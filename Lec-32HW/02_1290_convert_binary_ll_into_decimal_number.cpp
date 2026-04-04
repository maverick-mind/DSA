#include<bits/stdc++.h>

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
int getDecimalValue(ListNode* head)
{
    // calculate the length of LL 
    ListNode * temp = head ;
    int length = 0 ;
    while(temp != NULL)
    {
        length++;
        temp = temp -> next ;
    }

    int ans = 0 ;
    int i = 1 ;
    while(i < length or head != NULL)
    {
        ans += pow( 2 , (length - i) )*head->val;
        i++;
        head = head->next ;
    }

    return ans ;
}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	// insertAtHead(head, 5);
	insertAtHead(head, 1);
	insertAtHead(head, 1);
	insertAtHead(head, 0);
	insertAtHead(head, 1);

	printLinkedList(head);

    cout<<getDecimalValue(head)<<endl;


	return 0;
}