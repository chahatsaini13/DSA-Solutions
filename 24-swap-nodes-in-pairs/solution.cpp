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

    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        int size = 2;

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

            ListNode* newHead = reverse(left, 2);

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