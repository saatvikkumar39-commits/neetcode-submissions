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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* frw=head;
        ListNode* bck=head;
        int s=0;
        for(int i=0;i<n && frw!=nullptr;i++){
            s++;
            frw=frw->next;
        }
        while(frw!=nullptr && frw->next!=nullptr){
            s++;
            frw=frw->next;
            bck=bck->next;
        }
        if(frw==nullptr){
            if(n==s){
                bck=bck->next;
                return bck;
            }
        }
        bck->next=bck->next->next;
        return head;
    }
};
