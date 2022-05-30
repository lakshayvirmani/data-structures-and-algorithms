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
    bool isPalindrome(ListNode* head) {
        bool result = true;
        
        if(head -> next == NULL)
        {
            return result;
        }
        
        ListNode *slow, *fast, *prev, *tmp, *mid;
        
        slow = fast = head;
        prev = NULL;
        
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            
            // reverse while looking for mid
            tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        
        slow = prev;
        mid = tmp;
        
        // corner case. no need to compare the middle element if the length of ll is odd.
        if(fast != NULL && fast->next == NULL)
        {
            tmp = tmp->next;
        }
        
        // iterate through 2 halves and check for palindrome property
        while(slow != NULL && tmp != NULL && slow->val == tmp->val)
        {
            slow = slow->next;
            tmp = tmp->next;
        }
        
        if(slow == NULL && tmp == NULL)
        {
            result = true;
        }
        else
        {
            result = false;
        }
        
        // Reverse ll again to restore.
        slow = prev;
        prev = mid;
        
        while(slow != NULL)
        {
            tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        
        return result;
    }
};
