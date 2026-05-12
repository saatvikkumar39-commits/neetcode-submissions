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
    void reorderList(ListNode* head) {
        unordered_map<int,ListNode*> hash;
        ListNode* temp=head;
        int i=0;
        while(temp!=nullptr){
            hash[i]=temp;
            temp=temp->next;
            i++;
        }
        int l=1; int r=i-1;
        int n=i;
        temp=head;
        for(int i=1;i<n;i++){
            if((i&1)==1){
                temp->next=hash[r];
                temp=temp->next;
                r--;
            }
            else{
                temp->next=hash[l];
                temp=temp->next;
                l++;
            }
        }
        temp->next=nullptr;
    }
};
