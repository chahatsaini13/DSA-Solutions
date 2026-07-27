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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* leftPre = dummy;
        ListNode* curr = head;

        for(int i = 0; i < left - 1 ; i++){
            leftPre = leftPre->next;
            curr = curr->next;
        }

        ListNode* subHead = curr;
        ListNode* pre = nullptr;

        for(int i = 0 ; i < right - left + 1 ; i++){
            ListNode* nex = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nex;
        }

        leftPre->next = pre;
        subHead->next = curr;

        return dummy->next;
    }
};