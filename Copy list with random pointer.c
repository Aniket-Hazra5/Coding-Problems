/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> m; //hash mapping with map m
        Node* temp=head; // Assigning value of head to temp
        while(temp!=NULL) // Traversing the linked list
        {
            Node* copy = new Node(temp->val);// Creating copy of each node
            m[temp]=copy; //Copying the value by mapping a->a'
            temp=temp->next; // traversing
        }
        temp=head;
        while(temp!=NULL)
        {
            m[temp]->next=m[temp->next];
            m[temp]->random=m[temp->random];
            temp=temp->next;
        }
        return m[head];
    }
};