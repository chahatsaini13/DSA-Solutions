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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr){
            return nullptr;
        }

        ListNode* last = head;
        int n = 1;

        while(last -> next != nullptr){
            n++;
            last = last -> next;
        }
        
        k = k % n;
        if(k == 0){
            return head;
        }

        int count = 1;
        ListNode* t = head;

        while(t != nullptr){
            if(count == n-k){
                break;
            }
            count++;
            t = t-> next; //(n-k)th node
        }
        
        last -> next = head; //last node ko had bna do
        ListNode* res = t-> next; // (n-k+1)th node
        t-> next = nullptr;

        return res;

    }
};