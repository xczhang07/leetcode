class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(my_map.find(val) != my_map.end())
            return false;
        nums.emplace_back(val);
        my_map[val] = nums.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(my_map.find(val) == my_map.end())
            return false;
        int last = nums.back();
        my_map[last] = my_map[val];
        nums[my_map[val]] = last;
        nums.pop_back();
        my_map.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int,int> my_map;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
 
 
 Conclusion:
 用一个动态数组和一个哈希表设计这道题，要插入一个元素时候，先在数组中push_back, 之后在哈希表中插入这个元素，键值是元素和这个元素在数组中的index，因为
 每次都是push_back，所以这个元素的index就是nums.size()-1(数组中的最后一个元素)。当要remove这个元素的时候，取出数组中最后一个元素，在数组中和哈希表中
 用最后一个元素和要remove的元素进行替换:
 int last = nums.back();
 hash_map[last] = hash_map[val]; // index 替换 O(1)
 nums[hash_map[val]] = last; // val 替换，将val替换成last O(1)
 nums.pop_back(); //删除数组中最后一个元素，O(1)
 hash_map.erase(val); //删除哈希表中值为val的元素，O(1)
 
 
 Time Complexity: O(1)
