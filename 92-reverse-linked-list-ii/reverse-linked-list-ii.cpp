class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // Dummy node helps when left == 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Move prev to the node before 'left'
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++)
        {
            prev = prev->next;
        }

        // curr points to the first node we need to reverse
        ListNode* curr = prev->next;

        // Reverse the section one node at a time
        for (int i = 0; i < right - left; i++)
        {
            ListNode* nextNode = curr->next;

            curr->next = nextNode->next;

            nextNode->next = prev->next;

            prev->next = nextNode;
        }

        return dummy->next;
    }
};