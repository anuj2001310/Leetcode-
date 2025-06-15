class MyStack {
    Deque<Integer> q;
    public MyStack() {
        q = new ArrayDeque<>();
    }
    
    public void push(int x) {
        q.offerLast(x);
    }
    
    public int pop() {
        return q.pollLast();
    }
    
    public int top() {
        return q.peekLast();
    }
    
    public boolean empty() {
        return q.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */