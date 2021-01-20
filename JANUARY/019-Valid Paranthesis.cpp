/***
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        int i = 0;
        while (s[i] != '\0')
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stack.push(s[i]);
            }
            else
            {
                if (s[i] == ')' && !stack.empty() && stack.top() == '(')
                {
                    stack.pop();
                }
                else if (s[i] == '}' && !stack.empty() && stack.top() == '{')
                {
                    stack.pop();
                }
                else if (s[i] == ']' && !stack.empty() && stack.top() == '[')
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
            i++;
        }
        if (!stack.empty())
            return false;
        return true;
    }
};