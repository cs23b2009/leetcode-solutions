class LFUCache {
public:
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyToValFreq; // key → {val, freq}
    unordered_map<int, list<int>> freqToKeys;        // freq → list of keys
    unordered_map<int, list<int>::iterator> keyToIter; // key → its iterator in list

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyToValFreq.find(key) == keyToValFreq.end()) return -1;

        // Update frequency
        int val = keyToValFreq[key].first;
        int freq = keyToValFreq[key].second;
        freqToKeys[freq].erase(keyToIter[key]);

        // Clean up freq list
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq) minFreq++;  // update minFreq
        }

        // Move to next freq
        freqToKeys[freq + 1].push_front(key);
        keyToIter[key] = freqToKeys[freq + 1].begin();
        keyToValFreq[key].second++;

        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        // If key already exists, update value & frequency
        if (keyToValFreq.find(key) != keyToValFreq.end()) {
            keyToValFreq[key].first = value;
            get(key);  // call get() to update freq
            return;
        }

        // Cache is full, need to evict LFU item
        if (keyToValFreq.size() >= capacity) {
            int keyToRemove = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();

            if (freqToKeys[minFreq].empty()) {
                freqToKeys.erase(minFreq);
            }

            keyToValFreq.erase(keyToRemove);
            keyToIter.erase(keyToRemove);
        }

        // Insert new key
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;  // new key has freq = 1
    }
};