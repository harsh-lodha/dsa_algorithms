/**
 * @file leetcode.cpp
 * @author Harsh Lodha
 * @brief solutions to https://bitter-lamp-bf3.notion.site/IT-TRAINING-MODULE-dafb059594564cfbab47304441b3c795
 * @version 0.1
 * @date 2023-01-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Contiguous subarray sum
 * Problem :
 * Find the contiguous subarray within an array, A of length N which has the largest sum.
 * 
 */
int Solution::maxSubArray(const vector<int> &A)
{
    int n = A.size();
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += A[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}

/**
 * @brief Hotel bookings
 * A hotel manager has to process N advance bookings of rooms for the next season.
 *  His hotel has C rooms. Bookings contain an arrival date and a departure date. 
 * He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .
 * 
 */
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K)
{
    set<pair<int, char>> s;
    int rooms = arrive.size();

    for (int i = 0; i < rooms; i++)
    {
        s.insert({arrive[i], 'z'});
        s.insert({depart[i], 'y'});
    }
    int count = 0;
    for (auto ele : s)
    {
        if (ele.second == 'z')
        {
            K--;
        }
        if (ele.second == 'y')
        {
            K++;
        }
        if (K < 0)
            return 0;
    }

    return 1;
}

/**
 * @brief Maximum Unsorted Subarray
 * Given an array A of non-negative integers of size N. Find the minimum sub-array Al, Al+1 ,..., Ar 
 * such that if we sort(in ascending order) that sub-array, then the whole array should get sorted.
 * If A is already sorted, output -1.
 */

vector<int> Solution::subUnsort(vector<int> &A)
{
    vector<int> ans;

    int i = 0;
    int j = A.size() - 1;

    while (i < A.size() - 1 && A[i] <= A[i + 1])
    {
        i++;
    }

    while (j > 0 && A[j] >= A[j - 1])
    {
        j--;
    }

    if (i == A.size() - 1)
    {
        ans.push_back(-1);
        return ans;
    }
    int minele = INT_MAX;
    int maxele = INT_MIN;

    for(int k = i; k <= j; k++)
    {
        minele = min(minele, A[k]);
        maxele = max(maxele, A[k]);
    }

    int l = 0;
    int r = A.size() - 1;

    while(l <= i && A[l] <= minele)
    {
        l++;
    }

    while(r >= j && A[r] >= maxele)
    {
        r--;
    }
    ans.push_back(l);
    ans.push_back(r);
    return ans;
}

/**
 * @brief 
 * Given a set of non-overlapping intervals and a new interval.

Insert the new interval into the set of intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.
Note: Make sure the returned intervals are also sorted.

Input 1:

Intervals = [[1,3],[6,9]]
newInterval = [2,5]

Output 1:

[[1,5],[6,9]]

Input 2:

Intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
newInterval = [4,9]

Output 2:

[1,2],[3,10],[12,16]
 */

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval)
{

    // [3,4] , [5 , 6] , [7 , 8] -> [1, 9] .. [1,2] .. [2,5]

    // condition of overlapping is -> last interval is p , then p.end >= intervals[i].start

    // new formed overlapped interval is -> {min(p.start , intervals[i].start) , max(p.end , intervals[i].end)}

    // newly overlapped interval will be replaced by its old value at res[res.size()-1] , i.e last value of res from
    // which we are comparing \

    vector<Interval> res;

    if (newInterval.start > newInterval.end)
    {
        Interval p = {newInterval.end, newInterval.start};
        newInterval = p;
    }

    res.push_back(newInterval);

    for (int i = 0; i < intervals.size(); i++)
    {
        int sz = res.size();

        Interval last = res[sz - 1];

        if ((last.start <= intervals[i].end && intervals[i].start <= last.start) || (intervals[i].start <= last.end && intervals[i].start >= last.start))
        {
            res[sz - 1] = {min(last.start, intervals[i].start), max(last.end, intervals[i].end)};
        }
        else
        {
            if (intervals[i].end < last.start)
            {
                res[sz - 1] = intervals[i];
                res.push_back(last);
            }

            if (intervals[i].start > last.end)
            {
                res.push_back(intervals[i]);
            }
        }
    }
    return res;
}

/**
 * @brief 
 * Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

    0 <= i < j < nums.length and
    nums[i] > 2 * nums[j].
 * 
 */

public
int reversePairs(int[] nums)
{
    return reversePairsSub(nums, 0, nums.length - 1);
}

private
int reversePairsSub(int[] nums, int l, int r)
{
    if (l >= r)
        return 0;

    int m = l + ((r - l) >> 1);
    int res = reversePairsSub(nums, l, m) + reversePairsSub(nums, m + 1, r);

    int i = l, j = m + 1, k = 0, p = m + 1;
    int[] merge = new int[r - l + 1];

    while (i <= m)
    {
        while (p <= r && nums[i] > 2 L * nums[p])
            p++;
        res += p - (m + 1);

        while (j <= r && nums[i] >= nums[j])
            merge[k++] = nums[j++];
        merge[k++] = nums[i++];
    }

    while (j <= r)
        merge[k++] = nums[j++];

    System.arraycopy(merge, 0, nums, l, merge.length);

    return res;
}

/**
 * @brief 
 * Subarray with sum k
 */

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> s;
    int count = 0;
    int pre_sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        pre_sum += nums[i];
        if (pre_sum == k)
        {
            count++;
        }
        if (s.find(pre_sum - k) != s.end())
        {
            count += s[pre_sum - k];
        }
        s[pre_sum]++;
    }
    return count;
}

/**
 * @brief disjoint set
 * useful when we have queries and we have to connect objects accordingly
 * 
 * Minimum Spanning tree weight: prim's algo = priority queue based on wt,node,parent
 * kruskal's algo = sort edges based on weight and then connect them
 */
class djset
{
    vector<int>parent;
    vector<int>size;
    vector<int>rank;

    djset(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        rank.resize(n+1,0);
        for(int i =0; i<=n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node)
    {
        if(node == parent[node]) return node;
        return parent = findParent(parent[node]);
    }

    void unionbyrank(int u , int v)
    {
        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if(parent_u == parent_v) return; //already united

        if(rank[parent_u] < rank[parent_v]) parent[parent_u] = parent_v;
        else if(rank[parent_u]> rank[parent_v]) parent[parent_v] = parent_u;
        else 
        {
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }

    void unionbysize(int u, int v)
    {
        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if(parent_u == parent_v) return;

        if(size[parent_u] > size[parent_v]){
            parent[parent_v] = parent_u
            size[parent_u] += size[parent_v];
        }
        else{
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
    }
}