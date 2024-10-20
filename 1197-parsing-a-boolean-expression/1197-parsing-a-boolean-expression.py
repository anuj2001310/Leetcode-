class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        stack = []
        for curr in expression:
            if curr == ',' or curr == '(':
                continue
            if curr == 't' or curr == 'f' or curr == '!' or curr == '&' or curr == '|':
                stack.append(curr)
            
            elif curr == ')':
                has_true, has_false = False, False
                while stack[-1] != '!' and stack[-1] != '&' and stack[-1] != '|':
                    top_val = stack[-1]
                    stack.pop()
                    if top_val == 't':
                        has_true = True
                    if top_val == 'f':
                        has_false = True
                
                op = stack[-1]
                stack.pop()
                if op == '!':
                    stack.append('f' if has_true else 't')
                elif op == '&':
                    stack.append('f' if has_false else 't')
                else:
                    stack.append('t' if has_true else 'f')
        
        return stack[-1] == 't' 