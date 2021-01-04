// Merge Two Sorted Lists

/**
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists
*/

//EXAMPLE 1

/**
    *Input: l1 = [1,2,4], l2 = [1,3,4]
    Output: [1,1,2,3,4,4]
    Example 2:

    Input: l1 = [], l2 = []
    Output: []
    Example 3:

    Input: l1 = [], l2 = [0]
    Output: [0]
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *temp, *head, *prev = NULL;

        if (!l1 && !l2)
        {
            return head;
        }

        if (!l1)
        {
            head = l2;
        }
        else if (!l2)
        {
            head = l1;
        }
        else
        {
            head = l1->val < l2->val ? l1 : l2;
        }

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {

                if (prev != NULL)
                {
                    prev->next = l1;
                }
                temp = l1->next;
                l1->next = l2;
                prev = l1;
                l1 = temp;
            }
            else
            {
                if (prev != NULL)
                {
                    prev->next = l2;
                }
                prev = l2;
                temp = l2->next;
                l2->next = l1;
                l2 = temp;
            }
        }

        return head;
    }
};