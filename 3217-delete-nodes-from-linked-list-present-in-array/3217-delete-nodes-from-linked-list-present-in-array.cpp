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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>hashmap;

        for(auto it:nums){
            hashmap[it]++;
        }

        ListNode*prev=head;
        ListNode*current=head;

        while(current!=nullptr){
            if(hashmap.find(current->val)!=hashmap.end()){
                //The node exists in hashmap
                if(current==head){
                    head=head->next;
                    current=head;
                    prev=current;
                }
                else{
                    prev->next=current->next;
                    current=current->next;
                }
            }
            else{
                prev=current;
                current=current->next;
            }
        }
        return head;
    }
};