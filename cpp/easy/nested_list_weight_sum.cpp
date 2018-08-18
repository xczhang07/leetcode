/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int weight_sum = 0;
        int depth = 1;
        dfs(nestedList, weight_sum, depth);
        return weight_sum;
    }
    
    void dfs(vector<NestedInteger>& nestedList, int& weight_sum, int& depth)
    {
        if(nestedList.size() == 0)
            return;
        for(NestedInteger n: nestedList)
        {
            if(n.isInteger()) // if the item is integer, we directly add it into sum
                weight_sum += n.getInteger() * depth;
            else // if the item is a list, using dfs to dig into it
            {
                depth++;
                dfs(n.getList(), weight_sum, depth);
                --depth;
            }
        }
    }
    
};

Conclustion: an easy algorithm issue, dfs can resolve the issue, read the description carefully, know how to use api call.
Time Complexity: O(n) n is the integer number
Space Complexity: O(k) k is the level of the list.
