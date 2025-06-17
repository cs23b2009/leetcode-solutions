class LFUCache {
public:
    class Node {
    public:
        int key, val, freq;
        Node *prev, *next;
        Node(int k, int v) {
            key = k;
            val = v;
            freq = 1;
            prev = next = nullptr;
        }
    };

    class DLL {
    public:
        Node *head, *tail;
        int size;

        DLL() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addFront(Node *node) {
            Node *temp = head->next;
            head->next = node;
            node->prev = head;
            node->next = temp;
            temp->prev = node;
            size++;
        }

        void removeNode(Node *node) {
            Node *p = node->prev;
            Node *n = node->next;
            p->next = n;
            n->prev = p;
            size--;
        }

        Node* removeLast() {
            if (size == 0) return nullptr;
            Node *node = tail->prev;
            removeNode(node);
            return node;
        }
    };

    int cap, minFreq;
    unordered_map<int, Node*> keyMap;
    unordered_map<int, DLL*> freqMap;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(Node *node) {
        int oldFreq = node->freq;
        freqMap[oldFreq]->removeNode(node);

        // if old frequency list is empty and was minFreq, update it
        if (freqMap[oldFreq]->size == 0) {
            if (minFreq == oldFreq) minFreq++;
            delete freqMap[oldFreq];
            freqMap.erase(oldFreq);
        }

        node->freq++;
        if (freqMap.find(node->freq) == freqMap.end()) {
            freqMap[node->freq] = new DLL();
        }
        freqMap[node->freq]->addFront(node);
    }

    int get(int key) {
        if (keyMap.find(key) == keyMap.end()) return -1;

        Node *node = keyMap[key];
        updateFreq(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        // Update value if key exists
        if (keyMap.find(key) != keyMap.end()) {
            Node *node = keyMap[key];
            node->val = value;
            updateFreq(node);
            return;
        }

        // Eviction if at capacity
        if (keyMap.size() >= cap) {
            Node *nodeToRemove = freqMap[minFreq]->removeLast();
            keyMap.erase(nodeToRemove->key);
        }

        // Insert new node
        Node *newNode = new Node(key, value);
        minFreq = 1;
        if (freqMap.find(minFreq) == freqMap.end()) {
            freqMap[minFreq] = new DLL();
        }
        freqMap[minFreq]->addFront(newNode);
        keyMap[key] = newNode;
    }
};