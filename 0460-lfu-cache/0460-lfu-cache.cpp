class LFUCache {
public:
    LFUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        auto it = key_value_frequency_.find(key);
        if (it == key_value_frequency_.end()) return -1;
        int frequency{it->second.second};
        int res{it->second.first};
        frequency_keys_[frequency].erase(key_iterators_[key]);
        frequency_keys_[frequency + 1].push_front(key);
        if (frequency == minLevel_ &&
            frequency_keys_[frequency].empty()) 
            ++minLevel_;
        key_iterators_[key] = frequency_keys_[frequency + 1].begin();
        it->second.second = frequency + 1;
        return res;
    }
    
    void put(int key, int value) {
        if (capacity_ == 0) return;
        auto it = key_value_frequency_.find(key);
        if (it == key_value_frequency_.end()) {
            if (key_value_frequency_.size() >= capacity_) {
                int delKey = frequency_keys_[minLevel_].back();
                key_value_frequency_.erase(delKey);
                frequency_keys_[minLevel_].erase(key_iterators_[delKey]);
                key_iterators_.erase(delKey);
            }
            key_value_frequency_[key] = make_pair(value, 1);
            frequency_keys_[1].push_front(key);
            key_iterators_[key] = frequency_keys_[1].begin();
            minLevel_ = 1;
        } else {
            it->second.first = value;
            frequency_keys_[it->second.second].erase(key_iterators_[key]);
            key_iterators_.erase(key);
            frequency_keys_[it->second.second + 1].push_front(key);
            key_iterators_[key] = frequency_keys_[it->second.second + 1].begin();
            if (minLevel_ == it->second.second && frequency_keys_[minLevel_].empty()) ++minLevel_;
            it->second.second += 1;
        }
    }
private:
    unordered_map<int, pair<int, int>> key_value_frequency_;
    unordered_map<int, list<int>> frequency_keys_;
    unordered_map<int, list<int>::iterator> key_iterators_;
    int capacity_;
    int minLevel_;
};