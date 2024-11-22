public class Solution {
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        List<IList<int>> result = new List<IList<int>>();
        Array.Sort(candidates);
        BackTrack(candidates, 0, target, result, new List<int>());
        return result;
    }

    private void BackTrack(int[] candidates, int index, int target, List<IList<int>> result, List<int> current) {
        if(target == 0) {
            result.Add(new List<int>(current));
            return;
        }
        
        for(int ix = index; ix < candidates.Length; ++ix){
            if (candidates[ix] > target)
                break;
            current.Add(candidates[ix]);
            BackTrack(candidates, ix, target - candidates[ix], result, current);
            current.RemoveAt(current.Count - 1);
        }
    }
}