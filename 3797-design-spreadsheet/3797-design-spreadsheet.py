class Spreadsheet:

    def __init__(self, rows: int):
        # Use a hashmap
        self.spreadsheet = defaultdict(int)
        
    def setCell(self, cell: str, value: int) -> None:
        self.spreadsheet[cell] = value

    def resetCell(self, cell: str) -> None:
        self.spreadsheet[cell] = 0

    def getValue(self, formula: str) -> int:
        terms = formula[1:].split("+")
        total = 0
        for term in terms:
            if term.isdigit():
                total += int(term)
            else:
                total += self.spreadsheet[term]

        return total
        


# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)