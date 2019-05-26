Solution#1

Time Complexity is: O(nlogn)
Space Complexity is: O(n)

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size() == 0)
            return 0;
        vector<int> tmp = arr;
        sort(tmp.begin(), tmp.end());
        long long sum1 = 0;
        long long sum2 = 0;
        int partition = 0;
        for(int i = 0; i < arr.size(); ++i)
        {
            sum1 += arr[i];
            sum2 += tmp[i];
            if(sum1 == sum2)
                partition++;
        }
        
        return partition;
    }
};


Solution #2

Time Complexity is: O(n)
Space Complexity is: O(n)

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size() == 0)
            return 0;
        stack<int> st;
        st.push(arr[0]);
        for(int i = 1; i < arr.size(); ++i)
        {
            if(arr[i] >= st.top())
            {
                st.push(arr[i]);
                continue;
            }
            int tmp = st.top();
            while(!st.empty() && arr[i] < st.top())
                st.pop();
            st.push(tmp);
        }
        
        return st.size();
    }
};
