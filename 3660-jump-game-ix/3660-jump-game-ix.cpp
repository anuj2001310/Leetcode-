class DSU {
public:
    vector<int> par, sz, compMax;

    DSU(int n, vector<int>& nums) {
        par.resize(n);
        sz.resize(n, 1);
        compMax = nums;

        iota(par.begin(), par.end(), 0);
    }

    int findPar(int u) {
        if (par[u] == u)
            return u;
        return par[u] = findPar(par[u]);
    }

    void unionBySize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv)
            return;

        if (sz[pu] < sz[pv])
            swap(pu, pv);

        par[pv] = pu;
        sz[pu] += sz[pv];

        compMax[pu] = max(compMax[pu], compMax[pv]);
    }
};

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixMax(n), suffixMin(n);

        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

        DSU ds(n, nums);

        for (int i = 0; i < n - 1; i++) {
            if (prefixMax[i] > suffixMin[i + 1]) {
                ds.unionBySize(i, i + 1);
            }
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = ds.compMax[ds.findPar(i)];
        }

        return ans;
    }
};