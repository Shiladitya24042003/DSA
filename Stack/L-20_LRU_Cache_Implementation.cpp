class Node {
public:
    int key; int val;
    Node* next; Node* prev;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
    }
};
class LRUCache {
private:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    map<int, Node*> mpp;
    int cap;

    void deleteNodeAtEnd(Node* node) {
        Node* pre = node->prev;
        Node* after = node->next;
        pre->next = after;
        after->prev = pre;
    }
    void insertNodeAtFirst(Node* node) {
        Node* after = head->next;
        node->prev = head;
        head->next = node;
        node->next = after;
        after->prev = node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        Node* node = mpp[key];
        deleteNodeAtEnd(node);
        insertNodeAtFirst(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->val = value;
            deleteNodeAtEnd(node);
            insertNodeAtFirst(node);
        }
        else {
            if(mpp.size() == cap) {
                mpp.erase(tail->prev->key);
                deleteNodeAtEnd(tail->prev);
            }
            Node* newNode = new Node(key, value);
            insertNodeAtFirst(newNode);
            mpp[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */