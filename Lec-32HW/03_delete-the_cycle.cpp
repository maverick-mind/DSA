#include<iostream>
#include<set>

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

// time : O(nlogn)
// space: O(n) due to set<>

bool isCyclePresent(ListNode* head) {

	set<ListNode*> s;
	while (head != NULL) {
		if (s.find(head) != s.end()) {
			// you've found a cycle
			return true;
		}
		s.insert(head);
		head = head->next;
	}

	// no cycle found
	return false;

}

// time : O(n)
// space : O(1)

bool isCyclePresent2(ListNode* head) {

	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != NULL and fast->next != NULL) {

		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			// you've found a cycle
			return true;
		}

	}

	// no cycle found
	return false;

}
ListNode * deleteCycle( ListNode * head )
{
    // first check whether cycle exists or not
    ListNode * slow = head ;
    ListNode * fast = head ;
    while(fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next ;
        slow = slow -> next ;
        if(fast == slow)
        {
            break ;
        }
    }

    // now confirm , we reach here by (fast != NULL and fast->next != NULL)
    // or (fast == slow) -> break ;
    if(fast == slow and fast != NULL)
    {
        slow = head ;

        while(slow->next != fast->next) // slow ka next aur fast ka next 
        {           // tab same honge , jahaa se cycle shuru hoga
            fast = fast -> next ;
            slow = slow->next ;
        }
        // this loop will exit when fast is at tail , and slow->next is first node of cycle
        // to break cycle :  fast -> next = NULL;
        fast->next = NULL;
    }
    return head ;
}

int main() {

	ListNode* head = new ListNode(10);
	head->next = new ListNode(20);
	head->next->next = new ListNode(30);
	head->next->next->next = new ListNode(40);
	head->next->next->next->next = new ListNode(50);
	head->next->next->next->next->next = new ListNode(60);
	head->next->next->next->next->next->next = head->next;

	isCyclePresent(head) ? cout << "cycle found" << endl :
	                            cout << "cycle not found" << endl;

	isCyclePresent2(head) ? cout << "cycle found" << endl :
	                             cout << "cycle not found" << endl;
    head = deleteCycle(head);
    printLinkedList(head);

	return 0;
}