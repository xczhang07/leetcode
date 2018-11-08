/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto n : nestedList)
        {
            dfs(n);
        }
        size = internal.size();
        idx = 0;
    }
    
    void dfs(NestedInteger n)
    {
        if(n.isInteger())
            internal.push_back(n.getInteger());
        else
        {
            vector<NestedInteger> list = n.getList();
            for(int i = 0; i < list.size(); ++i)
                dfs(list[i]);
        }
        return;
        
    }

    int next() {
        return internal[idx++];
    }

    bool hasNext() {
        return idx < size;
    }
private:
    vector<int> internal;
    int size;
    int idx;
    

};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

Solution2, using stack
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size()-1; i >= 0; --i)
            st.push(nestedList[i]);
    }
    
    

    int next() {
        NestedInteger top = st.top();
        st.pop();
        return top.getInteger();
    }

    bool hasNext() {
        while(!st.empty())
        {
            NestedInteger n = st.top();
            if(n.isInteger())
                return true;
            st.pop();
            for(int i = n.getList().size()-1; i >= 0; --i)
            {
                st.push(n.getList()[i]);
            }
        }
        return false;
    }
private:
   stack<NestedInteger> st;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
