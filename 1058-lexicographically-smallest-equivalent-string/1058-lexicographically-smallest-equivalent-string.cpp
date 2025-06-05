#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int find_set(vector<int>& parent, int x) {
        if (parent[x] != x)
            parent[x] = find_set(parent, parent[x]);
    
        return parent[x];
    }

    void union_sets(vector<int>& parent, int x, int y) {
        int rootX = find_set(parent, x);
        int rootY = find_set(parent, y);

        if (rootX != rootY) {
            if (rootX < rootY)
                parent[rootY] = rootX;
            else
                parent[rootX] = rootY;
        }
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for (int i = 0; i < 26; i++)
            parent[i] = i;

        for (int i = 0; i < s1.length(); i++) {
            int x = s1[i] - 'a';
            int y = s2[i] - 'a';
            union_sets(parent, x, y);
        }

        string result = "";
        for (char c : baseStr)
            result += (char)(find_set(parent, c - 'a') + 'a');

        return result;
    }
};