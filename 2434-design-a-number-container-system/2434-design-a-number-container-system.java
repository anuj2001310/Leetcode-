import java.util.*;

class NumberContainers {
    private Map<Integer, PriorityQueue<Integer>> numToIdx;
    private Map<Integer, Integer> idxToNum;

    public NumberContainers() {
        numToIdx = new HashMap<>();
        idxToNum = new HashMap<>();
    }

    public void change(int index, int number) {
        // Update the idxToNum map
        idxToNum.put(index, number);

        // Update the numToIdx map with a min-heap (PriorityQueue)
        numToIdx.putIfAbsent(number, new PriorityQueue<>());
        numToIdx.get(number).offer(index);
    }

    public int find(int number) {
        if (!numToIdx.containsKey(number)) {
            return -1;
        }
        
        // Get the priority queue associated with the number
        PriorityQueue<Integer> minHeap = numToIdx.get(number);
        
        // Pop from the heap until we find a valid index
        while (!minHeap.isEmpty()) {
            int index = minHeap.peek();
            if (idxToNum.get(index) == number) {
                return index;
            }
            minHeap.poll(); // Remove invalid index
        }
        
        return -1;
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */