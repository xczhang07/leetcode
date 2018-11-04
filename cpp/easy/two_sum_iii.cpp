class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        m[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
       for(auto e : m)
       {
           int rest = value - e.first;
           if(rest != e.first && m.find(rest) != m.end())
               return true;
           else if(rest == e.first && e.second > 1)
               return true;
       }
        return false;
    }
    
private:
    unordered_map<int, int> m;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
 
