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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *left, *right;
        
        right = head;
        left = new ListNode();
        left->next = head;
        
        while(n--)
        {
            right = right->next;
        }
        
        while(right != NULL)
        {
            left = left->next;
            right = right->next;
        }
        
        if(left->next == head)
        {
            head = left->next->next;
        }
        
        ListNode* temp = left->next;
        left->next = left->next->next;
        delete temp;
        
        return head;
    }
};
