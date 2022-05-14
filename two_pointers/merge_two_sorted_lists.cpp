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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head, *cur, *cur1, *cur2;
        
        head = new ListNode(-1);
        cur = head;
        cur1 = list1;
        cur2 = list2;
        
        while(cur1 != NULL && cur2 != NULL)
        {
            if(cur1 -> val < cur2 -> val)
            {
                cur -> next = cur1;
                cur1 = cur1 -> next;
            }
            else
            {
                cur -> next = cur2;
                cur2 = cur2 -> next;
            }
            
            cur = cur -> next;
        }
        
        if(cur1 != NULL)
        {
            cur -> next = cur1;
        }
        else
        {
            cur -> next = cur2;
        }
        
        return head->next;
    }
};
