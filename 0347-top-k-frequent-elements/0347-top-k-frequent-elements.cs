public class Solution {
    public int[] TopKFrequent(int[] nums, int k) {
        List<int> top_k_elements = new();
        PriorityQueue<int, int> frequency_buckets = new(1);
        Dictionary<int, int> frequency_map = new();

        foreach (int num in nums)
            if (frequency_map.ContainsKey(num)) frequency_map[num]++;
            else frequency_map.Add(num, 1);

        foreach (KeyValuePair<int, int> entries in frequency_map)
            frequency_buckets.Enqueue(entries.Key, -entries.Value);

        while (k-- != 0)
            top_k_elements.Add(frequency_buckets.Dequeue());

        return top_k_elements.ToArray();
    }
}