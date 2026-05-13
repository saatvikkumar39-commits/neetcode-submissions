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
        unordered_map<Node*,Node*> hash;
        Node* temp=head;
        while(temp!=nullptr){
            if(hash.find(temp)==hash.end()){
                Node* node=new Node(temp->val);
                hash[temp]=node;
            }
            Node* copy=hash[temp];
            if(temp->next==nullptr){
                copy->next=nullptr;
            }
            else{
                if(hash.find(temp->next)==hash.end()){
                    Node* copy_next=new Node(temp->next->val);
                    hash[temp->next]=copy_next;
                }
                copy->next=hash[temp->next];
            }
            if(temp->random==nullptr){
                copy->random=nullptr;
            }
            else{
                if(hash.find(temp->random)==hash.end()){
                    Node* copy_random=new Node(temp->random->val);
                    hash[temp->random]=copy_random;
                }
                copy->random=hash[temp->random];
            }
            temp=temp->next;
        }
        return hash[head];
    }
};
