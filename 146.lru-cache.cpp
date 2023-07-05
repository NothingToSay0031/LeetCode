/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
  unordered_map<int, pair<int, list<int>::iterator>> cache;
  list<int> lru;
  int capacity;

 public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    auto it = cache.find(key);
    if (it == cache.end()) {
      return -1;
    } else {
      auto &val = it->second;
      lru.splice(lru.begin(), lru, val.second);
      return val.first;
    }
  }

  void put(int key, int value) {
    auto it = cache.find(key);
    if (it == cache.end()) {
      if (lru.size() == capacity) {
        cache.erase(lru.back());
        lru.pop_back();
      }
      lru.push_front(key);
      cache[key] = {value, lru.begin()};
    } else {
      auto &val = it->second;
      lru.splice(lru.begin(), lru, val.second);
      val.first = value;
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
