Find the kth largest element in an unsorted array.Note that it is the kth largest element in the sorted order, not the kth distinct element.

                                                                                                                   Example 1 :

    Input : [ 3, 2, 1, 5, 6, 4 ] and k = 2 Output : 5 Example 2 :

    Input : [ 3, 2, 3, 1, 2, 4, 5, 5, 6 ] and k = 4 Output : 4 Note : You may assume k is always valid,
                                     1 ≤ k ≤ array's length.

    //first solution: using priority_queue as a min_heap
    //in C++, priority queues are a type of container adaptors, specifically designed such that its first element is always the greatest of the elements it contains, according to some strict weak ordering criterion
    //time complexity: O(n*logk)
    //space complexity: O(k)
    //run time: 28ms
    struct compare
{
    bool operator()(int &l, int &r)
    {
        return l > r;
    }
};

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, compare> Q;
        for (auto num : nums)
        {
            Q.push(num);
            if (Q.size() > k)
                Q.pop(); //pop out the smallest element
            //keep k largest elements in the min heap
        }
        return Q.top();
    }
};

//second solution: use a vector to implement min_heap by yourself
//time complexity: O(n*logk + k)
//space complexity: O(k)
//run time: 13ms
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        vector<int> min_heap(k, 0);
        for (int i = 0; i < k; i++)
            min_heap[i] = nums[i];
        intializeHeap(min_heap);
        for (int i = k; i < nums.size(); i++)
        {
            if (min_heap[0] < nums[i])
                min_heap[0] = nums[i];
            rebuildHeap(min_heap, 0);
        }
        return min_heap[0];
    }

    void intializeHeap(vector<int> &min_heap)
    {
        if (min_heap.size() <= 1)
            return;
        int pos = (min_heap.size() - 2) / 2;
        while (pos >= 0)
        {
            rebuildHeap(min_heap, pos);
            pos--;
        }
    }

    void rebuildHeap(vector<int> &min_heap, int i)
    {
        int j = 2 * i + 1;
        int k = 2 * i + 2;
        if (j >= min_heap.size())
            return;
        if (k == min_heap.size())
        {
            if (min_heap[j] < min_heap[i])
                swap(min_heap[j], min_heap[i]);
            return;
        }
        int min_val = i;
        if (min_heap[j] < min_heap[i])
            min_val = j;
        if (min_heap[k] < min_heap[min_val])
            min_val = k;
        if (min_val != i)
        {
            swap(min_heap[min_val], min_heap[i]);
            rebuildHeap(min_heap, min_val);
        }
    }

    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};

//third solution: quick sort partition method
//run time: 72ms
//time complexity: average O(n)
//worst: O(n*n)
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return findKth(nums, 0, nums.size() - 1, k);
    }

    int findKth(vector<int> &nums, int beg, int end, int k)
    {
        int p = partition(nums, beg, end);
        if (end + 1 - p == k)
            return nums[p];
        //else
        if (end + 1 - p > k)
            return findKth(nums, p + 1, end, k);
        else
            return findKth(nums, beg, p - 1, k - (end + 1 - p));
    }

    int partition(vector<int> &nums, int beg, int end)
    {
        if (beg == end)
            return beg;
        if (beg + 1 == end)
        {
            if (nums[beg] > nums[end])
                swap(nums[beg], nums[end]);
            return beg;
        }
        int pivot = nums[beg];
        int i = beg + 1;
        int part = beg;
        while (i <= end)
        {
            if (nums[i] < pivot)
            {
                part++;
                swap(nums[part], nums[i]);
            }
            i++;
        }
        swap(nums[part], nums[beg]);
        return part;
    }
};