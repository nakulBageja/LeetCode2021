/**
 * Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
    ListNode *deleteDuplicates(ListNode *head)
    {

        //I will traverse the linkedList twice
        //In first traversal i will keep count of each value
        //if value is less than 0 make it 100 + val
        //else normal index
        vector<int> check(200, 0);
        ListNode *ptr = head, *prev = head;
        while (ptr != NULL)
        {
            if (ptr->val < 0)
            {
                check[100 + abs(ptr->val)]++;
            }
            else
            {
                check[ptr->val]++;
            }
            ptr = ptr->next;
        }

        ptr = head;

        while (ptr != NULL)
        {

            if (ptr->val < 0)
            {
                if (check[100 + abs(ptr->val)] > 1)
                {
                    cout << ptr->val;
                    if (ptr == head)
                    {
                        ptr = ptr->next;
                        head = ptr;
                        continue;
                    }
                    prev->next = ptr->next;
                    ptr = ptr->next;
                    continue;
                }
            }
            else
            {
                if (check[ptr->val] > 1)
                {
                    cout << ptr->val;
                    if (ptr == head)
                    {
                        ptr = ptr->next;
                        head = ptr;
                        continue;
                    }
                    prev->next = ptr->next;
                    ptr = ptr->next;
                    continue;
                }
            }
            prev = ptr;

            ptr = ptr->next;
        }

        return head;
    }
};