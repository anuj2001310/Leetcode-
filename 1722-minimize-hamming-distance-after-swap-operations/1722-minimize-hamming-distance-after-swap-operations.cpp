struct DSU {
	vector<int> parents;
	vector<int> ranks;
	DSU(int size) {
		parents.resize(size);
		ranks = vector<int>(size, 0);
		iota(parents.begin(), parents.end(), 0);
	}

	int find(int x) {
		return parents[x] == x ? x : parents[x] = find(parents[x]);
	}

	void join(int a, int b) {
		int parent_a = find(a);
		int parent_b = find(b);
		if (parent_a == parent_b) {
			return;
		}
		if (ranks[parent_b] > ranks[parent_a]) {
			swap(parent_a, parent_b);
		}
		parents[parent_b] = parent_a;
		if (ranks[parent_b] == ranks[parent_a]) {
			++ranks[parent_a];
		}
	}
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        DSU dsu(source.size());
        for (const auto& s : allowedSwaps) {
            dsu.join(s[0], s[1]);
        }
        vector<unordered_map<int, int>> cons(source.size());
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] == target[i]) {
                continue;
            }
            ++cons[dsu.find(i)][source[i]];
        }
        int result = 0;
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] == target[i])
                continue;
        
            int my_parent = dsu.find(i);
            if (not cons[my_parent].contains(target[i])) {
                ++result;
            } else {
                if (cons[my_parent][target[i]] == 1) {
                    cons[my_parent].erase(target[i]);
                } else {
                    --cons[my_parent][target[i]];
                }
            }
        }
        return result;
    }
};