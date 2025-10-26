class Bank {
    vector<long long> balance;
    int n = 0;

public:
    Bank(vector<long long>& balance) : balance(move(balance)) {
        n = this->balance.size();
    }

    bool isValid(int account) { return account >= 1 && account <= n; }

    bool transfer(int account1, int account2, long long money) {
        if (!isValid(account1) || !isValid(account2))
            return false;
        if (withdraw(account1, money))
            return deposit(account2, money);
        return false;
    }

    bool deposit(int account, long long money) {
        if (!isValid(account))
            return false;
        int index = account - 1;
        balance[index] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!isValid(account))
            return false;
        int index = account - 1;
        if (balance[index] >= money) {
            balance[index] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */