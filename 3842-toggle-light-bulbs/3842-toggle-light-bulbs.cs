public class Solution {
    public IList<int> ToggleLightBulbs(IList<int> bulbs) {
        int n = bulbs.Count;
        var map = new bool[101];
        for (int i = 0; i < n; i++) {
            if (map[bulbs[i]])
                map[bulbs[i]] = false;
            else
                map[bulbs[i]] = true;
        }

        var ans = new List<int>();
        for (int i = 0; i < 101; i++) {
            if (map[i])
                ans.Add(i);
        }
        return ans;
    }
}