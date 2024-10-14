public class Solution {
    public long MaxKelements(int[] nums, int k) {
        PriorityQueue<int, int> maxHeap = new PriorityQueue<int, int>();
        foreach(int num in nums)
            maxHeap.Enqueue(num , -num);

        long score = 0 ;
        for(int i = 0 ; i < k ; i++) {
            int largest = maxHeap.Dequeue();
            score += largest ;
            int reduced = (int)Math.Ceiling((double)largest / 3);
            maxHeap.Enqueue(reduced , -reduced);
        }
        return score;
    }
}