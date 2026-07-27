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
    ListNode* removeNodes(ListNode* head) {
        vector<int> arr;
        stack<int> st;

        for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
            arr.push_back(curr->val);
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            if(st.empty() || arr[i] >= st.top()){
                st.push(arr[i]);
            }
        }

        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;

        while (!st.empty()) {
            ListNode* node = new ListNode(st.top());
            st.pop();

            if (newHead == nullptr) {
                newHead = node;
                tail = node;
            } else {
                tail->next = node;
                tail = tail->next;
            }
        }

        return newHead;
    }
};