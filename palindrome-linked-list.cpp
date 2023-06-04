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

    ListNode* middle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast){
            fast = fast -> next;
            if(fast){
                fast = fast -> next;
            }
            slow = slow -> next;
        }

        return slow;
    }

        ListNode* reverseList(ListNode* head) {
        if(!head || !head -> next){
            return head;
        }
        ListNode* current = head;
        ListNode* next = head -> next;
        ListNode* prev = NULL;

        while(next){
            ListNode* suc = next -> next;
            next -> next = current;
            current -> next = prev;
            prev = current;
            current = next;
            next = suc;
        }
        

        return current;
    }


    bool isPalindrome(ListNode* head) {
        ListNode* rev = reverseList(middle(head));

        // while(rev){
        //     cout<<rev->val<<" ";
        //     rev = rev -> next;
        // }cout<<endl;

        // while(head){
        //     cout<<head -> val <<" ";
        //     head = head -> next;
        // }cout<<endl;
        
        while(rev && head){
            if(rev -> val != head -> val){
                return false;
            }

            rev = rev -> next;
            head = head -> next;
        }
        return true;
    }
};
