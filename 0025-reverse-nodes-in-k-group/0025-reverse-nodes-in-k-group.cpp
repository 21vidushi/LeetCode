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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        int count = 0;
        // Count the number of nodes in the current group
        while (current != nullptr && count != k) {
            current = current->next;
            count++;
        }
        // If the number of nodes in the group is less than k, no need to reverse
        if (count < k) {
            return head;
        }
        // Reverse the current group
        ListNode* reversedHead = reverseLinkedList(head, k);
        // Recursively call for the remaining list
        head->next = reverseKGroup(current, k);
        return reversedHead;
    }
    
private:
    // Function to reverse a linked list of size k
    ListNode* reverseLinkedList(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        for (int i = 0; i < k; i++) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};
