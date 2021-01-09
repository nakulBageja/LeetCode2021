/**
 * 
 * Given two words beginWord and endWord, and a dictionary wordList, return the length of the shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Return 0 if there is no such transformation sequence.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 

Constraints:

1 <= beginWord.length <= 100
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the strings in wordList are unique.
*/

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> s1;
        unordered_set<string> s2;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))
            return 0;
        int len = beginWord.size();
        int ans = 0;
        s1.insert(beginWord);
        s2.insert(endWord);
        while (!s1.empty() && !s2.empty())
        {
            ans++;
            if (s1.size() > s2.size())
            {
                swap(s1, s2);
            }
            unordered_set<string> cur;
            for (string w : s1)
            {
                for (int i = 0; i < len; i++)
                {
                    char temp = w[i];
                    for (char x = 'a'; x <= 'z'; x++)
                    {
                        w[i] = x;
                        if (s2.count(w))
                        {
                            return ans + 1;
                        }
                        if (!dict.count(w))
                            continue;
                        dict.erase(w);
                        cur.insert(w);
                    }
                    w[i] = temp;
                }
            }

            s1 = cur;
        }

        return 0;
    }
};