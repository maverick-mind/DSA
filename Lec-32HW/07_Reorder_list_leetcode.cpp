/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
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
    ListNode* findMidPoint(ListNode* head) {
        if (head == NULL)
            return head; // agar zero node hai , to return head
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL and fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    void reorderList(ListNode* head) {
        // logic : break the LL accross it's mid-point
        // after mid-point reverse the LL and name it head as headFromTheEnd
        // now make 2 more pointers as nextFromFront(initialise it as
        // headFromFront ka next ) and other nextFromBack(initialise it as
        // headFromBack ka next) now iterate in loop and just reorder the links
        // of the LL

        ListNode * headFromFront = head ;

        ListNode* midPoint = findMidPoint(head);
        ListNode* headFromEnd = midPoint->next;
        midPoint -> next = NULL ;
        // now reverse the second half
        headFromEnd = reverseIterative(headFromEnd);

        // now make one more pointer each for first half part and second half part 
        ListNode * nextFromFront = head -> next ;
        ListNode * nextFromEnd = headFromEnd -> next ;

        while(headFromEnd != NULL)
        {
            headFromFront ->next = headFromEnd ;
            headFromEnd -> next = nextFromFront ;
            headFromFront = nextFromFront ;
            headFromEnd = nextFromEnd ; 
            if(nextFromFront!= NULL)
            {
                nextFromFront -> next = nextFromFront ;
            }
            if(nextFromEnd != NULL )
            {
                nextFromEnd -> next = nextFromEnd ;
            }
        }

    }
};