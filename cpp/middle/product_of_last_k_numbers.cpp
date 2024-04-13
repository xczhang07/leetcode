class ProductOfNumbers {
public:
    ProductOfNumbers() {
        nums.push_back(1);
    }
    
    // O(1)
    void add(int num) {
        if(num != 0) {
            int product = nums.back()*num;
            nums.push_back(product);
        } else {
            nums.clear();
            nums.push_back(1);
        }
    }
    
    // O(1)
    int getProduct(int k) {
        if(k >= nums.size()) {
            return 0;
        } else {
            return nums.back()/nums[nums.size()-1-k];
        }
    }

private:
   vector<int> nums;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
