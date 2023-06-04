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
        //  if(!head || !head -> next){
        //     return head;
        // }
        // ListNode* current = head;
        // ListNode* next = head -> next;
        // ListNode* prev = NULL;

        // while(next){
        //     ListNode* suc = next -> next;
        //     next -> next = current;
        //     current -> next = prev;
        //     prev = current;
        //     current = next;
        //     next = suc;
        // }
        

        // return current;
class Solution {
public:

    ListNode* solve(ListNode* head){
        if(!head || !head->next){
            return head;
        }

        ListNode* current = head;
        ListNode* next = head -> next;
        ListNode* prev = NULL;

        if(!next){
            return current;
        }

        List
    }

    ListNode* reverseList(ListNode* head) {
        return solve(head);
    }
};
