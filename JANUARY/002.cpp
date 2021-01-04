//Beautiful Arrangement

/**
 * Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

    perm[i] is divisible by i.
    i is divisible by perm[i].
    Given an integer n, return the number of the beautiful arrangements that you can construct.
*/

//EXAMPLE 1

/**
 * Input: n = 2
    Output: 2
    Explanation: 
    The first beautiful arrangement is [1,2]:
        - perm[1] = 1 is divisible by i = 1
        - perm[2] = 2 is divisible by i = 2
    The second beautiful arrangement is [2,1]:
        - perm[1] = 2 is divisible by i = 1
        - i = 2 is divisible by perm[2] = 1
*/

class Solution
{
public:
    int res = 0;
    void swap(vector<int> &arr, int a, int b)
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    void permute(vector<int> &arr, int idx)
    {
        if (idx == arr.size())
            res++;
        for (int i = idx; i < arr.size(); i++)
        {
            swap(arr, i, idx);
            if (arr[idx] % (idx + 1) == 0 || (idx + 1) % arr[idx] == 0)
                permute(arr, idx + 1);
            swap(arr, i, idx);
        }
    }
    int countArrangement(int n)
    {
        vector<int> arr(n);
        for (int i = 1; i <= n; i++)
        {
            arr[i - 1] = i;
        }
        permute(arr, 0);
        return res;
    }
};