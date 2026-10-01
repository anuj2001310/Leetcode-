class Solution {
public:
    bool isValid(string s) {
        stack<char> store;
        
        for(char ch : s) {
            if(ch == ')') {
                if(store.empty() || store.top() != '(') return false;
                store.pop();
            }
            else if(ch == ']') {
                if(store.empty() || store.top() != '[') return false;
                store.pop();
            }
            else if(ch == '}') {
                if(store.empty() || store.top() != '{') return false;
                store.pop();
            }
            else {
                store.push(ch);
            }
        }
        
        return store.empty();
    }
};