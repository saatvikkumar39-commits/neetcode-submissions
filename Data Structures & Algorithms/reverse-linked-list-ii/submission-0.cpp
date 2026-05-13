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
    ListNode* reverse(ListNode* start,int l,int r){
        ListNode* prev=start;
        ListNode* temp=start->next;
        for(int i=l+1;i<=r && temp!=nullptr;i++){
            ListNode* next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        start->next=temp;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* start=head;
        for(int i=1;i<left-1;i++){
            if(start==nullptr) return head;
            start=start->next;
        }
        if(left==1){
            head=reverse(head,left,right);
        }
        else start->next=reverse(start->next,left,right);
        return head;
    }
};