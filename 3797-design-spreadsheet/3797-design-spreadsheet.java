class Spreadsheet {
    HashMap<String, Integer> map;

    public Spreadsheet(int rows) {
        map = new HashMap<>();
    }

    public void setCell(String cell, int value) {
        map.put(cell, value);
    }

    public void resetCell(String cell) {
        map.put(cell, 0);
    }

    public int getValue(String formula) {
        String arr[] = formula.substring(1).split("\\+");
        return getCell(arr[0]) + getCell(arr[1]);
    }

    public int getCell(String cell) {
        if (cell.charAt(0) >= '0' && cell.charAt(0) <= '9') {
            return Integer.parseInt(cell);
        } else
            return map.getOrDefault(cell, 0);
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet obj = new Spreadsheet(rows);
 * obj.setCell(cell,value);
 * obj.resetCell(cell);
 * int param_3 = obj.getValue(formula);
 */