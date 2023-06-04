/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    if(!head || !head->next){
        return head;
    }

    Node* fast = head->next;
    Node* slow = head;

    while(fast){
        fast = fast -> next;
        if(fast){
            fast = fast -> next;
        }
        slow = slow -> next;
    }

    return slow;
}

