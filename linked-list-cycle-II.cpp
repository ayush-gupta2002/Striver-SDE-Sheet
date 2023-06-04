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

    ListNode* intersection(ListNode* head){
        if(!head || !head -> next){
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        do{
            fast = fast -> next;
            if(fast){
                fast = fast -> next;
            }
            slow = slow -> next;
        }while(fast && slow && fast != slow);

        return fast;
    }

    ListNode *detectCycle(ListNode *head) {
        if(!head || !head -> next){
            return NULL;
        }
        ListNode* temp = intersection(head);

        if(!temp){
            return NULL;
        }

        ListNode* slow = head;

        while(slow != temp){
            slow = slow -> next;
            temp = temp -> next;
        }
        return slow;
    }
};
