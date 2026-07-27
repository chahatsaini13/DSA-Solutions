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
    ListNode* reverse(ListNode* head, int times) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (times--) {
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;

        int size = k;

        ListNode* left = head;
        ListNode* right;

        ListNode* res = nullptr;
        ListNode* preLeft = nullptr;

        while (true) {

            right = left;

            for (int i = 0; i < size - 1; i++) {
                if (right == nullptr)
                    break;

                right = right->next;
            }

            if (right == nullptr) {
                if (preLeft)
                    preLeft->next = left;

                if (res == nullptr)
                    res = left;

                break;
            }

            ListNode* nextLeft = right->next;

            ListNode* newHead = reverse(left, k);

            if (preLeft)
                preLeft->next = newHead;

            if (res == nullptr)
                res = newHead;

            left->next = nextLeft;

            preLeft = left;
            left = nextLeft;
        }

        return res;
    }
};