class Solution {
  bool doesValidArrayExist(List<int> derived) {
    int n = derived.length;
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans ^= derived[i];
    
    return ans == 0;
  }
}