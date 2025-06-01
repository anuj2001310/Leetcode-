class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mp;
    int limit;

    void addNode(Node* newNode) {
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }

    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* ansNode = mp[key];
        int ans = ansNode->val;

        mp.erase(key);
        delNode(ansNode);

        addNode(ansNode);
        mp[key] = ansNode;

        return ans;
    }

    void put(int key, int value) {
        // first check if it doesnt already exist
        if (mp.find(key) != mp.end()) {
            Node* oldNode = mp[key];
            delNode(oldNode);
            mp.erase(key);
        }
        if (mp.size() == limit) {
            // delete LRU data (node before tail)
            Node* oldNode = tail->prev;
            delNode(oldNode);
            mp.erase(oldNode->key);
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
