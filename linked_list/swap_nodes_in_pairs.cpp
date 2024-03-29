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
    ListNode* swapPairs(ListNode* head) {
        ListNode *prev, *cur, *next;
        
        // initialize
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        prev = dummyHead;
        cur = head;
        
        while(cur != NULL && cur->next != NULL)
        {
            next = cur->next;
            
            cur->next = next->next;
            prev->next = next;
            next->next = cur;
            
            prev = cur;
            cur = cur->next;
        }
        
        // clean up
        head = dummyHead->next;
        delete dummyHead;
        
        return head;
    }
};
