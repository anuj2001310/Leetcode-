class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> digs(10, 0);
        vector<int> answer;

        for (auto& el : digits)
            ++digs[el];

        for (int i = 100; i < 1000; i += 2) {
            int a = i / 100;
            int b = i / 10 % 10;
            int c = i % 10;
            --digs[a];
            --digs[b];
            --digs[c];
            if ((digs[a] >= 0) && (digs[b] >= 0) && (digs[c] >= 0))
                answer.push_back(i);
    
            ++digs[a];
            ++digs[b];
            ++digs[c];
        }
        return answer;
    }
};