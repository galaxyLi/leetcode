class LRUCache{
public:
        LRUCache(int capacity) {
            max_size = capacity;
            cnt = 0;
        }

        int get(int key) {
            unordered_map<int, list<pair<int, int> >::iterator >::iterator it = cache_map.find(key);
            if (it != cache_map.end()) {
                int val = it->second->second;
                cache_list.erase(it->second);
                cache_map[key] = cache_list.insert(cache_list.end(), make_pair(key, val));
                return val;
            }
            return -1;
        }

        void set(int key, int value) {
            if (get(key) < 0) {
                if (cnt == max_size) {
                    int vtm = cache_list.front().first;
                    cache_list.pop_front();
                    cache_map.erase(vtm);
                } else cnt++;
                cache_list.push_back(make_pair(key, value));
            }
            cache_list.pop_back();
            cache_map[key] = cache_list.insert(cache_list.end(), make_pair(key, value));
        }

    private:
        unordered_map<int, list<pair<int, int> >::iterator > cache_map;
        list<pair<int, int> > cache_list;
        int max_size;
        int cnt;
};
