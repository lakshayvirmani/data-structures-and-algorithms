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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
        {
            return NULL;
        }
        
        ListNode *oddHead, *evenHead, *odd, *even;
        
        oddHead = head;
        evenHead = head->next;
        
        odd = head;
        while(odd->next != NULL && odd->next->next != NULL)
        {
            even = odd->next;
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
        }
        
        odd->next = evenHead;
        
        return oddHead;
    }
};
