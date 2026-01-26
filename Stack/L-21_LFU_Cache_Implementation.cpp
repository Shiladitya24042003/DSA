struct Node {
public:
    int key;
    int val;
    int cnt;
    Node* next;
    Node* prev;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        cnt = 1;
    }
};
struct List {
public:
    Node* head;
    Node* tail;
    int size;
    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node* node) {
        Node* after = head->next;
        node->next = after;
        head->next = node;
        node->prev = head;
        after->prev = node;
        size++;
    }
    void remove(Node* node) {
        Node* before = node->prev;
        Node* after = node->next;
        before->next = after;
        after->prev = before;
        size--;
    }

};
class LFUCache {
private:
    map<int, List*> freqListMap;
    map<int, Node*> keyNode;
    int maxCap;
    int curCap;
    int leastFreq;
    void updateFreqListMap(Node* node) {
        freqListMap[node->cnt]->remove(node);
        if(node->cnt == leastFreq && freqListMap[node->cnt]->size == 0) {
            leastFreq++;
        }
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt+1];
        }
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
    }
public:
    LFUCache(int capacity) {
        maxCap = capacity;
        curCap = 0;
        leastFreq = 0;
    }
    
    int get(int key) {
        if(keyNode.find(key) == keyNode.end()) return -1;
        Node* node = keyNode[key];
        updateFreqListMap(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);
        }
        else {
            if(curCap == maxCap) {
                List* list = freqListMap[leastFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[leastFreq]->remove(list->tail->prev);
                curCap--;
            }
            curCap++;
            leastFreq = 1;
            List* listFreq = new List();
            if(freqListMap.find(leastFreq) != freqListMap.end()) {
                listFreq = freqListMap[leastFreq];
            }
            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[leastFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */