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

    ListNode* reverse(ListNode* head, int left,int right){
        if(!head || !head -> next){
            return head;
        }

        ListNode* newNode = new ListNode(-101);
        newNode -> next = head;

        // while(newNode){
        //     cout<<newNode -> val<<" ";
        //     newNode = newNode -> next;
        // }cout<<endl;

        int i = 1;

        ListNode* lprev = newNode;
        ListNode* curr = head;

        // while(curr){
        //     cout<<curr -> val<<" ";
        //     curr = curr -> next;
        // }cout<<endl;

        while(i != left){
            // cout<<lprev -> val<<" ";
            // cout<<curr -> val<<endl;
            lprev = curr;
            curr = curr -> next;
            i++;
        }

        ListNode* prev = NULL;

        for(int k = 0 ; k<right-left+1;k++){
            ListNode* suc = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = suc;
        }

        lprev -> next -> next = curr;
        lprev -> next = prev;

        return newNode -> next;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head -> next){
            return head;
        }
        ListNode* temp = head;
        int cnt = 0;

        while(temp){
            cnt++;
            temp = temp -> next;
        }

        if(k == 0 || k % cnt == 0){
            return head;
        }

        // while(head){
        //     cout<<head -> val<<" ";
        //     head = head -> next;
        // }cout<<endl;
        // cout<<cnt<<endl;
        k = k % cnt;

        head = reverse(head,1,cnt-k);
        head = reverse(head,cnt-k+1,cnt);
        head = reverse(head,1,cnt);

        return head;
    }
};
