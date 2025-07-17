class FrontMiddleBackQueue {
    Deque<Integer> main, help;
    public FrontMiddleBackQueue() {
        main = new ArrayDeque<>();
        help = new ArrayDeque<>();
    }
    
    public void pushFront(int val) {
        main.offerFirst(val);
        help.offerFirst(val);
    }
    
    public void pushMiddle(int val) {
        int middle = main.size() / 2;
        int size = middle;
        while (size-- > 0) {
            int num = main.pollFirst();
            help.offerLast(num);
        }
        main.offerFirst(val);
        size = middle;
        while (size-- > 0) {
            int num = help.pollLast();
            main.offerFirst(num);
        }

    }
    
    public void pushBack(int val) {
        main.offerLast(val);
        help.offerLast(val);
    }
    
    public int popFront() {
        if (main.isEmpty())
            return -1;
        int num = main.pollFirst();
        help.pollFirst();
        return num;
    }
    
    public int popMiddle() {
        if (main.isEmpty())
            return -1;
        int middle = main.size() / 2;
        int size = middle;
        while (size-- > 0) {
            int num = main.pollLast();
            help.offerLast(num);
        }
        int ans = main.pollLast();
        size = middle;
        while (size-- > 0) {
            int num = help.pollLast();
            main.offerLast(num);
        }
        return ans;
    }
    
    public int popBack() {
        if (main.isEmpty())
            return -1;
        help.pollLast();
        return main.pollLast();
    }
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue obj = new FrontMiddleBackQueue();
 * obj.pushFront(val);
 * obj.pushMiddle(val);
 * obj.pushBack(val);
 * int param_4 = obj.popFront();
 * int param_5 = obj.popMiddle();
 * int param_6 = obj.popBack();
 */