class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        # Handle zero numerator
        if numerator == 0:
            return "0"
        
        res = []
        
        # Check for negative result
        if (numerator < 0) ^ (denominator < 0):
            res.append("-")
        
        # Convert to positive
        numerator, denominator = abs(numerator), abs(denominator)
        
        # Append integer part
        res.append(str(numerator // denominator))
        remainder = numerator % denominator
        
        if remainder == 0:
            return "".join(res)
        
        res.append(".")
        
        # Map to store remainders and their positions in result
        remainder_map = {}
        
        while remainder != 0:
            if remainder in remainder_map:
                # Insert '(' at the position remainder first appeared
                res.insert(remainder_map[remainder], "(")
                res.append(")")
                break
            
            remainder_map[remainder] = len(res)
            
            remainder *= 10
            res.append(str(remainder // denominator))
            remainder %= denominator
        
        return "".join(res)
