struct DS {
    int k;
    long long sum;
    set<pair<int, int>> top, rest;
    unordered_map<int, int> freq;

    DS(int k) : k(k), sum(0) {}

    void balance() {
        while (top.size() < k && !rest.empty()) {
            auto it = prev(rest.end());
            auto p = *it;
            sum += 1LL * p.first * p.second;
            top.insert(p);
            rest.erase(it);
        }
        while (top.size() > k) {
            auto it = top.begin();
            auto p = *it;
            sum -= 1LL * p.first * p.second;
            rest.insert(p);
            top.erase(it);
        }
    }

    void removePair(int val) {
        pair<int, int> p = {freq[val], val};
        auto t_it = top.find(p); 
        if (t_it != top.end()) {
            sum -= 1LL * val * freq[val];
            top.erase(t_it);
        } else {
            auto r_it = rest.find(p);
            if (r_it != rest.end()) rest.erase(r_it);
        }
    }

    void addPair(int val) {
        if (freq[val] == 0) return;
        pair<int, int> p = {freq[val], val};
        if (!top.empty()) {
            auto it = top.begin();
            if (p >= *it) {
                top.insert(p);
                sum += 1LL * val * freq[val];
            } else {
                rest.insert(p);
            }
        } else {
            rest.insert(p);
        }
    }

    void add(int val) {
        if (freq[val] > 0) removePair(val);
        freq[val]++;
        addPair(val);
        balance();
    }

    void remove(int val) {
        if (freq[val] > 0) removePair(val);
        freq[val]--;
        addPair(val);
        balance();
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        DS ds(x);
        vector<long long> ans;
        for (int i = 0; i < k; ++i) {
            ds.add(nums[i]);
        }
        ans.push_back(ds.sum);
        for (int i = k; i < n; ++i) {
            ds.add(nums[i]);
            ds.remove(nums[i - k]);
            ans.push_back(ds.sum);
        }
        return ans;
    }
};