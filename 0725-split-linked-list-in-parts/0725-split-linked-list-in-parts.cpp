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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=0;
        ListNode*temp=head;
        while(temp!=nullptr){
            size++;
            temp=temp->next;
        }

        int parts=size/k;   //min no. of parts of size k
        int extraParts=size%k;  //number of parts having an extra node

        vector<ListNode*> result;

        temp = head;

        // Step 2: Handle parts with one extra node
        for (int i = 0; i < k; i++) {
            ListNode* listHead = temp;  // Head of the current part
            ListNode* listEnd = nullptr;
            int currentPartSize = parts + (extraParts > 0 ? 1 : 0);  // Size of the current part

            // Traverse the current part
            for (int j = 0; j < currentPartSize && temp != nullptr; j++) {
                listEnd = temp;  // Keep track of the last node of this part
                temp = temp->next;
            }

            // Cut off the current part from the rest of the list
            if (listEnd != nullptr) {
                listEnd->next = nullptr;
            }

            // Add the current part to the result
            result.push_back(listHead);

            // Decrease extraParts after assigning an extra node to the part
            if (extraParts > 0) {
                extraParts--;
            }
        }

        // Ensure the result vector has exactly k parts
        while (result.size() < k) {
            result.push_back(nullptr);
        }

        return result;
    }
};