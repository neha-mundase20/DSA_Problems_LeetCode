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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==nullptr)return list2;
        if (list2 == nullptr) return list1;
        
        ListNode* head = nullptr; // Head of the merged list
        ListNode* mergedList = nullptr; // Current end of the merged list
        
        // Initialize head and mergedList
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        mergedList = head;

        // Merge the two lists
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                mergedList->next = list1;
                list1 = list1->next;
            } else {
                mergedList->next = list2;
                list2 = list2->next;
            }
            mergedList = mergedList->next;
        }

        // Attach the remaining part
        if (list1 != nullptr) {
            mergedList->next = list1;
        } else {
            mergedList->next = list2;
        }

        return head;
    }
};