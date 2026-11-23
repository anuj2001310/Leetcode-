class ProductOfNumbers {
private:
    vector<int> nums;

public:
    ProductOfNumbers() { nums.push_back(1); }

    void add(int num) {
        if (num == 0) {
            nums = {1};
        } else
            nums.push_back(nums.back() * num);
    }

    int getProduct(int k) {
        int n = nums.size();
        if (n < k + 1)
            return 0;
        return nums[n - 1] / nums[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */