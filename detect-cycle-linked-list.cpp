/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head -> next){
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(slow && fast && slow != fast){
            if(fast){
                fast = fast -> next;
                if(fast){
                    fast = fast -> next;
                }
                slow = slow -> next;
            }
        }
        if(fast && slow && fast == slow){
            return true;
        }
        return false;
    }
};
