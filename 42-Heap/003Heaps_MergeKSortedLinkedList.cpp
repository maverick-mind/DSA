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
class ListNodeCmp{

public : 
    bool operator()(pair<ListNode* , int> a , pair<ListNode* , int> b)
    {
        return (a.first)->val > (b.first)->val ; // if a.val > b.val then a will go below b 
    }

};

// time : O(n (k log k))
// space : O(k) due to heap of size k 

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // I have handled head , current pointer in such a way that , these 2 if conditions are optional
        if(lists.size() == 0) return NULL ;
        if(lists.size() == 1) return lists[0] ;

        priority_queue<pair<ListNode* , int> , vector<pair<ListNode* , int>> , ListNodeCmp> hp ;

        // pair<ListNode* , int> :: <ListNode* , int to track the index of which linked list ListNode

        // put all the head of ListNode vector in the min-heap , which are not NULL

        for(int i = 0 ; i < lists.size() ; i++)
        {
            if(lists[i] != NULL) hp.push({lists[i] , i}) ; // < node , index>
        }

        ListNode * head = NULL ; 
        ListNode * current = NULL ;
        while(!hp.empty())
        {
            auto [node , idx] = hp.top() ;
            hp.pop() ;
            if(head == NULL and node != NULL)
            {
                head = node ; 
                current = head ; 
            }
            else if(head != NULL and node != NULL){
                current->next = node ; 
                current = node ;
            }

            lists[idx] = (lists[idx])->next ; 

            if(lists[idx] != NULL){ // each lists[idx] have their last node pointing to NULL , 
                                    // and we don't want to insert NULL in heap , 
                                    //we will insert NULL only once and at the end of the final linked list 
                hp.push({lists[idx] , idx}) ;
            }
        }

        if(current != NULL) current->next = NULL ;
        return head ;
    }
};