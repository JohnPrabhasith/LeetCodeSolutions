struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    int c;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    map<int, Node*> mp;
    LRUCache(int capacity) {
        c = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    //Remove from Beginning
    void removeNode(Node* node) {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }

    //Insert at End
    void insertToHead(Node* node) {
       node -> next = head -> next;
       head -> next -> prev = node;
       head -> next = node;
       node -> prev = head;
    }

    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            removeNode(node);
            insertToHead(node);
            return node -> val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node -> val = value;
            removeNode(node);
            insertToHead(node);
        }
        else {
            if(mp.size() == c) {
                Node* node = tail->prev;
                removeNode(node);
                mp.erase(node->key);
            }
            Node* node = new Node(key, value);
            insertToHead(node);
            mp[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */