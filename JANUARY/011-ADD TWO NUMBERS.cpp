/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

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
class Solution
{
public:
    void append(ListNode **head_ref, int new_data)
    {

        // 1. allocate node
        ListNode *new_node = new ListNode(new_data);

        // Used in step 5
        ListNode *last = *head_ref;

        // 4. If the Linked List is empty,
        // then make the new node as head
        if (*head_ref == NULL)
        {
            *head_ref = new_node;
            return;
        }

        // 5. Else traverse till the last node
        while (last->next != NULL)
            last = last->next;

        // 6. Change the next of last node
        last->next = new_node;
        return;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        int sum = 0;
        ListNode *head = NULL;
        int i = 0;
        while (1)
        {
            if (!l1 && !l2)
            {
                break;
            }
            if (l1 == NULL && l2 != NULL)
            {
                sum = l2->val + carry;

                l2 = l2->next;
            }
            else if (l2 == NULL && l1 != NULL)
            {
                sum = l1->val + carry;

                l1 = l1->next;
            }
            else
            {
                sum = l1->val + l2->val + carry;

                l1 = l1->next;
                l2 = l2->next;
            }
            carry = 0;
            if (sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
            }
            append(&head, sum);
        }
        if (carry != 0)
        {
            append(&head, carry);
        }
        return head;
    }
};