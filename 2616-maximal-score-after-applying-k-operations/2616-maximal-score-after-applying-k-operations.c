int cmp(const void* a, const void* b) { 
    return (*(int*)b - *(int*)a);
}

void heapify_down(int* heap, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify_down(heap, size, largest);
    }
}

void heapify_up(int* heap, int i) {
    int parent = (i - 1) / 2;
    if (i > 0 && heap[i] > heap[parent]) {
        int temp = heap[i];
        heap[i] = heap[parent];
        heap[parent] = temp;
        heapify_up(heap, parent);
    }
}

long long maxKelements(int* nums, int numsSize, int k) {
    int* heap = (int*)malloc(numsSize * sizeof(int));
    int heapSize = 0;
    for (int i = 0; i < numsSize; i++) {
        heap[heapSize] = nums[i];
        heapify_up(heap, heapSize);
        heapSize++;
    }

    long long score = 0;
    for (int i = 0; i < k; i++) {
        int maxElement = heap[0];
        score += maxElement;
        int newElement = (int)ceil((double)maxElement / 3.0);
        heap[0] = newElement;
        heapify_down(heap, heapSize, 0);
    }
    
    free(heap);
    return score;
}