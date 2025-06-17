class LRUCache {
public:
    class node{
        public:
            int val, key;
            node *prev, *next;
            node(int k, int v){
                key = k;
                val = v;
                next = prev = nullptr;
            }
    };

    unordered_map <int, node*> mp;
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    
    int limit = 0, cnt;

    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        limit = capacity;
        cnt = 0;
    }
    void add(node* curr){
        node *temp = head->next;
        head->next = curr;
        curr->next = temp;
        temp->prev = curr;
        curr->prev = head;
    }
    void del(){
        node *temp = tail->prev;
        temp = temp->prev;
        tail->prev = temp;
        temp->next = tail;
    }
    void update(node* temp){
        node* p = temp->prev;
        node* n = temp->next;
        p->next = n;
        n->prev = p;
        add(temp);
    }
    
    int get(int key) {
        if(mp.find(key)!= mp.end()){
            node* i = mp[key];
            update(i);
            return i->val;
        }
        return -1;    
    }
    void put(int key, int val) {
        if(mp.find(key)!= mp.end()){
            node* temp = mp[key];
            temp->val = val;
            update(temp);
        }
        else{
            if(cnt < limit){
                node* temp = new node(key, val);
                add(temp);
                mp[key] = temp;
                cnt++;
            }
            else{
                node* temp = new node(key, val);
                add(temp);
                node *x = tail->prev;
                mp.erase(x->key);
                del();
                mp[key] = temp;
            }
        }
    }
};