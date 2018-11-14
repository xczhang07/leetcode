class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size()-1-k;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(x - arr[mid] > arr[mid+k] - x)
                left = mid+1;
            else
                right = mid-1;
        }
        return vector<int>(arr.begin()+left, arr.begin()+left+k);
    }
};


/*
http://www.cnblogs.com/grandyang/p/7519466.html

Time Complexity is: O(n)
Space Complexity is: O(1)
*/


Solution 2:
easy to understand 

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size()-1;
        while(high-low >= k)
        {
            if(abs(arr[low]-x) > abs(arr[high]-x))
                ++low;
            else
                --high;
        }
        return vector<int>(arr.begin()+low, arr.begin()+low+k);
    }
    
};
