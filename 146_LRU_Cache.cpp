/*
	146. LRU Cache (HARD)
	Design and implement a data structure for Least Recently Used (LRU) cache.
	It should support the following operations: get and put (with O(1)).
	get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
	put(key, value) - Set or insert the value if the key is not already present.
	When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/* 
 * Class to perform 'LRU Cache' implementation
 */
class LRUCache {
private:
    int _capacity;
    list<int> _priority; // Last element indicates Least Recently Used
    unordered_map<int, pair<int, list<int>::iterator>> _cache;

public:
	// Constructor
    LRUCache(int capacity) : _capacity{capacity} {}
    
    // Method to get element from cache
    int get(int key) {
        auto iter = _cache.find(key);

   		// Element not present in Cache 
        if (iter == _cache.end()) return -1;
        
        // Modify existing entry's priority
        auto eraseIter = iter->second.second;
        _priority.erase(eraseIter);
        _priority.push_front(key);
        iter->second.second = _priority.begin();
        
        return iter->second.first;
    }
    
    // Method to put element in cache
    void put(int key, int value) {
        // Insert new entry in Cache
        auto iter = _cache.find(key);
        if (iter == _cache.end()) {
            if (_cache.size() < _capacity) {
                _priority.push_front(key);
                _cache[key] = {value, _priority.begin()};
            } else {
                // Evict least recently used elements from cache
                int k = _priority.back();
                _priority.pop_back();
                _cache.erase(k);
                
                _priority.push_front(key);
                _cache[key] = {value, _priority.begin()};
            }
        } else {
            // Modify existing entry's priority
            auto eraseIter = iter->second.second;
            _priority.erase(eraseIter);
            _priority.push_front(key);
            _cache[key] = {value, _priority.begin()};
        }
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}