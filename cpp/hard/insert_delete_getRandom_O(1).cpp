class RandomizedCollection {
public:

    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        arr.push_back(val);
        m[val].insert(arr.size()-1);
        if(m[val].size() == 1)
            return true;
        else
            return false;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m[val].empty())
            return false;
        int idx = *m[val].begin();
        m[val].erase(idx);
        if(idx != arr.size()-1)
        {
            int v = arr.back();
            arr[idx] = v;
            m[v].erase(arr.size()-1);
            m[v].insert(idx);
        }
        arr.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return arr[rand()%(arr.size())];
    }
    
private:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> m;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
