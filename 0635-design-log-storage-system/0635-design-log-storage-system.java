class LogSystem {
    class Log {
        String timestamp;
        int id;
        public Log(int id, String timestamp) {
            this.id = id;
            this.timestamp = timestamp;
        }
    }
   
    Stack<Log> st1;
    Stack<Log> st2;

    public LogSystem() {
        st1 = new Stack<>();
        st2 = new Stack<>();
    }
    
    public void put(int id, String timestamp) {
        Log log = new Log(id, timestamp);
        while(st1.size()>0 && st1.peek().timestamp.compareTo(timestamp)>0) {
            st2.push(st1.pop());
        }
        while(st2.size()>0 && st2.peek().timestamp.compareTo(timestamp)<=0) {
            st1.push(st2.pop());
        }
        st1.push(log);
    }
    
    public List<Integer> retrieve(String start, String end, String granularity) {
        String startTimestamp = trim(start, granularity, true);
        String endTimestamp = trim(end, granularity, false);

        while(st2.size()>0 && st2.peek().timestamp.compareTo(endTimestamp)<=0) {
            st1.push(st2.pop());
        }
        while(st1.size()>0 && st1.peek().timestamp.compareTo(endTimestamp)>0) {
            st2.push(st1.pop());
        }

        List<Integer> result = new ArrayList<>();
        while(st1.size()>0 && st1.peek().timestamp.compareTo(startTimestamp)>=0) {
            Log top = st1.peek();
            result.add(top.id);
            st2.push(st1.pop());
        }
        return result;
    }

    private String trim(String timestamp, String granularity, boolean begin) {
        String[] split = timestamp.split(":");
        char[] arr = timestamp.toCharArray();
        switch (granularity) {
            case("Year"): split[1] = begin ? "01" : "12";
            case("Month"): split[2] = begin ?  "01" : "31";
            case("Day"): split[3] = begin ? "00" : "23";
            case("Hour"): split[4] = begin ? "00" : "59";
            case("Minute"): split[5] = begin ? "00" : "59";
            case("Second"): 
        }
        String trimmed = "";
        for(String str: split) trimmed += str + ":";
        return trimmed.substring(0, trimmed.length()-1);
    }
}

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * List<Integer> param_2 = obj.retrieve(start,end,granularity);
 */


 

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * List<Integer> param_2 = obj.retrieve(start,end,granularity);
 */