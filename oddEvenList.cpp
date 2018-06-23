/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {

            ListNode *oddHead  = NULL;
            ListNode *oddTail  = NULL;
            ListNode *evenHead = NULL;
            ListNode *evenTail = NULL;
            if (head == NULL) {
                return head;

            }
            oddHead = head;
            oddTail = oddHead;
            if (oddHead->next == NULL) {
                return head;

            }
            evenHead = oddHead->next;
            evenTail = evenHead;

            ListNode *tail = evenHead->next;
            int index = 1;
            while(tail) {
                if (index % 2) {
                    oddTail->next = tail;
                    oddTail = tail;

                }
                else {
                    evenTail->next = tail;
                    evenTail = tail;

                }
                tail = tail->next;
                index++;

            }
            evenTail->next = NULL;
            oddTail->next = evenHead;
            return oddHead;

        }

};
