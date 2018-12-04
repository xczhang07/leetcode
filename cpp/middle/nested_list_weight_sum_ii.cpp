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
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = 1;
        int sum = 0;
        int maxDepth = 1;
        getHeight(nestedList, depth, maxDepth);
        caculateSum(nestedList, maxDepth, sum);
        return sum;
    }
private:
    void getHeight(vector<NestedInteger>& nestedList, int depth, int& maxDepth)
    {
        if(nestedList.size() == 0)
            return;
        for(auto n: nestedList)
        {
            if(!n.isInteger())
            {
                depth++;
                maxDepth = max(maxDepth, depth);
                getHeight(n.getList(),depth, maxDepth);
                depth--;
            }
        }
        return;
    }
    
    void caculateSum(vector<NestedInteger>& nestedList, int& depth, int& sum)
    {
        if(nestedList.size() == 0)
            return;
        for(auto n: nestedList)
        {
            if(n.isInteger())
                sum += n.getInteger() * depth;
            else
            {
                depth--;
                caculateSum(n.getList(), depth, sum);
                depth++;
            }
        }
        return;
    }
    
};


/*
Conclusion:
an middle level algorithm issue, not diffcult, but need to caculate the deepest degree of nestedList.
Time Complexity: O(n)
Space Complexity: O(1)
*/

version 2

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
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int max_depth = 0;
        int height = 1;
        int sum = 0;
        getHeight(nestedList, max_depth, height);
        getSum(nestedList, max_depth, sum);
        return sum;
    }
    
    void getHeight(vector<NestedInteger>& nestedList, int& max_depth, int depth)
    {
        if(nestedList.size() == 0)
            return;
        max_depth = max(max_depth, depth);
        for(int i = 0; i < nestedList.size(); ++i)
        {
            if(!nestedList[i].isInteger())
                getHeight(nestedList[i].getList(), max_depth, depth+1);
        }
    }
    
    void getSum(vector<NestedInteger>& nestedList, int depth, int& sum)
    {
        if(nestedList.size() == 0)
            return;
        for(auto a : nestedList)
        {
            if(a.isInteger())
                sum += a.getInteger()*depth;
            else
                getSum(a.getList(), depth-1, sum);
        }
    }
    
   
};
