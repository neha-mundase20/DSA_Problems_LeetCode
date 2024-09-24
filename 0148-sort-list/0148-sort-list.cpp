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
    ListNode* sortList(ListNode* head) {
        vector<int>arr;
        ListNode*temp=head;

        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }

        sort(arr.begin(),arr.end());

        ListNode*newHead=nullptr;
        ListNode*tail=nullptr;

        for(auto it:arr){
            ListNode*v=new ListNode(it);
            if(newHead==nullptr){
                newHead=tail=v;
            }
            else{
                tail->next=v;
                tail=tail->next;
            }
        }
        return newHead;
    }
};